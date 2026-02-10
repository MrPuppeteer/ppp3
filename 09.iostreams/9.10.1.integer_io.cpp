import std;
using namespace std;

int main() {
  int x = 1234;
  cout << x << " - " << hex << x << " - " << oct << x << " - " << dec << x << '\n';

  int a = 0;
  int b = 0;
  int c = 0;
  cin >> a >> hex >> b >> oct >> c;
  cout << dec;
  cout << a << '\t' << b << '\t' << c << '\n';
  cout << hex;
  cout << a << '\t' << b << '\t' << c << '\n';
}
