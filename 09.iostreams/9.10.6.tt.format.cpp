import std;
using namespace std;

int main() {
  constexpr double d = 1234.56789;
  cout << format("- {:12} - {:12.8f} - {:30.20e} -\n", d, d, d);
  // prints: -   1234.56789 - 1234.56789000 -     1.23456789000000003398e+03 -
  cout << format("- {:12.4} - {:12.4f} - {:8.8a} - {:12.2e} - {:1.1g} -\n", d, d, d, d, d);
  // prints: -         1235 -    1234.5679 - 1.34a4584fp+10 -     1.23e+03 - 1e+03 -
}
