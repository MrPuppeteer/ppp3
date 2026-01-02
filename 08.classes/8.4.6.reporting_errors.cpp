import std;
using namespace std;

// simple Date (prevent invalid dates)
class Date {
public:
  class Invalid {};          // to be used as exception
  Date(int y, int m, int d); // check for valid date and initialize
  void add_day(int n);
  int month() { return m; }
  int day() { return d; }
  int year() { return y; }
  bool is_valid(); // return true if date is valid
private:
  int y, m, d; // year, month, day
};

Date::Date(int yy, int mm, int dd)
    : y{yy}, m{mm}, d{dd} { // initialize data members
  if (!is_valid())          // check for validity
    throw Invalid{};
}

void Date::add_day(int n) {
  // ...
}

bool Date::is_valid() {   // return true if date is valid
  return 0 < m && m < 13; // very incomplete check
}

ostream &operator<<(ostream &os, Date d) {
  return os << d.year() << '/' << d.month() << '/' << d.day();
}

void f(int x, int y) try {
  Date dxy{2024, x, y};
  cout << dxy << '\n';
  dxy.add_day(2);
} catch (Date::Invalid) {
  throw runtime_error("f(): invalid date");
}
