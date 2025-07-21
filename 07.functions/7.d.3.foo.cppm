export module foo;

import std;
using namespace std;

int foo = 0;
export void print_foo() { cout << foo << '\n'; }
export void set_foo(int x) { foo = x; }
export int get_foo() { return foo; }
