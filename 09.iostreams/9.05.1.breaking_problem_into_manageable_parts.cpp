import std;
using namespace std;

// int get10() {
//   cout << "Please enter an integer in the range 1 to 10 (inclusive):\n";
//   int n = 0;
//   while (true) {
//     cin>>n;
//     if (cin) {  // we got an integer; now check it
//       if (1<=n && n<=10) return n;
//       cout << "Sorry " << n << " is not in the [1:10] range; please try again\n";
//     } else if (cin.fail()) {  // we found something that wasn't an integer
//       cin.clear(); // set the state back to good(); we want to look at the characters
//       cout << "Sorry that was not a number; please try again\n";
//       for (char ch; cin>>ch && !isdigit(ch); ) /*nothing*/; // throw away non-digits
//       if (!cin) throw runtime_error("no input");
//       cin.unget(); // put the digit back, so taht we can read the number
//     } else throw runtime_error("no input"); // bad: give up
//   }
// }

void skip_to_int() {
  if (cin.fail()) { // we found something that wasn't an integer
    cin.clear();  // we'd like to look at the characters
    for (char ch; cin>>ch; ) { // throw away non-digits
      if (isdigit(ch) || ch=='-') {
        cin.unget();  // put the digit back, so that we can read the number
        return;
      }
    }
  }
  throw runtime_error("no input");  // eof or bad: give up
}

// int get10() {
//   cout << "Please enter an integer in the range 1 to 10 (inclusive):\n";
//   int n = 0;
//   while (true) {
//     if (cin>>n) { // we got an integer; now check it
//       if (1<=n && n<=10) return n;
//       cout << "Sorry " << n << " is not in the [1:10] range; please try again\n";
//     } else {
//       cout << "Sorry, that was not a number; please try again\n";
//       skip_to_int();
//     }
//   }
// }

int get_int();  // read an int from cin
int get_int(int low, int high); // read an int in [low:high] from cin

int get_int() {
  int n = 0;
  while (true) {
    if (cin >> n) return n;
    cout << "Sorry, that was not a number; please try again\n";
    skip_to_int();
  }
}

int get_int(int low, int high) {
  cout << "Please enter an integer in the range "
       << low << " to " << high << " (inclusive):\n";
  while (true) {
    int n = get_int();
      if (low<=n && n<=high) return n;
      cout << "Sorry " << n << " is not in the [" << low << ':' << high
           << "] range; please try again\n";
  }
}
