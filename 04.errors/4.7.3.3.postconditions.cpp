import std;
using namespace std;

void expect(bool cond, string mess);

// calculate area of a rectangle
// the arguments are positive
int area(int length, int width);

int main() {
  area(2,3);
}

void expect(bool cond, string mess) {
  if (!cond) {
    throw runtime_error(mess);
  }
}

// int area(int length, int width) {
//   expect([&]{ return 0<length && 0<width; }(), "bad arguments to area()");
//   return length*width;
// }

// looks bloated but useful when correct results are critically important
int area(int length, int width) {
  expect([&]{ return 0<length && 0<width; }(), "bad arguments to area()");
  int a = length*width;
  expect([&]{ return 0<a; }(), "bad area() result");
  return a;
}

// // straightforward
// int area(int length, int width) {
//   return length*width;
// }
