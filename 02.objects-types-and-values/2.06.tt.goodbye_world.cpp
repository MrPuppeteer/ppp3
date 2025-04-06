import std;
using namespace std;

// undefined reference to `main'
// int Main() {
int main() {
  // unknown type name 'STRING'
  // STRING s = "Goodbye, cruel world!";
  string s = "Goodbye, cruel world!";
  // use of undeclared identifier 'cOut'; did you mean 'cout'
  // cOut << S << '\n';
  // error: use of undeclared identifier 'S'
  // cout << S << '\n';
  cout << s << '\n';
}
