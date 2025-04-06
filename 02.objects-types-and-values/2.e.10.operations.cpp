import std;
using namespace std;

int main() {
  cout << "Enter an operation (+, -, *, /, plus, minus, mul, div) "
       << "followed by two floating-point values separated by a space: ";
  string op = "";
  double x = 0;
  double y = 0;
  cin >> op >> x >> y;

  double res = 0;
  if (op == "+" || op == "plus")
    res = x+y;
  else if (op == "-" || op == "minus")
    res = x-y;
  else if (op == "*" || op == "mul")
    res = x*y;
  else if (op == "/" || op == "div") {
    if (y==0) {
      cout << "Unfortunately you can't divide " << x << " by zero\n";
      exit(1);
    }
    res = x/y;
  }
  else {
    cout << "Unknown operation\n";
  }
  
  cout << x << op << y << " == " << res << '\n';
}
