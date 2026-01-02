import std;
using namespace std;

// Date d1 {4,5,2005}; // oops: year 4, day 2005
// Date d2 {2005,4,5}; // April 5 or May 4?

enum class Month {
  jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

// // simple Date (use Month type)
// class Date {
// public:
//   Date(int y, Month m, int d);  // check for valid date initialize
//   // ...
// private:
//   int y;  // year
//   Month m;
//   int d;  // day
// };
//
// int main() {
//   Date dx1{1998, 4, 3};           // error: 2nd argument not a Month
//   Date dx2{1998, 4, Month::mar};  // error: 2nd argument not a Month
//   Date dx3{4, Month::mar, 1998};  // oops: run-time error: day 1998
//   Date dx4{Month::mar, 4, 1998};  // error: 2nd argument not a Month
//   Date dx5{1998, Month::mar, 30}; // OK
// }

struct Year {
  int y;
};

class Date {
public:
  Date(Year y, Month m, int d); // check for valid date and initialize
  // ...
private:
  Year y;
  Month m;
  int d;  // day
};

int main() {
  Date dx1{Year{1998}, 4, 3};           // error: 2nd argument not a Month
  Date dx2{Year{1998}, 4, Month::mar};  // error: 2nd argument not a Month
  Date dx3{4, Month::mar, Year{1998}};  // error: 1st argument not a Year
  Date dx4{Month::mar, 4, Year{1998}};  // error: 2nd argument not a Month
  Date dx5{Year{1998}, Month::mar, 30}; // OK
  Date dx6{Year{4}, Month::mar, 1998};  // run-time error: Year ::Invalid
}
