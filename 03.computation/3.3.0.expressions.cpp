import std;
using namespace std;

int main() {
  int length = 20;          // a literal integer (used to initialize a variable)
  int width = 40;
  int area = length*width;  // a multiplication

  length = 99;  // assign 99 to length

  int perimeter = (length+width)*2;     // add then multiply
  // int perimeter = length*2+width*2;
  // int perimeter = length+width*2;    // add width*2 to length -> logical error
  
  // ugly code slows down reading and comprehension
  // a*b+c/d*(e/-f/g)/h+7 // too complicated
}
