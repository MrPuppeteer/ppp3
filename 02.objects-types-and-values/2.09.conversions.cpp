import std;
using namespace std;

int main() {
  char c = 'x';
  int i1 = c;         // i1 gets the integer value of c
  int i2 = c+1000;    // i2 gets the integer value of c added to 1000
  double d = i2+7.3;  // d gets the floating-point value of i2 plus 7.3

  int x0 = 7.8;   // narrows, some compilers warn
  int x1 {7.8};   // error: {} doesn't narrow
  int x2 = {7.8}; // error: ={} doesn't narrow (the redundant = is allowed)
  int x3 (7.8);   // narrows, some compilers warn

  int x = 7;
  double e = 7.7;
  string s = "Hello, World\n";

  vector v = {1, 2, 3, 5, 8};
  pair p {"Hello",17};
}
