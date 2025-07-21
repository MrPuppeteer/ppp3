import std;
using namespace std;

void print_iv(const string& label, const vector<int>& v);

int main() {
  vector<int> v = {0, 2, 4, 6, 8, 10};

  print_iv("Even numbers", v);
}

void print_iv(const string& label, const vector<int>& v) {
  cout << label << ": { ";
  for (int i : v) cout << i << ' ';
  cout << "}\n";
}
