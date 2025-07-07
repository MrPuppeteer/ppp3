import std;
using namespace std;

constexpr char celsius {'C'};
constexpr char kelvin {'K'};
constexpr double absolute_zero {-273.15};
constexpr string prompt {": "};
constexpr char quit {'q'};

double ctok(double c);  // converts Celcius to Kelvin

double ktoc(double k);  // converts Kelvin to Celcius

bool user_quits();

void convert();

int main() try {
  cout << "Insert a temperature in Celcius or Kelvin to convert.\n"
       << "Format: Number followed by Unit\n"
       << "        Unit C for Celcius and K for Kelvin.\n"
       << "Insert q to exit the program\n";

  while (!cin.eof()) convert();
  if (cin.eof()) cout << "Bye, bye!\n";
} catch (exception &e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "Oops: unknown exception!\n";
  return 2;
}

double ctok(double c) { // converts Celsius to Kelvin
  if (c < absolute_zero)
    throw runtime_error("the temperature cannot be below absolute zero! (0K = -273.15c)");
  return c - absolute_zero;
}

double ktoc(double k) { // converts Kelvin to Celcius
  if (k < 0)
    throw runtime_error("the temperature cannot be below absolute zero! (0K = -273.15c)");
  return k + absolute_zero;
}

bool user_quits() {
  char tmp;
  cin >> tmp;
  if (tmp != quit) {
    cin.putback(tmp);
    return false;
  }
  return true;
}

void convert() try {
  cout << prompt;
  if (user_quits()) {
    cin.setstate(cin.eofbit);
    return;
  }

  double degrees;
  char unit;
  
  if (cin >> degrees >> unit) {
    switch (unit) {
    case celsius:
      cout << degrees << " °C is equivalent to " << ctok(degrees) << "K\n";
      break;
    case kelvin:
      cout << degrees << " K is equivalent to " << ktoc(degrees) << " °C\n";
      break;
    default:
      throw runtime_error("unrecognized temperature unit.");
    }
  } else {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    throw runtime_error("bad input format.");
  }
} catch (exception& e) {
  cout << "Error: " << e.what() << '\n';
}
