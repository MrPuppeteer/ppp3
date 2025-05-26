// calculate and print a table of characters a-z A-Z 0-9
import std;
using namespace std;

int main() {
  for (char i = 'a'; i <= 'z'; ++i)
    cout << i << '\t' << int{i} << '\n';

  for (char i = 'A'; i <= 'Z'; ++i)
    cout << i << '\t' << int{i} << '\n';

  for (char i = '0'; i <= '9'; ++i)
    cout << i << '\t' << int{i} << '\n';
}
