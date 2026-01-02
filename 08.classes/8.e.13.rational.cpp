import std;
using namespace std;

class Rational {
public:
  class ZeroDivisionError {};
  Rational(int num, int denom) {
    if (q==0) throw ZeroDivisionError{};
    int cd = gcd(num, denom);
    p = num/cd;
    q = denom/cd;

    if (q < 0) {
      p = -p;
      q = -q;
    }
  }
  Rational(int n) : p{n}, q{1} {}
  Rational() : p{0}, q{1} {}

  double to_double() const { return static_cast<double>(p)/q; }

  int numerator() const { return p; }
  int denominator() const { return q; }

private:
  int p;  // numerator
  int q;  // denominator
};

Rational operator+(const Rational& l, const Rational& r) {
  long long p = static_cast<long long>(l.numerator()) * r.denominator() +
                static_cast<long long>(r.numerator()) * l.denominator();
  long long q = static_cast<long long>(l.denominator()) * r.denominator();

  return Rational{static_cast<int>(p), static_cast<int>(q)};
}

Rational operator-(const Rational& l, const Rational& r) {
  long long p = static_cast<long long>(l.numerator()) * r.denominator() -
                static_cast<long long>(r.numerator()) * l.denominator();
  long long q = static_cast<long long>(l.denominator()) * r.denominator();

  return Rational{static_cast<int>(p), static_cast<int>(q)};
}

Rational operator*(const Rational& l, const Rational& r) {
  long long p = static_cast<long long>(l.numerator()) * r.numerator();
  long long q = static_cast<long long>(l.denominator()) * r.denominator();

  return Rational{static_cast<int>(p), static_cast<int>(q)};
}

Rational operator/(const Rational& l, const Rational& r) {
  if (r.numerator() == 0) throw Rational::ZeroDivisionError{};

  long long p = static_cast<long long>(l.numerator()) * r.denominator();
  long long q = static_cast<long long>(l.denominator()) * r.numerator();

  return Rational{static_cast<int>(p), static_cast<int>(q)};
}

bool operator==(const Rational& l, const Rational& r) {
  return l.numerator() == r.numerator() && l.denominator() == r.denominator();
}

bool operator!=(const Rational& l, const Rational& r) {
  return !(l == r);
}

ostream& operator<<(ostream& os, const Rational& r) {
  os << r.numerator() << '/' << r.denominator();
  return os;
}

istream& operator>>(istream& is, Rational& r) {
  int p, q;
  char c;
  is >> p >> c >> q;
  if (!is) return is;
  if (c != '/') {                // format error
    is.clear(ios_base::failbit); // set the fail bit
    return is;
  }
  r = Rational{p, q};

  return is;
}

int main() try {
  Rational a{25, 12};
  Rational b{-50, -24};
  if (a == b) cout << a << " equals " << b << '\n';
  b = Rational{12};
  if (!(a == b)) cout << a << " does not equal " << b << '\n';

  b = Rational{-100, 3};
  cout << b << " interpreted as floating point is "
       << b.to_double() << '\n';

  a = Rational{3, 4};
  b = Rational{2, 4};
  cout << a << " + " << b << " = " << a+b << '\n';
  cout << a << " - " << b << " = " << a-b << '\n';
  cout << a << " * " << b << " = " << a*b << '\n';
  cout << a << " / " << b << " = " << a/b << '\n';
} catch(Rational::ZeroDivisionError& e) {
  cerr << "Rational::ZeroDivisionError exception: denominator cannot be 0.\n";
  return 1;
} catch(exception& e) {
  cerr << e.what() << '\n';
  return 2;
} catch(...) {
  cerr << "Unknown exception!\n";
  return 3;
}
