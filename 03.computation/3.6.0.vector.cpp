import std;
using namespace std;

int main() {
  vector<int> v = {5, 7, 9, 4, 6, 8}; // vector of 6 ints
  vector<string> philosopher = {"Kant", "Plato", "Hume", "Kierkegaard"};  // vector of 4 strings

  philosopher[2] = 99;  // error: trying to assign an int to a string
  v[2] = "Hume";        // error: trying to assign a string to an int

  vector<int> vi(6);    // vector of 6 ints initialized to 0
  vector<string> vs(4); // vector of 4 strings initialized to "" (empty string)

  vi[20000] = 44; // run-time error
}
