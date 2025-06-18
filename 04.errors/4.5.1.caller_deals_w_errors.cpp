import std;
using namespace std;

int area(int length, int width);  // calculate area of a rectangle

constexpr int frame_width = 2;

int framed_area(int x, int y);    // calculate area within frame

void test(int x, int y, int z);

int main() {
  test(-1,2,3);
}

int area(int length, int width) {
  return length*width;
}


int framed_area(int x, int y) {
  // return area(x-2,y-2);
  return area(x-frame_width,y-frame_width);
}


void test(int x, int y, int z) {
  // if (x<=0)
  //   throw runtime_error("non-positive x");
  // if (y<=0)
  //   throw runtime_error("non-positive y");
  if (x<=0 || y<=0)
    throw runtime_error("non-positive area() argument");
  int area1 = area(x,y);

  // if (z<=2)
    // throw runtime_error("non-positive 2nd area() argument called by framed_area()");
  if (1-frame_width<=0 || z-frame_width<=0)
    throw runtime_error("non-positive argument for area() called by framed_area()");
  int area2 = framed_area(1,z);
  
  // if (y<=2 || z<=2)
    // throw runtime_error("non-positive area() argument called by framed_area()");
  if (y-frame_width<=0 || z-frame_width<=0)
    throw runtime_error("non-positive argument for area() called by framed_area()");
  int area3 = framed_area(y,z);
  
  double ratio = double(area1)/area3; // convert to double to get floating-point division
  // ...
}
