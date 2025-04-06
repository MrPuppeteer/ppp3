// Spell numbers into digits
import std;
using namespace std;

int main() {
  cout << "Enter an integer as a text string: ";
  string s;
  cin >> s;

  int val = -1;
  if (s=="zero") val = 0;
  else if (s=="one") val = 1;
  else if (s=="two") val = 2;
  else if (s=="three") val = 3;
  else if (s=="four") val = 4;

  if (val >= 0)
    cout << s << " has the value of " << val << '\n';
  else
    cout << s << " is not a number I know\n";
}
