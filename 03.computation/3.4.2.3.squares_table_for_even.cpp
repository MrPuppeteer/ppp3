// calculate and print a table of even squares in the [0:100) range
import std;
using namespace std;

int square(int x);

int main() {
  for (int i = 0; i<100; i+=2)
    cout << i << '\t' << square(i) << '\n';
}

int square(int x) {
  return x*x;
}
