import std;
using namespace std;

int area(int length, int width);  // calculate area of a rectangle

int main() {
  // int x0 = arena(7,2);      // error: undeclared function
  // error: use of undeclared identifier 'arena'; did you mean 'area'?
  // note: 'area' declared here

  // int x1 = area(7);         // error: wrong number of arguments
  // error: no matching function for call to 'area'
  // note: candidate function not viable: requires 2 arguments, but 1 was provided

  // int x2 = area("seven",2); // error: 1st argument has a wrong type
  // error: no matching function for call to 'area'
  // note: candidate function not viable: no known conversion from 'const char[6]' to 'int' for
  // 1st argument
}

int area(int length, int width) {
  return length*width;
}
