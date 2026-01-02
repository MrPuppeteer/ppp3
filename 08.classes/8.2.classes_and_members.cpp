import std;
using namespace std;

class X {
public:
  int m;  // data member
  int mf(int v) { int old = m; m=v; return old; } // function member
};

int main() {
  X var;  // var is a variable of type X
  var.m = 7;  // assign to var's data member m
  int x = var.mf(9);  // call var's member function mf()
}
