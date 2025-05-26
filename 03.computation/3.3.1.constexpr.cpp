import std;
using namespace std;

int main() {
  int r = 10;
  constexpr double pi = 3.14159;
  // constexpr double pi = 3.14159265359; // more precise

  // pi = 7;          // error: assignment to constant
  double c = 2*pi*r;  // OK: we just read pi; we don't try to change it

  constexpr int max = 100;
  int n;
  cin >> n;

  constexpr int c1 = max+7;   // OK: c1 is 107
  // constexpr int c2 = n+7;  // error: we don't know the value of n
  const int c3 = n;           // OK
  // c3 = 7;                  // error: c3 is a const
}
