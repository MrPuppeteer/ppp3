import std;
using namespace std;

int get_number();

int main() {
  int a, b;
  char op;
  cout << "Simple Calculator\n"
       << "Enter three arguments: two operands (either written as digits or spelled out) "
       << "then an operator (+,-,*,/):\n";

  while (true) {
    a = get_number();
    if (a == -2) break;
    else if (a == -1) {
      cout << "Please enter a single-digit number "
           << "either digits or spelled out!\n";
      continue;
    }

    b = get_number();
    if (b == -2) break;
    else if (b == -1) {
      cout << "Please enter a single-digit number "
           << "either digits or spelled out!\n";
      continue;
    }

    cin >> op;
    if (op == '|') break;

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

int get_number() {
  const vector<string> nums = {
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine"
  };

  int num;
  string name;

  if (cin >> num) {
    if (num < 0 || num > 9)
      return -1;
    else
      return num;
  } else {
    cin.clear();
    cin >> name;

    if (name == "|")
      return -2;

    for (size_t i = 0; i < nums.size(); ++i)
      if (name == nums[i])
        return int(i);

    return -1;
  }
}
