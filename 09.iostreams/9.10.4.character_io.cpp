import std;
using namespace std;

int main() {
  for (char ch; cin.get(ch); ) {
    if (isspace(ch)) {
      // do nothing; i.e., skip whitespace (e.g. space or tab)
    } else if (isdigit(ch)) {
      // ... read a number ...
    } else if (isalpha(ch)) {
      // ... read an identifier ...
    } else {
      // ... deail with operators ...
    }
  }
}

// put s into lowercase
void tolower(string& s) {
  for (char& x : s) x = tolower(x);
}
