import std;
using namespace std;

double ctok(double c);  // converts Celcius to Kelvin

int main()
try {
  double c = 0;         // declare input variable
  cin >> c;             // retrieve temperature to input variable
  double k = ctok(c);   // convert temperature
  cout << k << '\n';    // print out temperature
} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
}

double ctok(double c) { // converts Celsius to Kelvin
  if (c < -273.15)
    throw runtime_error("the temperature cannot be below absolute zero! (0K = -273.15c)");
  double k = c + 273.15;
  return k;
}

/* Error list:
 * warning: implicit conversion turns floating-point number into integer: 'double' to 'int'
 * logic error also 0C = 273.15K
 * 1. int k = c + 273.25; -> double k = c + 273.15;
 *
 * error: expected '(' for function-style cast or type construction
 * 2. return int -> return k;
 *
 * error: use of undeclared identifier 'd'
 * 3. cin >> d; -> cin >> c;
 *
 * error: no matching function for call to 'ctok'
 * 4. ctok("c"); -> ctok(c);
 *
 * error: use of identifier 'Cout'; did you mean 'cout'?
 * 5. Cout -> cout
 *
 * warning: multi-character character constant
 * 6. '/n' -> '\n'
 */ 

