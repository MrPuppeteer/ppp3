import std;
using namespace std;

int square(int x);

void write_sorry();

int main() {
  cout << square(2) << ' ' << square(10) << '\n'; // print 4 100

  square(2);              // probably a mistake: unused return value
  int v1 = square();      // error: argument missing
  int v2 = square;        // error: parentheses missing
  int v3 = square(1,2);   // error: too many arguments
  int v4 = square("two"); // error: wrong type of argument; int expected

  write_sorry();
}

// return the square of x
int square(int x) {
  return x*x;
}

// take no argument; return no value
void write_sorry() {
  cout << "Sorry\n";
}
