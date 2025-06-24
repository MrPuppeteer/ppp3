import std;
using namespace std;

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
  case '{':
  case '}':
  case '+':
  case '-':
  case '*':
  case '/':
  case '!':
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
    cin >> val;             // read a floating-point number
    return Token{'8', val}; // let '8' represent "a number"
  }
  default:
    throw runtime_error("Bad token");
  }
}

Token_stream ts;     // provides get() and putback()
double expression(); // declaration so that primary() can call expression()

// note: while factorial is defined only for ints, the results grows very large and very fast
// so it returns a double, only the input is defined as int
double factorial(int n) {
  if (n < 0)
    throw runtime_error("cannot use factorial with negative number");
  if (n == 0) return 1;

  double f = 1.0;
  for (int i = 1; i <= n; ++i) f *= i;

  return f;
}

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
  case '{': { // handle '{' expression '}'
    double d = expression();
    t = ts.get();
    if (t.kind != '}')
      throw runtime_error("'}' expected");
    return d;
  }
  case '8':         // we use '8' to represent a number
    return t.value; // return the number's value
  default:
    throw runtime_error("primary expected");
  }
}

double factor() {
  double left = primary();
  Token t = ts.get();

  switch (t.kind) {
  case '!': {
    if (left < 0 || left != static_cast<int>(left))
      throw runtime_error("factorial is only defined for non-negative integers");
    return factorial(static_cast<int>(left));
  }
  default:
    ts.putback(t);
    return left;
  }
}

double term() { // deal with *, /, and %
  double left = factor();
  Token t = ts.get(); // get the next token from token stream

  while (true) {
    switch (t.kind) {
    case '*':
      left *= factor();
      t = ts.get();
      break;
    case '/': {
      double d = factor();
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

double expression() {   // deal with + and -
  double left = term(); // read and evaluate a Term
  Token t = ts.get();   // get the next token from token stream

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
      ts.putback(t); // put t back into the token stream
      return left;   // finally: no more + or -: return the answer
    }
  }
}

int main() try {
  double val = 0;

  cout << "Welcome to our simple calculator.\n"
       << "Please enter expressions using floating-point numbers.\n"
       << "Currently +, -, *, /, (), {}, and ! are supported.\n"
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
