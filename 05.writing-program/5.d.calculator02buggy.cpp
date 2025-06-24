import std;
using namespace std;

/*
 * errors:
 * 1. lass -> class
 * 2. Token get() -> Token Token_stream::get()
 * 3. missing closing "
 * 4. term( -> term()
 * 5. missing variable val
 *
 * logic errors:
 * 1. missing case 8
 * 2. missing break;
 * 3. + instead of -
 */

// e1. error: lass -> class
class Token {
public:
  char kind;                             // what kind of token
  double value;                          // for numbers: a value
  Token(char k) : kind{k}, value{0.0} {} // make a Token from a char
  Token(char k, double v)
      : kind{k}, value{v} {} // make a Token from a char and a double
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

// e2. error: Token get() -> Token Token_stream::get()
Token Token_stream::get() {
  if (full) {     // do we already have a Token ready?
    full = false; // remove token from buffer
    return buffer;
  }

  char ch;
  cin >> ch;

  switch (ch) {
  // change print command from ; to =
  case '=': // for "print"
  // change exit command from q to x
  case 'x': // for "quit"
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
  // l1. logic error: missing case 8
  case '8':
  case '9': {
    cin.putback(ch); // put digit back into the input stream
    double val;
    cin >> val;             // read a floating-point number
    return Token{'8', val}; // let '8' represent "a number"
  }
  default:
    throw runtime_error("Bad token");
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
    // e3. error: missing closing "
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
  Token t = ts.get(); // get the next token from token stream

  while (true) {
    switch (t.kind) {
    case '*':
      left *= primary();
      t = ts.get();
      // l2. logic error: missing break;
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
      ts.putback(t); // put t back into the token stream
      return left;
    }
  }
}

double expression() { // deal with + and -
  // e4. error: term( -> term()
  double left = term(); // read and evaluate a Term
  Token t = ts.get();   // get the next token from token stream

  while (true) {
    switch (t.kind) {
    case '+':
      left += term(); // evaluate Term and add
      t = ts.get();
      break;
    case '-':
      // l3. logic error: + instead of -
      left -= term(); // evaluate Term and subtract
      t = ts.get();
      break;
    default:
      ts.putback(t); // put t back into the token stream
      return left;   // finally: no more + or -: return the answer
    }
  }
}

int main() try {
  // e5. error: missing variable val
  double val = 0;

  cout << "Welcome to our simple calculator.\n"
       << "Please enter expressions using floating-point numbers.\n"
       << "Currently +, -, *, /, and () are supported.\n"
       << "Insert = to evaluate the expression. Enter x to exit.\n";

  while (cin) {
    Token t = ts.get();

    if (t.kind == 'x')
      break;           // 'x' for quit
    if (t.kind == '=') // '=' for "print now"
      cout << "=" << val << '\n';
    else {
      ts.putback(t);
      val = expression();
    }
  }
} catch (exception &e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "Oops: unknown exception!\n";
  return 2;
}
