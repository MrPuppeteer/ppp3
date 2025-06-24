import std;
using namespace std;

int main() {
  cout << "Please enter expression (we can handle +, -, *, and /)\n";
  cout << "add an x to end expression (e.g., 1+2*x*3x): ";
  int lval = 0;
  int rval = 0;
  cin>>lval;                  // read left-most operand
  if (!cin)
    throw runtime_error("no first operand");

  for (char op; cin>>op;) {   // read operator and right-hand operand repeatedly
    if (op!='x')
      cin>>rval;
    if (!cin)
      throw runtime_error("no second operand");
    switch (op) {
    case '+':
      lval += rval;           // add: lval = lval + rval
      break;
    case '-':
      lval -= rval;           // subtract: lval = lval - rval
      break;
    case '*':
      lval *= rval;           // multiply: lval = lval * rval
      break;
    case '/':
      lval /= rval;           // divide: lval = lval / rval
      break;
      default:                  // not another operator: print result
      cout << "Result: " << lval << '\n';
      return 0;
    }
  }
  throw runtime_error("bad expression");
}
