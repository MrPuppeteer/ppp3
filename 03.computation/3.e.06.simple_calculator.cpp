import std;
using namespace std;

int main() {
  double a, b;
  char op;
  cout << "Simple Calculator\n"
       << "Enter three arguments: two operands then an operator (+,-,*,/):\n";

  while (cin >> a >> b >> op) {
    switch (op) {
      case '+':
        cout << "The sum of " << a << " and " << b << " is "
             << a+b << '\n';
        break;
      case '-':
        cout << "The difference between " << a << " and " << b << " is "
             << a-b << '\n';
        break;
      case '*':
        cout << "The product of " << a << " and " << b << " is "
             << a*b << '\n';
        break;
      case '/':
        if (b == 0)
          cout << "Error! Cannot divide by zero.\n";
        else
        cout << "The quotient of " << a << " and " << b << " is "
             << a/b << '\n';
        break;
      default:
        cout << "Unrecognized operator!\n";
        break;
    }
  }
}
