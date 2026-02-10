import std;
using namespace std;

const int not_a_reading = -7777;  // less than absolute zero
const int not_a_month = -1;

struct Day {
  vector<double> temp = vector<double>(24,not_a_reading); // note: parentheses
};

struct Month {  // a month of temperature readings
  int month = not_a_month;  // [0:11] January is 0
  vector<Day> day = vector<Day>(32);  // [1:31] one vector of readings per day
};

struct Year { // a year of temperature readings, organized by month
  int year; // positive == A.D.
  vector<Month> month = vector<Month>(12);  // [0:11] January is 0
};

struct Reading {
  int day;
  int hour;
  double temperature;
};

// read a temperature reading from is into r. format:( 3 4 9.7 )
// check format, but don't bother with data validity
istream& operator>>(istream& is, Reading& r) {
  char ch1;
  if (is>>ch1 && ch1!='(') { // could it be a Reading?
    is.unget();
    is.clear(ios::failbit);
    return is;
  }

  char ch2;
  if ((is >> r.day >> r.hour >> r.temperature >> ch2) && ch2!=')')  // messed-up Reading?
    throw runtime_error("bad reading");
  return is;
}

vector<string> month_input_tbl = {
  // "-not a month-",
  "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"
};

// is s the name of a month? if so return its index [1:12] otherwise -1
int month_to_int(string s) {
  for (int i=0; i<12; ++i)
    if (month_input_tbl[i]==s) return i;
  return -1;
}

vector<string> month_print_tbl = {
  // "-not a month-",
  "January", "February", "March", "April", "May", "June", "July",
  "August", "September", "October", "November", "December"
};

// months [1:12]
string int_to_month(int i) {
  if (i<0 || i>=12) throw runtime_error("bad month index");
  return month_print_tbl[i];
}

constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

// a rough test
bool is_valid(const Reading& r) {
  if (r.day<1 || 31<r.day) return false;
  if (r.hour<0 || 23<r.hour) return false;
  if (r.temperature<implausible_min||implausible_max<r.temperature) return false;
  return true;
}

void end_of_loop(istream& ist, char term, const string& message) {
  if (ist.fail()) { // use term as terminator and/or separator
    ist.clear();
    char ch = 0;
    if (ist>>ch && ch==term) return;  // all is fine
    throw runtime_error(message);
  }
}

// read a month from is into m. format: { month feb ... }
istream& operator>>(istream& is, Month& m) {
  char ch = 0;
  if (is >> ch && ch!='{') {
    is.unget();
    is.clear(ios::failbit); // we failed to read a Month
    return is;
  }

  string month_marker;
  string mm;
  is >> month_marker >> mm;
  if (!is || month_marker!="month") throw runtime_error("bad start of month");
  m.month = month_to_int(mm);

  int duplicates = 0;
  int invalids = 0;
  for (Reading r; is >> r; ) {
    if (is_valid(r)) {
      if (m.day[r.day].temp[r.hour] != not_a_reading) ++duplicates;
      m.day[r.day].temp[r.hour] = r.temperature;
    } else ++invalids;
  }
  if (invalids) throw runtime_error("invalid readings in month" + to_string(invalids));
  if (duplicates) throw runtime_error("duplicate readings in month" + to_string(duplicates));
  end_of_loop(is,'}',"bad end of month");
  return is;
}

// read a year from is into y. format: { year 1972 ... }
istream& operator>>(istream& is, Year& y) {
  char ch = 0;
  is >> ch;
  if (ch!='{') {
    is.unget();
    is.clear(ios::failbit);
    return is;
  }

  string year_marker;
  int yy = -1;
  is >> year_marker >> yy;
  if (!is || year_marker!="year") throw runtime_error("bad start of year");
  y.year = yy;

  while (true) {
    Month m;  // get a clean m each time around
    if (!(is >> m)) break;
    // if (m.month == -1) throw runtime_error("invalid month name in year");
    y.month[m.month] = m;
  }

  end_of_loop(is, '}', "bad end of year");
  return is;
}

void print_year(ostream &os, const Year &y) {
  os << "{ year " << y.year << " ";
  for (const Month &m : y.month) {
    if (m.month != not_a_month) {
      os << "{ month " << int_to_month(m.month) << " ";
      for (int d = 1; d < m.day.size(); ++d) {
        bool has_readings = false;
        for (double temp : m.day[d].temp) {
          if (temp != not_a_reading) {
            has_readings = true;
            break;
          }
        }

        if (has_readings) {
          for (int h = 0; h < m.day[d].temp.size(); ++h)
            if (m.day[d].temp[h] != not_a_reading)
              os << "(" << d << " " << h << " " << m.day[d].temp[h] << ") ";
        }
      }
      os << "} ";
    }
  }
  os << "}\n";
}

int main() {
  // open an input file:
  cout << "Please enter input file name\n";
  string iname;
  cin >> iname;
  ifstream ifs {iname};
  if (!ifs) throw runtime_error("can't open input file" + iname);

  ifs.exceptions(ifs.exceptions()|ios::badbit); // throw for bad()

  // open and output file:
  cout << "Please enter output file name\n";
  string oname;
  cin >> oname;
  ofstream ofs {oname};
  if (!ofs) throw runtime_error("can't open output file" + oname);

  // read an arbitrary number of years:
  vector<Year> ys;
  while (true) {
    Year y; // get a freshly initialized Year each time around
    if (!(ifs>>y)) break;
    ys.push_back(y);
  }
  cout << "read " << ys.size() << " years of readings\n";

  for (Year& y : ys) print_year(ofs,y);
}
