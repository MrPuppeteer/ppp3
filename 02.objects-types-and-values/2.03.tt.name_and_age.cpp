// read name and age (try this)
import std;
using namespace std;

int main() {
  cout << "Please enter your first name and age\n";
  string first_name = "???";  // string variable ("???" indicates "don't know the name")
  double age = -1;            // double variable (-1 means "don't know the age")
  cin >> first_name >> age;   // read a string followed by an double
  cout << "Hello, " << first_name << " (age " << age * 12 << " month(s))\n";
}
