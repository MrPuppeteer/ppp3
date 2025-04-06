import std;
using namespace std;

int main() {
  string a = "alpha"; // a starts out with the value "alpha"

  a = "beta";         // a gets the value "beta" (becomes "beta")

  string b = a;       // b starts out with a copy of a's value (that is, "beta")

  b = a+"gamma";      // b gets the value a+"gamma" (that is, "betagamma")

  a = a+"delta";      // a gets the value a+"delta" (that is, "betadelta")
}
