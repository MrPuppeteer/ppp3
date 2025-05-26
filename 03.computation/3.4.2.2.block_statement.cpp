import std;
using namespace std;

int main() {
  int a;
  int b;
  cin >> a >> b;

  if (a<=b) {
    // do nothing
  } else {
    // swap a and b:
    int t = a;
    a = b;
    b = t;
  }
}
