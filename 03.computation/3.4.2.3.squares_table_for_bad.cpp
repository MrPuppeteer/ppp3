// calculate and print a table of squares 0-99
// bad code
import std;
using namespace std;

int square(int x);

int main() {
  // for i in the [0:100) range
  for (int i = 0; i<100; ++i) {
    cout << i << '\t' << square(i) << '\n';
    ++i;  // what's going on here? it smells like an error!
  }
}

int square(int x) {
  return x*x;
}
