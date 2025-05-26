// case labels must be distinct and constants:
import std;
using namespace std;

int main() {
  int y = 'y';  // this is going to cause trouble
  constexpr char n = 'n';

  cout << "Do you like fish?\n";
  char a = 0;
  cin >> a;

  switch (a) {
    case n:
      //...
      break;
    case y:   // error: variable in case label
      //...
    case 'n': // error: duplicate case label (n's value is 'n')
      //...
      break;
    default:
      //...
      break;
  }
}
