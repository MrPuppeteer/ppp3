import std;
using namespace std;

int area(int length, int width);  // calculate area of a rectangle

int main() {
  int s1 = area(7,2;    // error: ) missing
  int s2 = area(7,2)    // error: ; missing
  Int s3 = area(7,2);   // error: Int (with a capitalized 'i') is not a type
  int s4 = area('7,2);  // error: non-terminated character '; terminating ' is missing
}

int area(int length, int width) {
  return length*width;
}
