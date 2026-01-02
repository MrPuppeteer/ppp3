import std;
using namespace std;

enum class Month {
  jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

int to_int(Month m) {
  return static_cast<int>(m);
}

Month operator++(Month& m) { // prefix increment operator
  m = (m==Month::dec) ? Month::jan : Month{to_int(m)+1};  // "wrap around"
  return m;
}

vector<string> month_tbl = {"Not a month", "January", "February", "March", /*...*/};

ostream& operator<<(ostream& os, Month m) {
  return os << month_tbl[to_int(m)];
}

class Vector {};

int operator+(int,int); // error: you can't overload built-in +
Vector operator+(const Vector&, const Vector&); // OK
Vector operator+=(const Vector&, int);          // OK

int main() {
  Month m = Month::oct;
  ++m;  // m becomes nov
  ++m;  // m becomes dec
  ++m;  // m becomes jan ("wrap around")
}
