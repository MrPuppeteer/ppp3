import std;
using namespace std;

pair<double, double> solve_quadratic_equation(double a, double b, double c);

int main() {
  double a, b, c;

  cout << "Insert the coefficient a, b, and c of the "
       << "quadratic equation (ax^2 + bx + c = 0)\n";

  cout << "a = ";
  cin >> a;
  
  cout << "b = ";
  cin >> b;
  
  cout << "c = ";
  cin >> c;

  if (a == 0) {
    cout << "if a = 0 then it's not a quadratic equation\n";
    return 1;
  }

  pair<double, double> x = solve_quadratic_equation(a, b, c);

  cout << "The solution using quadratic formula for ";

  if (a != 1)
    cout << a;
  cout << "x^2";

  if (b < 0)
    cout << " - " << abs(b) << "x";
  else if (b > 0)
    cout << " + " << b << "x";

  if (c < 0)
    cout << " - " << abs(c);
  else if (c > 0)
    cout << " + " << c;

  cout << " = 0 is:\n"
       << "x1 = " << x.first << '\n'
       << "x2 = " << x.second << '\n';
}

pair<double, double> solve_quadratic_equation(double a, double b, double c) {
  double x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
  double x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
  
  return {x1, x2};
}
