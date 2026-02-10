import std;
using namespace std;

int get10() {
  cout << "Please enter an integer in the range 1 to 10 (inclusive):\n";
  int n = 0;
  while (cin>>n) {  // read
    if (1<=n && n<=10) return n; // check range
    cout << "Sorry " << n << " is not in the [1:10] range; please try again\n";
  }
}
