import std;
using namespace std;

int main() {
  int x = 2003;
  int age = 2025-x;
  cout << "*" << "\t\t" << "dec" << '\t' << "hex" << '\t' << "oct" << '\n' << showbase;
  cout << "birthyear" << '\t' << x << '\t' << hex << x << '\t' << oct << x << '\n' << dec;
  cout << "age" << "\t\t" << age << '\t' << hex << age << '\t' << oct << age << "\n\n" << dec;
}
