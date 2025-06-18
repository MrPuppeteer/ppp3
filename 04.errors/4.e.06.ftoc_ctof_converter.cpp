import std;
using namespace std;

double ctof(double c);  // converts Celcius to Fahrenheit

double ftoc(double c);  // converts Fahrenheit to Celcius

int main()
try {
  double in = 0;        // declare input variable
  char unit = ' ';

  cin >> in >> unit;    // retrieve temperature to input variable
  
  switch (unit) {
  case 'c': case 'C':
    cout << ctof(in) << "°F\n"; // convert and print out temperature
    break;
  case 'f': case 'F':
    cout << ftoc(in) << "°C\n"; // convert and print out temperature
    break;
  default:
    throw runtime_error("unrecognized temperature unit!");
  }
} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
}

double ctof(double c) { // converts Celsius to Fahrenheit
  if (c < -273.15)
    throw runtime_error("the temperature cannot be below absolute zero! (0K = -273.15c = -459.67F)");
  double f = (9.0 / 5) * c + 32;
  return f;
}

double ftoc(double f) { // converts Fahrenheit to Celcius
  if (f < -459.67)
    throw runtime_error("the temperature cannot be below absolute zero! (0K = -273.15c = -459.67F)");
  double c = (f - 32) * (5.0 / 9);
  return c;
}
