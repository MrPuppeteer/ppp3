import std;
using namespace std;

class Token {
public:
  char kind;                                     // what kind of token
  double value;                                  // for numbers: a value
  Token(char k) : kind{k}, value{0.0} {}         // construct from one value
  Token(char k, double v) : kind{k}, value{v} {} // construct from two values
};

class Token_stream {
public:
  Token get();           // get a Token
  void putback(Token t); // put a Token back
private:
  bool full = false; // is there a Token in the buffer?
  Token buffer = 0;  // where we store a 'putback' Token
};

void Token_stream::putback(Token t) {
  if (full)
    throw runtime_error("putback() into a full buffer");
  buffer = t;  // copy t to buffer
  full = true; // buffer is now full
}

Token Token_stream::get() {
  if (full) {     // do we already have a Token ready?
    full = false; // remove Token from buffer
    return buffer;
  }
  char ch;
  cin >> ch;

  switch (ch) {
  case ';': // for "print"
  case 'q': // for "quit"
  case '(':
  case ')':
  case '+':
  case '-':
  case '*':
  case '/':
    return Token{ch}; // let each character represent itself
  case '.':
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9': {
    cin.putback(ch); // put digit back into the input stream
    double val;
    cin >> val;             // read floating-point number
    return Token{'8', val}; // let '8' represent "a number"
  }
  default:
    throw runtime_error("Bad Token");
  }
}

Token_stream ts;     // provides get() and putback()
double expression(); // declaration so that primary() can call expression()

double primary() { // deal with numbers and parentheses
  Token t = ts.get();
  switch (t.kind) {
  case '(': { // handle '(' expression ')'
    double d = expression();
    t = ts.get();
    if (t.kind != ')')
      throw runtime_error("')' expected");
    return d;
  }
  case '8':         // we use '8' to represent a number
    return t.value; // return the number's value
  default:
    throw runtime_error("primary expected");
  }
}

double term() { // deal with *, /, and %
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

double expression() {   // deal with + and -
  double left = term(); // read and evaluate an Term
  Token t = ts.get();   // get the next token

  while (true) {
    switch (t.kind) {
    case '+':
      left += term(); // evaluate Term and add
      t = ts.get();
      break;
    case '-':
      left -= term(); // evaluate Term and subtract
      t = ts.get();
      break;
    default:
      ts.putback(t);
      return left; // finally: no more + or -; return the answer
    }
  }
}

int main() try {
  while (cin) {
    cout << "> ";
    Token t = ts.get();
    while (t.kind == ';')
      t = ts.get(); // eat ';'
    if (t.kind == 'q')
      return 0;
    ts.putback(t);
    cout << "= " << expression() << '\n';
  }
  return 0;
} catch (exception &e) {
  cerr << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "exception \n";
  return 2;
}
