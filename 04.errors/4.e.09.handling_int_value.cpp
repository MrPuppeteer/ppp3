import std;
using namespace std;

int sum_of_N(int n, vector<int> values);

int main()
try {
  int n;
  cout << "Please enter the number of values you want to sum: ";
  cin >> n;
  if (n < 1) throw runtime_error("the number of values must be 1 or greater!");
  else if (!cin) throw runtime_error("bad input!");

  int val;
  vector<int> values;
  cout << "Please enter some integers (press '|' to stop): ";
  while (cin >> val) values.push_back(val);
  cin.clear();

  char end = ' ';
  cin >> end;
  if (end != '|') throw runtime_error("bad input!");

  int sum = sum_of_N(n, values);
  
  cout << "The sum of the first " << n << " numbers ( ";
  for (int i = 0; i < n; ++i) cout << values[size_t(i)] << " ";
  cout << ") is " << sum << ".\n";

  return 0;
} catch (exception& e) {
  cout << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "Oops: unknown exception!\n";
  return 2;
}

int sum_of_N(int n, vector<int> values) {
  if (size_t(n) > values.size())
    throw runtime_error("you asked to sum more numbers than given values!");

  const int INT_MAX = numeric_limits<int>::max();
  const int INT_MIN = numeric_limits<int>::min();
  
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int curr = values[size_t(i)];
    if (curr > 0 && sum > INT_MAX - curr)
      throw runtime_error("The result cannot be represented as an int");
    if (curr < 0 && sum < INT_MIN - curr)
      throw runtime_error("The result cannot be represented as an int");
    sum += curr;
  }
  return sum;
}
