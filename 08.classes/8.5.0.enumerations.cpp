import std;
using namespace std;

enum class Month {
  jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

// // tedious
// enum class Month {
//   jan=1, feb=2, mar=3, apr=4, may=5, jun=6, jul=7, aug=8, sep=9, oct=10, nov=11, dec=12
// };

// // count starts with 0
// enum class Month {
//   jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
// };

Month int_to_month(int x);

void f(int m);

int to_int(Month m);

int main() {
  Month m1 = Month::feb;
  Month m2 = feb; // error: feb is not in scope
  Month m3 = 7; // error: can't assign an int to a Month
  Month m4 = Month{7};  // OK: explicit conversion
  Month m5 = {7}; /// OK: explicit conversion

  int x1 = m1;  // error: can't assign a Month to an int
  int x2 = int{m1}; // error: narrowing conversion
  int x3 = to_int(m1);  // convert Month to int;

  Month bad = 9999; // error: cant convert an int to a Month
}

Month int_to_month(int x) { // checked conversion
  if (x<to_int(Month::jan) || to_int(Month::dec)<x) throw runtime_error("bad month");
  return Month{x};
}

void f(int m) {
  Month mm = int_to_month(m);
  // ...
}

int to_int(Month m) {
  return static_cast<int>(m);
}
