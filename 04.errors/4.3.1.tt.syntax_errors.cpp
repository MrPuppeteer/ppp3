import std;
using namespace std;

int area(int length, int width);  // calculate area of a rectangle

int main() {
  // int s1 = area(7,2;    // error: ) missing
  // error: expected ')'
  // note: to match this '('

  // int s2 = area(7,2)    // error: ; missing
  // error: expected ';' at end of declaration
  
  // Int s3 = area(7,2);   // error: Int (with a capitalized 'i') is not a type
  // error: use of undeclared identifier 'Int'; did you mean 'int'?

  // int s4 = area('7,2);  // error: non-terminated character '; terminating ' is missing
  // warning: multi-character constant [-Wmultichar]
  // warning: character constant too long for its type
  // error: expected ')'
  // note: to match this '('
}

int area(int length, int width) {
  return length*width;
}
