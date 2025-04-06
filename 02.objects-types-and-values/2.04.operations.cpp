// opearations example
import std;
using namespace std;

int main() {
  int age = -1;
  cin >> age;                 // >> reads an integer into age

  string name;
  cin >> name;                // >> reads a string into name

  int a2 = age+2;             // + adds integers
  string n2 = name + " Jr.";  // + concatenates strings

  int a3 = age-2;             // - substracts integers
  // string n3 = name - " Jr.";  // error: - isn't defined for strings
}
