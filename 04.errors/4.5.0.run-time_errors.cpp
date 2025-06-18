import std;
using namespace std;

int area(int length, int width);  // calculate area of a rectangle

int framed_area(int x, int y);    // calculate area within frame

void test(int x, int y, int z);

int main() {
  test(-1,2,3);
}

int area(int length, int width) {
  return length*width;
}


int framed_area(int x, int y) {
  return area(x-2,y-2);
}


void test(int x, int y, int z) {
  int area1 = area(x,y);
  int area2 = framed_area(1,z);
  int area3 = framed_area(y,z);
  double ratio = double(area1)/area3; // convert to double to get floating-point division
  // ...
}
