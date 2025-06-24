import std;
using namespace std;

class Token {
public:
  char kind;                                    // what kind of token
  double value;                                 // for numbers: a value
  Token(char k) :kind{k}, value{0.0}{}          // construct from one value
  Token(char k, double v) :kind{k}, value{v}{}  // construct from two values
};

Token get_token();    // read characters and compose tokens
double expression();  // deal with + and -
double term();        // deal with *, /, and %
double primary();     // deal with numbers and parentheses

int main() {}

double expression() {
  double left = expression(); // read and evaluate an Expression
  Token t = get_token();      // get the next token
  switch (t.kind) {           // see which kind of token it is
  case '+':
    return left + term();     // read and evaluate a Term, then do an add
  case '-':
    return left - term();     // read and evaluate a Term, then do a subtraction
  default:
    return left;              // return the value of the Expression
  }
}
