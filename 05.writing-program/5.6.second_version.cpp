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

int main()
try {
  while (cin)
    cout << "=" << expression() << '\n';  // version 2: '=' added
} catch (exception& e) {
  cerr << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "exception \n";
  return 2;
}

Token get_token() {
  char ch;
  cin >> ch;

  switch (ch) {
  case '(': case ')': case '+': case '-': case '*': case '/':
    return Token(ch);
  case '.':
  case '0': case '1': case '2': case '3': case '4':
  case '5': case '6': case '7': case '8': case '9':
  {
    cin.putback(ch);
    double val;
    cin >> val;
    return Token('8', val);
  }
  default:
    throw runtime_error("Bad token");
  }
}

double expression() {
  double left = term();   // read and evaluate an Term
  Token t = ts.get();     // get the next token

  while (true) {
    switch (t.kind) {
    case '+':
      left += term();     // evaluate Term and add
      t = ts.get();
      break;
    case '-':
      left -= term();     // evaluate Term and subtract
      t = ts.get();
      break;
    default:
      ts.putback(t);
      return left;        // finally: no more + or -; return the answer
    }
  }
}

double term() {
  double left = primary();
  Token t = ts.get();
  while (true) {
    switch (t.kind) {
    case '*':
      left *= primary();
      t = ts.get();
      break;
    case '/': {
      double d = primary();
      if (d == 0)
        throw runtime_error("divide by zero");
      left /= d;
      t = ts.get();
      break;
    }
    default:
      ts.putback(t);
      return left;
    }
  }
}

double primary() {
  Token t = ts.get();
  switch (t.kind) {
  case '(': {         // handle '(' expression ')'
    double d = expression();
    t = ts.get();
    if (t.kind != ')')
      throw runtime_error("')' expected");
    return d;
  }
  case '8':           // we use '8' to represent a number
    return t.value;   // return the number's value
  default:
    throw runtime_error("primary expected");
  }
}
