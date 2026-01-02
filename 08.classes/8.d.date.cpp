import std;
using namespace std;

enum class Month {
  jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month operator++(Month &m) {
  m = (m == Month::dec) ? Month::jan : Month{static_cast<int>(m) + 1};
  return m;
}

vector<string> month_tbl = {"Not a month",
                            "January",   "February", "March",    "April",
                            "May",       "June",     "July",     "August",
                            "September", "October",  "November", "December"};

ostream &operator<<(ostream &os, Month m) {
  return os << month_tbl[static_cast<size_t>(m)];
}

struct Year {
  int y;
};

ostream &operator<<(ostream &os, Year yy) {
  return os << yy.y;
}

class Date {
public:
  class Invalid {};
  Date();
  Date(Year y, Month m, int d);

  int day() const { return d; }
  Month month() const { return m; }
  Year year() const { return y; }

  void add_day(int n);
  void add_month(int n);
  void add_year(int n);

  bool is_valid();

private:
  Year y{2001};
  Month m = Month::jan;
  int d = 1;
};

Date::Date(Year yy, Month mm, int dd) : y{yy}, m{mm}, d{dd} {
  if (!is_valid()) throw Invalid{};
}

void Date::add_day(int n) {
  d += n % 31;

  int nm = (n / 31) % 12;
  int ny = n / (31 * 12);

  // check data overflows
  if (d > 31) {
    ++nm;
    d -= 31;
  } else if (d < 1) {
    --nm;
    d += 31;
  }

  int temp_m = static_cast<int>(m) + nm;
  if (temp_m > 12) {
    ++ny;
    temp_m -= 12;
  } else if (temp_m < 1) {
    --ny;
    temp_m += 12;
  }

  m = Month{temp_m};
  y.y += ny;
}

void Date::add_month(int n) {
  int nm = n % 12;
  int ny = n / 12;

  int temp_m = static_cast<int>(m) + nm;
  if (temp_m > 12) {
    ++ny;
    temp_m -= 12;
  } else if (temp_m < 1) {
    --ny;
    temp_m += 12;
  }
  m = Month{temp_m};
  y.y += ny;
}

void Date::add_year(int n)
{
  y.y += n;
}

bool Date::is_valid() {
  if (d < 1 || d > 31) return false;
  if (static_cast<int>(m) < 1 || static_cast<int>(m) > 12) return false;
  return true;
}

ostream &operator<<(ostream &os, Date d) {
  // return os << d.year() << '/' << d.month() << '/' << d.day();
  return os << d.month() << ' ' << d.day() << ", " << d.year();
}

int main() try {
  Date today{Year{2020}, Month::feb, 2};

  Date tomorrow{today};
  tomorrow.add_day(1);

  cout << "Today: " << today << '\n';
  cout << "Tomorrow: " << tomorrow << '\n';

  // Test
  Date test{Year{2010}, Month::dec, 31};
  test.add_day(6); // 2011 Jan 6
  cout << "6 Jan 2011? " << test << '\n';
  test.add_day(-6); // 2010 Dec 31
  cout << "31 Dec 2010? " << test << '\n';
  test.add_day(-31);
  cout << "31 Nov 2010? " << test << '\n';
  test.add_day(-62);
  cout << "31 Sep 2010? " << test << '\n';

  test = Date{Year{2010}, Month::feb, 5};
  test.add_day(-7); // 2010 Jan 29
  cout << "29 Jan 2010? " << test << '\n';
  test.add_day(7); // 2010 Feb 5
  cout << "5 Feb 2010? " << test << '\n';
  test.add_day(31 * 12 * 10);
  cout << "5 Feb 2020? " << test << '\n';
  test.add_day(-31 * 12 * 10);
  cout << "5 Feb 2010? " << test << '\n';
  test.add_month(25);
  cout << "5 Mar 2012? " << test << '\n';
  test.add_month(-25);
  test.add_year(8);
  cout << "5 Feb 2018? " << test << '\n';
  test.add_year(-8);
  cout << "5 Feb 2010? " << test << '\n';

  // Invalid date
  Date err{Year{2004}, Month::dec, -5};

  return 0;
} catch (exception &e) {
  cerr << e.what() << '\n';
  return 1;
} catch (Date::Invalid) {
  cerr << "Invalid date!\n";
  return 2;
} catch (...) {
  cerr << "Unknown exception!\n";
  return 3;
}
