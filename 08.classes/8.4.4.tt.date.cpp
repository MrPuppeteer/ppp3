import std;
using namespace std;

class Date {
public:
  Date(int y, int m, int d); // constructor: check for valid date and initialize
  void add_day(int n);       // increase the Date by n days
  int month() { return m; }
  int day() { return d; }
  int year() { return y; }
private:
  int y, m, d; // year, month, day
};

Date::Date(int yy, int mm, int dd) // constructor
    : y{yy}, m{mm}, d{dd}          // note: member initializers
{}

void Date::add_day(int n) {
  // ...
}

ostream& operator<<(ostream& os, Date d) {
  return os << d.year() << '/' << d.month() << '/' << d.day();
}

int main() {
  Date today {2025, 12, 24};
  cout << today << '\n';
}
