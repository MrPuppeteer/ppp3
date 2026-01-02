import std;
using namespace std;

enum Month { // note: no “class”
  jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

// void bad_code(Month m) {
//   if (m==17) // huh: 17th month?
//     do_something();
//   if (m==monday)  // huh: compare month to Monday?
//     do_something_else();
// }

int main() {
  Month m1 = feb;        // OK: feb in scope
  Month m2 = Month::feb; // also OK
  Month m3 = 7;          // error: can’t assign an int to a Month
  Month m4 = Month{7};   // OK: explicit conversion

  int x1 = m1; // OK: we can assign a Month to an int
}
