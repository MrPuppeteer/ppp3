import std;
using namespace std;

void print_square(int v);

int main() {
  for (int i = 0; i<100; ++i)
    print_square(i);
}

/* performs two logically separate actions:
 * it prints
 * it calculates a square
 *
 * It's easier to write and to understand if each function performs a single logical action
 */ 
void print_square(int v) {
  cout << v << '\t' << v*v << '\n';
}
