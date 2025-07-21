import std;
using namespace std;

int main() {
  // f(++i,++i); // don't: undefined order of evaluation
  // x = ++i + i;  // don't: undefined order of evaluation
  // z = f(x)+g(y);  // don't if the order of f(x) and g(y) matters
  // h(f(x),g(y)); // don't if the order of f(x) and g(y) matters

  // if (0<=x && v[x]!=0) ...  // v[x] will never be executed for x<0
  // v[i] = ++i; // i will be incremented before being used as a subscript
  // cout << ++i << ' ' << ++i;  // will print "2 3" if invoked with i==1
}
