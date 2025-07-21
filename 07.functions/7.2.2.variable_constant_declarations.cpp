import std;
using namespace std;

int main() {
  int a;                      // no initializer
  double d = 7;               // initializer using the = syntax
  vector<int> vi(10);         // initializer using the () syntax
  vector<int> vi2 {1,2,3,4};  // initializer using the {} syntax

  const int x = 7;  // initializer using the = syntax
  const int x2 {9}; // initializer using the {} syntax
  // const int y;   // error: no initializer
}

void f(int z) {
  int x;  // unitialized
  // ... no assignment t x here ...
  if (z>x) {
    // ...
  }
  x = 7;  // give x a value
  // ...
}
