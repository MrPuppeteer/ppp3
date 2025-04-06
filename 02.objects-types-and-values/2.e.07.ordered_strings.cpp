// Print three string values in order
import std;
using namespace std;

int main() {
  string x = "";
  string y = "";
  string z = "";

  cout << "Enter three string values: ";
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
