import std;
using namespace std;

// simple Date (many people prefer implementation details last)
class Date {
public:
  Date(int y, int m, int d); // constructor: check for valid date and initialize
  void add_day(int n);       // increase the Date by n days
  int month();
  // ...
private:
  int y, m, d; // year, month, day
};

Date::Date(int yy, int mm, int dd) // constructor
    : y{yy}, m{mm}, d{dd}          // note: member initializers
{}

// Date::Date(int yy, int mm, int dd) { // constructor
//   y = yy;
//   m = mm;
//   d = dd;
// }

void Date::add_day(int n) {
  // ...
}

int month() { // oops: we forgot Date::
  return m;   // not the member function, can’t access m
}

// class Date {
// public:
//   Date(int yy, int mm, int dd) : y{yy}, m{mm}, d{dd} {}
//
//   void add_day(int n) {
//     // ...
//   }
//   int month() { return m; }
//
//   // ...
// private:
//   int y, m, d; // year, month, day
// };
