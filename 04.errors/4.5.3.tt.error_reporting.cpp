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
  // f(-1,2,3);
  int x, y, z;
  while (cin >> x >> y >> z) {
    cout << "x: " << x << '\n'
         << "y: " << y << '\n'
         << "z: " << z << '\n';
    f(x, y, z);
  }
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
  if (area2 <= 0)
    throw runtime_error("non-positive area");
  
  int area3 = framed_area(y,z);
  if (area3 <= 0)
    throw runtime_error("non-positive area");
  
  double ratio = double(area1)/area3;
  
  cout << "area1: " << area1 << '\n'
       << "area2: " << area2 << '\n'
       << "area3: " << area3 << '\n'
       << "ratio: " << ratio << '\n';

  return 0;
}
