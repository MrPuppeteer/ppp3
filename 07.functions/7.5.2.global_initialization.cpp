import std;
using namespace std;

// // file f1.cpp
// int x1 = 1;
// int y1 = x1+2;  // y1 becomes 3

// // file f2.cpp
// extern int y1;
// int y2 = y1+2;  // y2 becomes 2 or 5

// const Date today = get_date_from_clock(); // suspicious definition

// const Date today() {
//   return get_date_from_clock(); // return today's date
// }

// const Date& today() {
//   static const Date today = get_date_from_clock();  // initialize today the first time we get here
//   return today;
// }
