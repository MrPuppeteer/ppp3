#include "7.d.4.foo.h"
import std;
using namespace std;

int main() {
  cout << "Initial value of foo: ";
  print_foo(); // 0

  foo = 42;
  std::cout << "Value of foo after directly modified (foo=42): ";
  print_foo(); // 42

  cout << "print(42) returned: ";
  print(42);  // 42

  return 0;
}
