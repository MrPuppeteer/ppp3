import std;
using namespace std;

class Date {
public:
  // ...
  int month() { return m; }
  // ...
private:
  int y, m, d; // year, month, day
};

void f(Date d1, Date d2) {
  cout << d1.month() << ' ' << d2.month() << '\n';
}
