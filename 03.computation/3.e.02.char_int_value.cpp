import std;
using namespace std;

int main() {
  string input = "";
  cin >> input;

  for (char i : input)
    cout << i << '\t' << int{i} << '\n';
}
