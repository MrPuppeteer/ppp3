import std;
using namespace std;

int main() {
  // string and vector are defined so that variable of those types are
  // initialized with a default value whenever we don't supply one explicitly,
  // thus
  vector<string> v; // v is empty (it has no elements)
  string s;         // s is the empty string ("")
  // before we reach the loop
  while (cin >> s)
    v.push_back(s);
}
