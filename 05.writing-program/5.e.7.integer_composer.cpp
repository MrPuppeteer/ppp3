import std;
using namespace std;

const array<string, 4> number_names = {"thousand", "hundred", "ten", "one"};

bool check(string input);
vector<int> parse(string input);
int compose(vector<int> digits);

int main()
try {
  string input = "";
  vector<int> digits;
  int composed = 0;

  cout << "Insert 4 or less digits integer to be composed.\n";

  while (cin >> input) {
    if (!check(input)) continue;

    digits = parse(input);
    composed = compose(digits);

    cout << composed << " is ";
    for (size_t i = 0, idx = 4 - digits.size(); i < digits.size(); ++i, ++idx) {
      cout << digits[i] << ' ' << number_names[idx] << (digits[i] == 1 ? " " : "s ");
      if (idx == 2) cout << "and ";
    }
    cout << '\n';
  }

  return 0;
} catch (exception &e) {
  cerr << "Error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "Oops! unknown exception!\n";
  return 2;
}

bool check(string input) {
  if (input.length() > 4) {
    cerr << "input is greater than maximum digits.\n";
    return false;
  }

  for (char c : input)
    if (c < '0' || c > '9') {
      cerr << "input is not an integer number.\n";
      return false;
    }

  return true;
}

vector<int> parse(string input) {
  vector<int> p;

  for (char d : input) {
    if (p.size() != 0 || d != '0')
      p.push_back(d - '0');
  }

  if (p.size() == 0)
    p.push_back(0);

  return p;
}

int compose(vector<int> digits) {
  int res = 0;
  for (int d : digits)
    res = res * 10 + d;
  return res;
}
