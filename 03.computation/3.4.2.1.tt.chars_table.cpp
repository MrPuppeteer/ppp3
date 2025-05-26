// calculate and print a table of characters a-z
import std;
using namespace std;

int main() {
  char i = 'a';  // start from a
  while (i<='z') {
    cout << i << '\t' << int{i} << '\n';
    ++i;      // increment i (that is, i becomes i+1)
  }
}
