import std;
using namespace std;

// T f() { // f() returns a T
//   V v;
//   // ...
//   return v;
// }
//
// V v;
// // ...
// T t(v); // initialize t with v

double my_abs(int x) {  // warning: buggy code
  if (x < 0) return -x;
  else if (x > 0) return x;
  // error: no value returned if x is 0
}

void print_until(vector<string> v, string quit) { // print until the string called "quit" is found
  for (string s : v) {
    if (s==quit) return;
    cout << s << '\n';
  }
}
