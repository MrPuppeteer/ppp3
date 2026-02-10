import std;
using namespace std;

int main() {
  string name;
  cin >> name;  // input: Dennis Ritchie
  cout << name << '\n'; // output: Dennis

  string name2;
  getline(cin,name2);  // input: Dennis Ritchie
  cout << name2 << '\n'; // output: Dennis Ritchie
}
