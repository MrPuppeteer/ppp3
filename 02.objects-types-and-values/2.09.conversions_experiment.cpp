// Conversions from double to int and from int to char
import std;
using namespace std;

int main() {
  double d = 0;
  while (cin>>d) {  // repeat the statements below as long as we type in numbers
    int i = d;      // try to squeeze a floating-point value into an integer
    char c = i;     // try to squeeze an integer into a char
    cout << "d==" << d                // the original double
         << " i==" << i                // double converted to int
         << " c==" << c                // int value of char
         << " char(" << c << ")\n";   // the char
  }
}
