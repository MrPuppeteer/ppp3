import std;
using namespace std;

void print_sv(const string& label, const vector<string>& v);

// returns a new vector in reverse
vector<string> reverse_retv(const vector<string>& v);

// reverse vector
void reverse_swapv(vector<string>& v);

int main() try {
  vector<string> odd_v = {"one", "three", "five", "seven", "nine"};
  print_sv("v", odd_v);
  vector<string> rev_odd_v = {reverse_retv(odd_v)};
  print_sv("Reverse v by const-ref", rev_odd_v);
  reverse_swapv(odd_v);
  print_sv("Reverse v by ref", odd_v);

  vector<string> even_v = {"two", "four", "six", "eight"};
  print_sv("v", even_v);
  vector<string> rev_even_v = {reverse_retv(even_v)};
  print_sv("Reverse v by const-ref", rev_even_v);
  reverse_swapv(even_v);
  print_sv("Reverse v by ref", even_v);
} catch (exception& e) {
  cerr << e.what() << endl;
  return 1;
} catch (...) {
  cerr << "Unknown exception!" << endl;
  return 2;
}

void print_sv(const string& label, const vector<string>& v) {
  cout << label << ": { ";
  for (string i : v) cout << i << ' ';
  cout << "}\n";
}

vector<string> reverse_retv(const vector<string>& v) {
  vector<string> rev;
  for (auto i = v.size(); i > 0; --i)
    rev.push_back(v[i-1]);
  return rev;
}

void reverse_swapv(vector<string>& v) {
  auto limit {v.size()/2};
  auto last {v.size()-1};

  for (size_t i = 0; i < limit; ++i)
    swap(v[i], v[last - i]);
}
