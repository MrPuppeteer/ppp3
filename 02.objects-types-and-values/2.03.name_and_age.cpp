// read name and age
import std;
using namespace std;

int main() {
  cout << "Please enter your first name and age\n";
  string first_name = "???";  // string variable ("???" indicates "don't know the name")
  int age = -1;               // integer variable (-1 means "don't know the age")
  cin >> first_name >> age;   // read a string followed by an integer
  cout << "Hello, " << first_name << " (age " << age << ")\n";
}
