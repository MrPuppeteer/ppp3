import std;
using namespace std;

int main() {
  printf("an int %d and a string '%s'\n", 123, "Hello!");

  string val = "World";
  // int val = 127;
  string s = format("Hello, {}!\n", val);

  int x = 1234;
  cout << format("{} - {:x} - {:o} - {:d} - {:b}\n", x, x, x, x, x);

  constexpr double d = 1234.56789;
  cout << format("format: {} - {:a} - {:e} - {:f} - {:g}\n", d, d, d, d, d);

  cout << format("width: {} - {:8} - {:20} -\n", d, d, d);

  cout << format("precision: {} - {:.8} - {:.20} -\n", d, d, d);

  cout << format("- {:12} - {:12.8f} - {:30.20e} -\n", d, d, d);
}
