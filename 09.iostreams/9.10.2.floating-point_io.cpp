import std;
using namespace std;

int main() {
  constexpr double d = 1234.56789;

  cout << "format: " << d << " - "  // use the default format for d
       << hexfloat << d << " - "  // use hexadecimal notation for d
       << scientific << d << " - " // use 1.123e2 style format for d
       << fixed << d << " - " // use 123.456 style format for d
       << defaultfloat << d << '\n';  // use the default format for d
  
  cout << "precision: " << d << " - " << setprecision(8) << d << " - " << setprecision(16) << d << '\n';

  cout << "width: " << d << " - " << setw(8) << d << " - " << setw(16) << d << '\n';
}
