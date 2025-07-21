import std; // get the ISO C++ standard library

// using std::string;  // from here on, string means std::string
// using std::cout;    // from here on, cout means std::cout
using namespace std;  // make names from std directly accessible

int main() {
  // std::string name;
  // std::cout << "Please enter your first name\n";
  // std::cin >> name;
  // std::cout << "Hello, " << name << '\n';
  string name;
  cout << "Please enter your first name\n";
  cin >> name;
  cout << "Hello, " << name << '\n';
}
