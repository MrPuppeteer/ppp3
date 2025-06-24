import std;
using namespace std;

class Token {
public:
  char kind;                                    // what kind of token
  double value;                                 // for numbers: a value
  Token(char k) :kind{k}, value{0.0}{}          // construct from one value
  Token(char k, double v) :kind{k}, value{v}{}  // construct from two values
};

int main() {
  Token t1 {'+'};       // initialize t1 so that t1.kind = '+'
  Token t2 {'8',11.5};  // initialize t2 so that t2.kind = '8' and t2.value = 11.5
  // Token t3;          // error: initializer missing for t3
}
