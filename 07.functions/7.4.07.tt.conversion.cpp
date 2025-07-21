import std;
using namespace std;

int main() try {
  int anint = 1001;
  double adouble = 7.7;
  char achar = 'x';

  double anint_double = anint;
  char anint_char = anint;
  int adouble_int = adouble;
  char adouble_char = adouble;
  int achar_int = achar;
  double achar_double = achar;

  cout << "Conversions:\n"
       << "  Implicit conversion:\n"
       << "    Int to Double: int(" << anint << ") -> double(" << anint_double << ")\n"
       << "    Int to Char: int(" << anint << ") -> char(" << anint_char << ")\n"
       << "    Double to Int: double(" << adouble << ") -> int(" << adouble_int << ")\n"
       << "    Double to Char: double(" << adouble << ") -> char(" << adouble_char << ")\n"
       << "    Char to Int: char(" << achar << ") -> int(" << achar_int << ")\n"
       << "    Char to Double: char(" << achar << ") -> double(" << achar_double << ")\n"
       << "  Static cast:\n"
       << "    Int to Double: int(" << anint << ") -> double(" << static_cast<double>(anint) << ")\n"
       << "    Int to Char: int(" << anint << ") -> char(" << static_cast<char>(anint) << ")\n"
       << "    Double to Int: double(" << adouble << ") -> int(" << static_cast<int>(adouble) << ")\n"
       << "    Double to Char: double(" << adouble << ") -> char(" << static_cast<char>(adouble) << ")\n"
       << "    Char to Int: char(" << achar << ") -> int(" << static_cast<int>(achar) << ")\n"
       << "    Char to Double: char(" << achar << ") -> double(" << static_cast<double>(achar) << ")\n";
} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "unknown error" << '\n';
  return 2;
}
