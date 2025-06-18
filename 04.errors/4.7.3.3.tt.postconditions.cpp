import std;
using namespace std;

void expect(bool cond, string mess);

// calculate area of a rectangle
// the arguments are positive
int area(int length, int width);

// for the program to satisfies precondition but fails postcondition
// length & width must be positive integer
// length * width must be higher than INT_MAX (which causes integer overflow)
// length, width
// 46341,  46341
// 46339,  46342
int main() try {
  int length;
  int width;
  cout << "Enter a length and a width: ";
  while (cin >> length >> width) {
    int a = area(length, width);
    cout << "Area is: " << a << '\n';
  }
} catch(runtime_error& e) {
  cerr << "runtime_error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "Oops: unknown exception!\n";
  return 2;
}

void expect(bool cond, string mess) {
  if (!cond) {
    throw runtime_error(mess);
  }
}

int area(int length, int width) {
  expect([&]{ return 0<length && 0<width; }(), "bad arguments to area()");
  int a = length*width;
  expect([&]{ return 0<a; }(), "bad area() result");
  return a;
}
