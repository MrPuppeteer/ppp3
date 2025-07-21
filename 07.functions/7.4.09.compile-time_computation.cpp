import std;
using namespace std;

// constexpr double xscale = 10; // scaling factors
// constexpr double yscale = 0.8;
//
// constexpr Point scale(Point p) { return {xscale*p.x,yscale*p.y}; }
//
// void user(int x, int y) {
//   Point p1 {x,y}; // at compile time, we don't know the value of p1
//   constexpr Point p2 {10,10};
//
//   Point p3 = scale(p1); // OK: p3 == {100,8}; run-time evaluation is fine
//   constexpr Point p4 = scale(p2); // OK: p4 == {100,8}; scale(p2) is a constant
//   constexpr Point p5 = scale(p1); // error: scale (p1) is not a constant expression
//   // ...
// }

constexpr int sum(const vector<int>& v) {
  int s = 0;
  for (int x : v) s += x;
  return s;
}

// consteval double half(double d) { return d/2; }
//
// double x1 = half(7);  // OK: 7 is a constant
// double x2 = half(x1); // error: x1 is a non-const variable
