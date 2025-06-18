import std;
using namespace std;

char ask_user(string question);   // ask user a yes-or-no answer;
                                  // return 'b' to indicate a bad answer (i.e., not yes or no)

int area(int length, int width);  // calculate area of a rectangle;
                                  // return -1 to indicate a bad argument

int framed_area(int x, int y);    // calculate area within frame

// void test(int x, int y, int z);

int f(int x, int y, int z);

int main() {
  // test(-1,2,3);
  f(-1,2,3);
}

char ask_user(string question) {
  cout << question << "? (yes or no)\n";
  string answer;
  cin >> answer;
  if (answer=="y" || answer=="yes")
    return 'y';
  if (answer=="n" || answer=="no")
    return 'n';
  return 'b';     // 'b' for "bad answer"
}

int area(int length, int width) {
  if (length<=0 || width<=0)
    return -1;
  return length*width;
}


int framed_area(int x, int y) {
  return area(x-2,y-2);
}


// void test(int x, int y, int z) {
//   int area1 = area(x,y);
//   int area2 = framed_area(1,z);
//   int area3 = framed_area(y,z);
//   double ratio = double(area1)/area3; // convert to double to get floating-point division
//   // ...
// }


int f(int x, int y, int z) {
  int area1 = area(x,y);
  if (area1<=0)
    throw runtime_error("non-positive area");
  int area2 = framed_area(1,z);
  int area3 = framed_area(y,z);
  double ratio = double(area1)/area3;
  // ...
  return 0;
}
