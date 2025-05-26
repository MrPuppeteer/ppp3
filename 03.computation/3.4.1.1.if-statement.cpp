import std;
using namespace std;

int main() {
  int a = 0;
  int b = 0;
  cout << "Please enter two integers\n";
  cin >> a >> b;

  if (a<b)  // condition
    cout << a << " is smaller than " << b << '\n';    // 1st alternative (if condition is true)
  else
    cout << a << " is larger than or equal to " << b << '\n'; // 2nd alternative (if condition is false)
}
