// Determine if an integer is odd or even
import std;
using namespace std;

int main() {
  int x = 0;
  cout << "Enter an integer: ";
  cin >> x;

  cout << "The value " << x << " is an "
       << ((x%2) ? "odd" : "even")
       << " number\n";
}
