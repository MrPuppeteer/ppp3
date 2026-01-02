import std;
using namespace std;

static long int round_m(double amount) { return static_cast<long int>(floor(amount + 0.5)); }

class Money {
public:
  class ZeroDivisionError {};
  Money(long int units, long int cents) {
    if (units < 0) amount = units * 100 - cents;
    else amount = units * 100 + cents;
  }
  explicit Money(long int cents) : amount{cents} {}
  explicit Money(double units) : amount{round_m(units * 100)} {}
  Money() : amount{0} {}

  long int total() const { return amount; }
  long int units() const { return amount / 100; }
  long int cents() const { return abs(amount % 100); }

private:
  long int amount; // monetary amount in cents
};

Money operator+(const Money& l, const Money& r) { return Money{l.total() + r.total()}; }

Money operator-(const Money& l, const Money& r) { return Money{l.total() - r.total()}; }

Money operator*(const Money& l, double factor) {
  return Money{round_m(static_cast<double>(l.total()) * factor)};
}

Money operator*(double factor, const Money& r) { return r*factor; }

Money operator/(const Money& l, double divisor) {
  if(divisor == 0) throw Money::ZeroDivisionError{};
  return Money{round_m(static_cast<double>(l.total())/divisor)};
}

bool operator==(const Money& l, const Money& r) { return l.total() == r.total(); }
bool operator!=(const Money& l, const Money& r) { return !(l == r); }

ostream& operator<<(ostream& os, const Money& money) {
  if (money.total() < 0 && money.units() == 0) os << "-";
  os << "$" << money.units() << '.' << setw(2) << setfill('0') << money.cents();
  return os;
}

int main() try {
  Money a{123, 45};
  Money b{long(1000)};

  cout << a << " + " << b << " = " << a + b << '\n'
       << a << " - " << b << " = " << a - b << '\n'
       << a << " * " << 2 << " = " << a * 2 << '\n'
       << a << " / " << 2 << " = " << a / 2 << '\n';

  cout << a / 0;
} catch(Money::ZeroDivisionError& e) {
  cerr << "Money class: division by zero\n";
  return 1;
} catch(exception& e) {
  cerr << e.what() << '\n';
  return 2;
} catch(...) {
  cerr << "Unknown exception!!\n";
  return 3;
}
