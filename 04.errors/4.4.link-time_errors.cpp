import std;
using namespace std;

int area(int length, int width);  // calculate area of a rectangle

int main() {
  int x = area(2,3);
}

// "our" area()
int area(int length, int width) {
  return length*width;
}

// not "our" area()
// double area(double x, double y) { /* ... */ }

// not "our" area()
// int area(int x, int y, char unit) { /* ... */ }
