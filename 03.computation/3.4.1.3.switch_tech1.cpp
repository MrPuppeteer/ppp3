// you can switch only on integers, etc.:
import std;
using namespace std;

int main() {
  cout << "Do you like fish?\n";
  string s;
  cin >> s;

  switch (s) { // error: the value must be of integer, char, or enum type
    case "no":
      //...
      break;
    case "yes":
      //...
      break;
  }
}
