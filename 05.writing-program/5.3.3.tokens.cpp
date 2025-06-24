import std;
using namespace std;

class Token {   // a very simple user-defined type
public:
  char kind;
  double value;
};

int main() {
  Token t;          // t is a Token
  t.kind = '+';     // t represents a +
  Token t2;         // t2 is another Token
  t2.kind = '8';    // we use the digit 8 as the "kind" for numbers
  t2.value = 3.14;
}
