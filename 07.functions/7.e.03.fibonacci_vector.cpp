import std;
using namespace std;

void print_iv(const string& label, const vector<int>& v);

int add_int(int a, int b);

void fibonacci(int x, int y, vector<int>& v, size_t n);

int main() try {
  vector<int> v;

  fibonacci(1, 2, v, 10);
  print_iv("Fib(10)", v);
  v.clear();

  fibonacci(1, 2, v, 20);
  print_iv("Fib(20)", v);
  v.clear();

  fibonacci(-2, -2, v, 10);
  print_iv("Test with negatives", v);
  v.clear();

  fibonacci(-5, 4, v, 20);
  print_iv("Test with positive and negative", v);
  // v.clear();

  // fibonacci(1, 2, v, 50);
  // print_iv("Integer overflow test", v);
} catch (exception& e) {
  cerr << e.what() << endl;
  return 1;
} catch (...) {
  cerr << "Unknown exception!" << endl;
  return 2;
}

void print_iv(const string& label, const vector<int>& v) {
  cout << label << ": { ";
  for (int i : v) cout << i << ' ';
  cout << "}\n";
}

// safely add two integers
int add_int(int a, int b) {
  if (((b > 0) && (a > (numeric_limits<int>::max() - b)))
    ||((b < 0) && (a < (numeric_limits<int>::min() - b))))
    throw runtime_error("integer overflows");
  
  return a+b;
}

void fibonacci(int x, int y, vector<int>& v, size_t n) {
  if (v.size() != 0) throw runtime_error("Non empty vector passed as argument.");
  if (n < 2) throw runtime_error("n must be at least 2.");

  v.push_back(x);
  v.push_back(y);

  for (size_t i = 2; i < n; ++i) {
    int next = add_int(v[i-2], v[i-1]);
    v.push_back(next);
  }
}
