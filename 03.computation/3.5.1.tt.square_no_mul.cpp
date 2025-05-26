import std;
using namespace std;

int square(int x);

int main() {
  for (int i = 0; i<100; ++i)
    cout << i << '\t' << square(i) << '\n';
}

// return the square of x without using multiplication
int square(int x) {
  int sum = 0;
  for (int i = 0; i < x; ++i)
    sum += x;
  return sum;
}
