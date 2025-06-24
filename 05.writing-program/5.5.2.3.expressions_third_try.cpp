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
  double left = term();   // read and evaluate an Term
  Token t = get_token();  // get the next token

  // while (t.kind=='+' || t.kind=='-') {  // look for a + or a -
  //   if (t.kind == '+')
  //     left += term();                   // evaluate Term and add
  //   else
  //     left -= term();                   // evaluate Term and subtract
  //   t = get_token();
  // }
  // return left;                          // finally: no more + or -; return the answer

  while (true) {
    switch (t.kind) {
    case '+':
      left += term();     // evaluate Term and add
      t = get_token();
      break;
    case '-':
      left -= term();     // evaluate Term and subtract
      t = get_token();
      break;
    default:
      return left;        // finally: no more + or -; return the answer
    }
  }
}
