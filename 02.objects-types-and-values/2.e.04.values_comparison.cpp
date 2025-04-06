import std;
using namespace std;

int main() {
  int val1 = 0;
  int val2 = 0;
  cout << "Enter two integer values: ";
  cin >> val1 >> val2;

  if (val1 < val2)
    cout << val1 << " is smaller and " << val2 << " is larger\n";
  else if (val2 < val1)
    cout << val2 << " is smaller and " << val1 << " is larger\n";
  else
    cout << val1 << " is equivalent to " << val2 << "\n";

  cout << "The sum of " << val1 << " and " << val2
       << " is " << val1+val2 << '\n'
       << "The difference between " << val1 << " and " << val2
       << " is " << val1-val2 << '\n'
       << "The product of " << val1 << " and " << val2
       << " is " << val1*val2 << '\n';

  if (val2==0) {
    cerr << "Error! Unfortunately you can't divide " << val1 << " by zero\n";
    exit(1);
  }
  else
    cout << "The ratio of " << val1 << " and " << val2
         << " is " << val1/val2 << '\n';
}
