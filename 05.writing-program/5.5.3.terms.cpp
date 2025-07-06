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

double term() {
  double left = primary();
  Token t = get_token();
  while (true) {
    switch (t.kind) {
    case '*':
      left *= primary();
      t = get_token();
      break;
    case '/': {
      double d = primary();
      if (d == 0)
        throw runtime_error("divide by zero");
      left /= d;
      t = get_token();
      break;
    }
    // case '%':
    //   left %= primary();
    //   t = get_token();
    //   break;
    default:
      return left;
    }
  }
}
