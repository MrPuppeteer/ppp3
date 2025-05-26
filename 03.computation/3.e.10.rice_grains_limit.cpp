import std;
using namespace std;

// int rice limit at 31 iter. Overflow at 32 iter (get -1 value).
// double rice limit at 1023 iter. At 1024 iter, get infinity value.
int main() {
  int rice = 1;
  int square_rice = 1;
  double drice = 1;
  double dsquare_rice = 1;

  for (int square = 1; square <= 1024; ++square) {
    cout << "Square: " << square << '\n'
         << "\tTotal Rice (int): " << rice << '\n'
         << "\tTotal Rice (double): " << drice << '\n';

    square_rice *= 2;
    dsquare_rice *= 2;
    rice += square_rice;
    drice += dsquare_rice;
  }
}
