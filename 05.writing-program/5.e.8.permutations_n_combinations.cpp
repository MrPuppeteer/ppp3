import std;
using namespace std;

int get_n(string msg);
int permute(int a, int b);
int combine(int a, int b);

int main()
try {
  cout << "Permutation and Combination Calculator\n";

  while (true) {
    int setc = get_n("Insert set cardinality (n): ");
    int subc = get_n("Insert subset cardinality (n): ");

    cout << "Choose the type of calculation to perform:\n"
         << "(p)ermutation, (c)ombination, or (b)oth\n";
    char opt;
    cin >> opt;

    switch (opt) {
    case 'p': case 'P':
      cout << "P(" << setc << ", " << subc << ") = "
           << permute(setc, subc) << '\n';
      break;
    case 'c': case 'C':
      cout << "C(" << setc << ", " << subc << ") = "
           << combine(setc, subc) << '\n';
      break;
    case 'b': case 'B':
      cout << "P(" << setc << ", " << subc << ") = "
           << permute(setc, subc) << '\n';
      cout << "C(" << setc << ", " << subc << ") = "
           << combine(setc, subc) << '\n';
      break;
    default:
      throw runtime_error("bad option");
    }

    cout << "Do you want to perform another calculation? (y/n): ";
    cin >> opt;
    if (opt == 'n') break;
    else if (opt != 'y')
      throw runtime_error("bad option");
  }

  return 0;
} catch (exception &e) {
  cerr << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "Oops! unknown exception.\n";
  return 2;
}

int get_n(string msg) {
  int n;
  cout << msg;

  cin >> n;
  
  if (!cin)
    throw runtime_error("bad input");
  
  if (n < 0)
    throw runtime_error("input is not a natural number");
  
  return n;
}

int permute(int a, int b) {
  if (a < 0 || b < 0 || a < b)
    throw runtime_error("a and b parameters precondition violated");

  if (a == 0 || b == 0) return 1;

  int res = 1;

  for (int i = a - b + 1; i <= a; ++i) {
    if (res > (numeric_limits<int>::max() / i))
      throw runtime_error("integer overflows");
    res *= i;
  }

  return res;
}

int combine(int a, int b) {
  if (a < 0 || b < 0 || a < b)
    throw runtime_error("a and b precondition violated");

  if (a == 0 || b == 0) return 1;

  int res = 1;

  for (int i = 1; i <= b; ++i) {
    if (res > (numeric_limits<int>::max() / (a + 1 - i)))
      throw runtime_error("integer overflows");
    res = (res * (a + 1 - i)) / i;
  }

  return res;
}
