// Use of undeclared identifier 'std'. Add the required import.

import std;
// #include <iostream>

// Unknown type name 'integer'. C++ used abbreviation int rather than integer.
// integer main()

/*
 * #5 'main' must return 'int'. 'main' function must use 'int' type. This allows the program to
 * return a value to the operating system to indicate success or failure.
 */
// double main()

int main()    // C++ programs start by executing the function main
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

  /*
   * #1 Use of undeclared identifier 'STD'. Expected '{' after '\N' escape sequence.
   * C++ is case-sensitive
   */
  // STD::COUT << "hELLO, wORLD!\N";

  /*
   * #2 Invalid operands to binary expression ('istream' (aka 'basic_istream<char>') and
   * 'const char[14]'). Use cout to output characters and cin to input.
   */
  // std::cin << "Hello, World\n";

  // #3 Slight typo.
  // std::cout << "Hell, World!\n";

  std::cout << "Hello, World!\n";   // output "Hello, World!"

  /*
   * We can leave out the return statement in main and it's as if we had written return 0;
   * and the end of main's body to indicate successful completion.
   */ 
  // return 0;

  // #4 Expected '}'. To match this '{'. Ensure every '{' has a matching '}'.
}
