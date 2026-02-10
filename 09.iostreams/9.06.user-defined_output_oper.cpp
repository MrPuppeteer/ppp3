import std;
using namespace std;

ostream& operator<<(ostream& os, const Date& d) {
  return os << '(' << d.year()
            << ',' << static_cast<int>(d.month())
            << ',' << d.day() << ')';
}
