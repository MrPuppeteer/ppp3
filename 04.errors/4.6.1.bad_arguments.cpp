import std;
using namespace std;

class Bad_area {};                // a type specifically for reporting errors from area()

int area(int length, int width);  // calculate area of a rectangle;
                                  // throw a Bad_area exception in case of a bad argument

int framed_area(int x, int y);    // calculate area within frame

void test(int x, int y, int z);

int main() try {
  test(-1,2,4);
} catch(Bad_area) {
  cout << "Oops! bad arguments to area()\n";
}

int area(int length, int width) {
  if (length<=0 || width<=0)
    throw Bad_area{};
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
