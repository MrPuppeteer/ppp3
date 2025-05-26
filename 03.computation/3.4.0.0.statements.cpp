import std;
using namespace std;

int main() {
  int a = 0;
  int b = 0;
  int c = 0;
  int x = 0;
  int y = 0;
  
  // expression statements
  a=b;
  ++c;

  // Why do we need semicolon?
  // a=b
  // ++c;  // syntax error: missing semicolon

  // computer executes statements in order in which they are written
  int d = 7;
  cout << d << '\n';

  // statements without effect are typically useless
  1+2;  // do an addition, but don't use the sum
  a*b;  // do a multiplication, but don't use the product

  // empty statement
  if (x == 5);
    y = 3;
}
