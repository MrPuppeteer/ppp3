import std;
using namespace std;

struct Reading {      // a temperature reading
  int hour;           // hour after midnight [0:23]
  double temperature; // in Fahrenheit
};

int main() {
  cout << "Please enter input file name: ";
  string iname;
  cin >> iname;
  ifstream ist{iname};  // ist reads from the file named iname
  if (!ist) throw runtime_error("can't open input file " + iname);

  string oname;
  cout << "Please enter name of output file: ";
  cin >> oname;
  ofstream ost{oname};  // ost writes to a file named oname
  if (!ost) throw runtime_error("can't open output file " + oname);

  vector<Reading> temps;  // store the readings here
  int hour = -1;
  double temperature = -700;
  while (ist >> hour >> temperature) {
    if (hour < 0 || 23 < hour) throw runtime_error("hour out of range");
    temps.push_back(Reading{hour,temperature});
  }

  for (Reading x : temps) ost << '(' << x.hour << ',' << x.temperature << ")\n";
}
