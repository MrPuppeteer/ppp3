import std;
using namespace std;

int main() {
  const vector<string> nums = {
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine"
  };

  cout << "Enter a single-digit number to get spelled-out value\n"
       << "or enter the spelled-out number to get its digit form:\n";
  int n = -1;
  string name = "";

  while (true) {
    if (cin >> n) {
      if (n < 0 || n > 10)
        cout << "Please enter a single-digit number!\n";
      else
        cout << nums[size_t(n)] << '\n';
    } else {
      cin.clear();
      cin >> name;
      if (name == "|")
        break;

      int number = -1;

      for (size_t i = 0; i < nums.size(); ++i) {
        if (name == nums[i]) {
          number = int(i);
        }
      }

      if (number == -1)
        cout << "Not a spelled-out single-digit number!\n";
      else
        cout << number << '\n';
    }
  }
}
