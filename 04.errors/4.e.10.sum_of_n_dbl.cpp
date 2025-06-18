import std;
using namespace std;

double sum_of_N(int n, vector<double> values);

vector<double> diffs_of_N(int n, vector<double> values);

int main()
try {
  int n;
  cout << "Please enter the number of values you want to sum: ";
  cin >> n;
  if (n < 1) throw runtime_error("the number of values must be 1 or greater!");
  else if (!cin) throw runtime_error("bad input!");

  double val;
  vector<double> values;
  cout << "Please enter some floating-point numbers (press '|' to stop): ";
  while (cin >> val) values.push_back(val);
  cin.clear();

  char end = ' ';
  cin >> end;
  if (end != '|') throw runtime_error("bad input!");

  double sum = sum_of_N(n, values);
  
  cout << "The sum of the first " << n << " numbers ( ";
  for (int i = 0; i < n; ++i) cout << values[size_t(i)] << " ";
  cout << ") is " << sum << ".\n";

  vector<double> diffs = diffs_of_N(n, values);

  cout << "The differences between adjacent values of the first " << n << " numbers are: ( ";
  for (int i = 0; i < n - 1; ++i) cout << diffs[size_t(i)] << ' ';
  cout << ")\n";

  return 0;
} catch (exception& e) {
  cout << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "Oops: unknown exception!\n";
  return 2;
}

double sum_of_N(int n, vector<double> values) {
  if (size_t(n) > values.size())
    throw runtime_error("you asked to sum more numbers than given values!");

  double sum = 0;
  for (int i = 0; i < n; ++i)
    sum += values[size_t(i)];
  return sum;
}


vector<double> diffs_of_N(int n, vector<double> values) {
  if (size_t(n) > values.size())
    throw runtime_error("you asked to sum more numbers than given values!");
  if (n < 2)
    throw runtime_error("n must be atleast 2 or greater to find the differences!");

  vector<double> diffs;
  for (int i = 0; i < n-1; ++i)
    diffs.push_back(values[size_t(i+1)] - values[size_t(i)]);
  return diffs;
}
