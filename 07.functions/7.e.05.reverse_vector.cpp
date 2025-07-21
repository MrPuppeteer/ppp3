import std;
using namespace std;

void print_iv(const string& label, const vector<int>& v);

// returns a new vector in reverse
vector<int> reverse_retv(const vector<int>& v);

// reverse vector
void reverse_swapv(vector<int>& v);

int main() try {
  vector<int> odd_v = {1, 3, 5, 7, 9};
  print_iv("v", odd_v);
  vector<int> rev_odd_v = {reverse_retv(odd_v)};
  print_iv("Reverse v by const-ref", rev_odd_v);
  reverse_swapv(odd_v);
  print_iv("Reverse v by ref", odd_v);

  vector<int> even_v = {2, 4, 6, 8};
  print_iv("v", even_v);
  vector<int> rev_even_v = {reverse_retv(even_v)};
  print_iv("Reverse v by const-ref", rev_even_v);
  reverse_swapv(even_v);
  print_iv("Reverse v by ref", even_v);
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

vector<int> reverse_retv(const vector<int>& v) {
  vector<int> rev;
  for (auto i = v.size(); i > 0; --i)
    rev.push_back(v[i-1]);
  return rev;
}

void reverse_swapv(vector<int>& v) {
  auto limit {v.size()/2};
  auto last {v.size()-1};

  for (size_t i = 0; i < limit; ++i)
    swap(v[i], v[last - i]);
}
