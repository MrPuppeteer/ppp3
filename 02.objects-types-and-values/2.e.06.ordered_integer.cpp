// Print three integer values in order
import std;
using namespace std;

int main() {
  int x = 0;
  int y = 0;
  int z = 0;

  cout << "Enter three integer values: ";
  cin >> x >> y >> z;

  if (x <= y && x <= z) {
    if (z <= y) {
      swap(y, z);
    }
  } else if (y <= x && y <= z) {
    swap(x, y);
    if (z <= y) {
      swap(y, z);
    }
  } else {
    swap(x, z);
    if (z <= y) {
      swap(y, z);
    }
  }

  cout << x << ", " << y << ", " << z << '\n';
}
