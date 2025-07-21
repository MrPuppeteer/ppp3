import std;
using namespace std;

// void print(vector<double> v) {  // pass-by-value; appropriate?
//   cout << "{ ";
//   for (int i = 0; i<v.size(); ++i) {
//     cout << v[i];
//     if (i!=v.size()-1) cout << ", ";
//   }
//   cout << "}\n";
// }

void print(const vector<double>& v) { // pass-by-const-reference
  cout << "{ ";
  for (int i = 0; i<v.size(); ++i) {
    cout << v[i];
    if (i!=v.size()-1) cout << ", ";
  }
  cout << " }\n";
}

void f(int x) {
  vector<double> vd1(10);       // small vector
  vector<double> vd2(1000000);  // large vector
  vector<double> vd3(x);        // vector of some unknown size

  // ... fill vd1, vd2, vd3 with values ...

  print(vd1);
  print(vd2);
  print(vd3);
}

// void print(const vector<double>& v) { // pass-by-const-reference
//   // ...
//   v[i] = 7; // error: v is a const (is not mutable)
//   // ...
// }

int my_find(vector<string> vs, string s); // pass-by-value: copy

// pass-by-const-reference: no copy, read-only
int my_find(const vector<string>& vs, const string& s);
