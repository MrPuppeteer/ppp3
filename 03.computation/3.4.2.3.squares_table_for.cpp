// calculate and print a table of squares 0-99
import std;
using namespace std;

int square(int x);

int main() {
  for (int i = 0; i<100; ++i)
    cout << i << '\t' << square(i) << '\n';
}

int square(int x) {
  return x*x;
}
