import std;
using namespace std;

pair<double, double> quadratic_eq(double a, double b, double c);

int main()
try {
  double a = 0;
  double b = 0;
  double c = 0;

  cout << "Insert coefficient a, b, and c to solve quadratic equations "
       << "ax^2 + bx + c = 0\n";
  cin >> a >> b >> c;
  if (!cin) throw runtime_error("bad input!");

  auto [x1, x2] = quadratic_eq(a, b, c);

  auto sv = [](double val) { return format("{} {}", (val >= 0 ? "+" : "-"), abs(val)); };

  cout << "The roots of quadratic equation " << format("{}x^2 {}x {} = 0 are\n", a, sv(b), sv(c))
       << format("x1 = {} or x2 = {}\n", x1, x2);

  return 0;
} catch (exception& e) {
  cout << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "Oops: unknown exception!\n";
  return 2;
}

pair<double, double> quadratic_eq(double a, double b, double c) {
  if (a == 0) throw runtime_error("the equation is not a quadratic equation (a = 0)");

  double d = b*b - 4*a*c;
  if (d < 0) throw runtime_error("the equation has no real roots");

  double x1, x2;
  x1 = (-b + sqrt(d)) / (2*a);
  x2 = (-b - sqrt(d)) / (2*a);

  return {x1, x2};
}
