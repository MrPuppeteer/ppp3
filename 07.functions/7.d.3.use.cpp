import std;
import foo;

using namespace std;

int main() {
  cout << "Initial value of foo: ";
  print_foo(); // 0

  set_foo(42);
  cout << "Value of foo after set_foo(42): ";
  print_foo(); // 42

  int current_foo = get_foo();
  cout << "get_foo() returned: " << current_foo << '\n';  // 42

  return 0;
}
