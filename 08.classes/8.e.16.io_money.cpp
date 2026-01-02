import std;
using namespace std;

static long int round_m(double amount) { return static_cast<long int>(floor(amount + 0.5)); }

enum class Currency {
  USD, DKK, GBP, EUR
};

ostream& operator<<(ostream& os, const Currency& curr) {
  switch (curr) {
    case Currency::USD: os << "USD"; break;
    case Currency::DKK: os << "DKK"; break;
    case Currency::GBP: os << "GBP"; break;
    case Currency::EUR: os << "EUR"; break;
  }
  return os;
}

static map<Currency, double> rates = {
  {Currency::USD, 1.0},
  {Currency::DKK, 6.35},
  {Currency::GBP, 0.74},
  {Currency::EUR, 0.85}
};

static const map<string, Currency> string_to_curr = {
  {"USD", Currency::USD},
  {"DKK", Currency::DKK},
  {"GBP", Currency::GBP},
  {"EUR", Currency::EUR}
};

class Money {
public:
  class ZeroDivisionError {};
  class InexactValueError {};

  Money(long int units, long int cents, Currency currency) : curr{currency} {
    if (units < 0) amount = units * 100 - cents;
    else amount = units * 100 + cents;
  }
  explicit Money(long int cents, Currency currency) : amount{cents}, curr{currency} {}
  explicit Money(double units, Currency currency) : curr{currency} {
    double val = units * 100.0;
    if (abs(val - round(val)) > 1e-9) {
      throw InexactValueError{};
    }
    amount = static_cast<long int>(round(val));
  }
  Money() {}

  long int total() const { return amount; }
  Currency currency() const { return curr; }

  long int units() const { return amount / 100; }
  long int cents() const { return abs(amount % 100); }

  void convert_to(const Currency& to_curr) {
    if (curr == to_curr) return;
    double target_amount = (static_cast<double>(amount) * rates[to_curr]) / rates[curr];
    amount = round_m(target_amount);
    curr = to_curr;
  }

private:
  long int amount = 0; // monetary amount in cents
  Currency curr = Currency::USD;
};

Money operator+(const Money& l, const Money& r) {
  if (l.currency() == r.currency()) return Money{l.total() + r.total(), l.currency()};
  Money temp{r};
  temp.convert_to(l.currency());
  return Money{l.total() + temp.total(), l.currency()};
}

Money operator-(const Money& l, const Money& r) {
  if (l.currency() == r.currency()) return Money{l.total() - r.total(), l.currency()};
  Money temp{r};
  temp.convert_to(l.currency());
  return Money{l.total() - temp.total(), l.currency()};
}

Money operator*(const Money& l, double factor) {
  return Money{round_m(static_cast<double>(l.total()) * factor), l.currency()};
}

Money operator*(double factor, const Money& r) { return r*factor; }

Money operator/(const Money& l, double divisor) {
  if(divisor == 0) throw Money::ZeroDivisionError{};
  return Money{round_m(static_cast<double>(l.total())/divisor), l.currency()};
}

bool operator==(const Money& l, const Money& r) {
  if (l.currency() == r.currency()) return l.total() == r.total();
  Money temp{r};
  temp.convert_to(l.currency());
  return l.total() == temp.total();
}
bool operator!=(const Money& l, const Money& r) { return !(l == r); }

ostream& operator<<(ostream& os, const Money& money) {
  if (money.total() < 0 && money.units() == 0) os << "-";
  os << money.currency() << money.units() << '.' << setw(2) << setfill('0') << money.cents();
  return os;
}

istream& operator>>(istream& is, Money& money) {
  string unit_str;
  double val;

  char c1, c2, c3;
  if (!(is >> c1 >> c2 >> c3))
    return is;
  unit_str += c1;
  unit_str += c2;
  unit_str += c3;

  auto it = string_to_curr.find(unit_str);
  if (it == string_to_curr.end()) {
    is.setstate(ios::failbit);
    return is;
  }

  if (!(is >> val)) return is;

  try {
    money = Money{val, it->second};
  } catch (const Money::InexactValueError &) {
    is.setstate(ios::failbit);
  }

  return is;
}

int main() try {
  Money a;
  Money b;

  cin >> a >> b;

  cout << a << " + " << b << " = " << a + b << '\n'
       << a << " - " << b << " = " << a - b << '\n'
       << a << " * " << 2 << " = " << a * 2 << '\n'
       << a << " / " << 2 << " = " << a / 2 << '\n';

  // cout << a / 0;
  // Money c{1.234, Currency::DKK};
} catch(Money::ZeroDivisionError& e) {
  cerr << "Money class: division by zero\n";
  return 1;
} catch(Money::InexactValueError& e) {
  cerr << "Money class: double value has more than 2 decimal places\n";
  return 2;
} catch(exception& e) {
  cerr << e.what() << '\n';
  return 3;
} catch(...) {
  cerr << "Unknown exception!!\n";
  return 4;
}
