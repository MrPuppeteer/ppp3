import std;
using namespace std;

// void f() {
//   Date today;
//   // ...
//   cout << today << '\n';  // use today
//   // ...
//   init_day(today,2008,3,30);
//   // ...
//   Date tomorrow;
//   tomorrow.y = today.y;
//   tomorrow.m = today.m;
//   tomorrow.d = today.d+1;
//
//   cout << tomorrow << '\n';
// }

// simple Date
// guarantee initialization with constructor and provide some notational convenience
struct Date {
  int y, m, d;  // year, month, day
  Date(int y, int m, int d);  // check for valid date and initialize
  void add_day(int n);  // increase the Date by n days
};

int main() {
  Date birthday;  // error: birthday not initialized
  Date today {12,24,2027};  // oops! run-time error
  Date last {2005,12,31}; // OK (colloquial style)
  Date next = {2014,2,14};  // also OK (slightly verbose)
  Date Beethoven = Date{1770,12,16};  // also OK (vervose style)

  last.add_day(1);
  add_day(2); // error: what date?

  Date last(2000,12,31);  // OK (old style)

  int x {7};  // OK (initializer list style)
  x = int{9};
}
