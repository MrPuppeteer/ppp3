#include <limits>
import std;
using namespace std;

void print_iv(const string& label, const vector<int>& v);

int add_int(int a, int b);

void fibonacci(int x, int y, vector<int>& v, size_t n);

int main() try {
  vector<int> v;
  int max {0};
  int min {0};
  int begin {-200};
  int end {200};
  size_t seq_size {50};

  for (int i = begin; i < end; ++i) {
    fibonacci(i, i+1, v, seq_size);
    int& val = v[v.size() - 1];
    if (val > max) max = val;
    if (val < min) min = val;
    v.clear();
  }

  cout << "Maximum integer approximate: " << max
       << " (real limit " << numeric_limits<int>::max() << ")\n"
       << "Minimum integer approximate: " << min
       << " (real limit " << numeric_limits<int>::min() << ")\n";
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

  try {
    for (size_t i = 2; i < n; ++i) {
      int next = add_int(v[i-2], v[i-1]);
      v.push_back(next);
    }
  } catch (exception&) {
    // ignore overflow errors
  }
}
