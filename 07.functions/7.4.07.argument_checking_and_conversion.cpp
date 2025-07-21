import std;
using namespace std;

// void f(T x);
// f(y);
// T x = y;  // initialize x with y

void f(double x);

void g(int y) {
  f(y);
  double x = y; // initialize x with y
}

int main() {
  g(7.8);       // truncate 7.8 to 7; did you really mean to do that?
  int x = 7.8;  // truncate 7.8 to 7; did you really mean to do that?
}

void conv1(double y) {
  int x = static_cast<int>(y);
}

void conv2(double y) {
  int x = round(y); // 4/5 rounding
}

void conv3(int x, int y) {
  double z = double(x)/y; // x/y would have truncated
}
