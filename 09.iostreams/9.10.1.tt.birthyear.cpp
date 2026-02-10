import std;
using namespace std;

int main() {
  int x = 2003;
  int age = 2025-x;
  cout << "*" << "\t\t" << "dec" << '\t' << "hex" << '\t' << "oct" << '\n';
  cout << "birthyear" << '\t' << x << '\t' << hex << x << '\t' << oct << x << '\n';
  cout << "age" << "\t\t" << dec << age << '\t' << hex << age << '\t' << oct << age << '\n';
}
