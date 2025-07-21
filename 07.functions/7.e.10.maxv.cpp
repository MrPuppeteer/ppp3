import std;
using namespace std;

void print_dv(const string& label, const vector<double>& v);

// returns the largest element of a vector
double maxv(const vector<double>& v);

int main() try {
  vector<double> test {-5, 0, 6.7, -1000, 10.1e5, 10e5};

  print_dv("test", test);
  cout << "Largest element from test: " << maxv(test) << '\n';
} catch (exception& e) {
  cerr << e.what() << endl;
  return 1;
} catch (...) {
  cerr << "Unknown exception!" << endl;
  return 2;
}

void print_dv(const string& label, const vector<double>& v) {
  cout << label << ": { ";
  for (double i : v) cout << i << ' ';
  cout << "}\n";
}

double maxv(const vector<double>& v) {
  double max {v[0]};
  for (double d : v)
    if (d > max) max = d;
  return max;
}
