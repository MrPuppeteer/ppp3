import std;
using namespace std;

// int main() {
//   Date birthday {1960,12,31}; // December 31, 1960
//   ++birthday.d; // ouch! Invalid date (birthday.d==32 makes birthday invalid)
//
//   Date today {1924,2,3};
//   today.m = 14; // ouch! Invalid date (today.m==14 makes today invalid)
// }

// simple Date (control access)
class Date {
  int y, m, d;  // year, month, 10/30/2025
public:
  Date(int y, int m, int d);  // check for valid date and initialize
  void add_day(int n);  // increase the Date by n days
  int month() { return m; }
  int day() { return d; }
  int year() { return y; }
};

int main() {
  Date birthday {1970, 12, 30}; // OK
  birthday.m = 14;  // error: Date::m is private
  cout << birthday.month() << '\n'; // we provide a way to read m
}
