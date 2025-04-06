// declaring a number of variables with legal and illegal names
import std;
using namespace std;

int main() {
  int x;                      // OK
  // int double = 0;          // error: cannot combile with previous 'int' declaration specifier
                              // error: expected unqualified-id
  // double throw;            // errror: expected unqualified-id
  // string _foobar;          // OK but never use names starting with underscores 
                              // these names are reserved for implementation and system entities
  // char 321num;             // error: expected unqualified-id
  // int time$to$market = 2;  // warning: '$' in identifier
  // bool is true;            // error: expected ';' at end of declaration
  // int lliioOo0oOoiill;     // OK but avoid long names, easy to mistype, misread, or confuse
}
