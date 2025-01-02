// Use of undeclared identifier 'std'. Add the required import.

import std;

// Unknown type name 'integer'. C++ used abbreviation int rather than integer.
// integer main()
int main()
{
  // Use of undeclared identifier 'cout'. Change it to std::cout.
  // cout << "Hello, World!\n";

  // Missing terminating '"' character. Terminate the string with a ".
  // std::cout << "Hello, World!\n;

  /*
   * Invalid operands to binary expression ('ostream' (aka 'basic_ostream<char>')
   * and 'const char[15]'). Use the output operator << rather than the less operator <.
   */
  // std::cout < "Hello, World!\n";

  // Character constant too long for its type. Use double quotes to delimit the string.
  // std::cout << 'Hello, World!\n';

  // Expected ';' after expression. Terminate the statement with semicolon (;).
  // std::cout << "Hello, World!\n"

  std::cout << "Hello, World!\n";

  /*
   * We can leave out the return statement in main and it's as if we had written return 0;
   * and the end of main's body to indicate successful completion.
   */ 
  // return 0;
}
