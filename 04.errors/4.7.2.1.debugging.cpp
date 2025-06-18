import std;
using namespace std;

int my_fct(int a, double d);

// the arguments are positive and a < b < c
int my_complicated_function(int a, int b, int c);

int main() {
  // int max = 1;
  // vector<int> v = {1,2,3,4,5};
  // for (int i = 0; 0<=max; ++i) {              // oops!
  //   for (int j = 0; j<v.size(); ++i);         // print the elements of v
  //     cout << "v[" << j << "]==" << v[j] << '\n';
  //   // ...
  // }
}

int my_fct(int a, double d) {
  cerr << "my_fct(" << a << "," << d << ")\n";
  int res = 0;
  // ... misbehaving code here ...
  cerr << "my_fct() return " << res << '\n';
  return res;
}


int my_complicated_function(int a, int b, int c) {
  if (!(0<a && a<b && b<c))
    throw runtime_error("bad arguments for mcf");
  // ...
  return 0;
}
