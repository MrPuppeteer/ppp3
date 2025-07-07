/*
  Simple calculator

  Revision history:

  Revised by Bjarne Stroustrup (bjarne@stroustrup.com) November 2023
  Revised by Bjarne Stroustrup November 2013
  Revised by Bjarne Stroustrup May 2007
  Revised by Bjarne Stroustrup August 2006
  Revised by Bjarne Stroustrup August 2004
  Originally written by Bjarne Stroustrup (bs@cs.tamu.edu) Spring 2004.

  This program implements a basic expression calculator.
  Input from cin; output to cout.
  The grammar for input is:

  Statement:
    Expression
    Print
    Quit
  Print:
    ";"
  Quit:
    "q"
  Expression:
    Term
    Expression "+" Term
    Expression "-" Term
  Term:
    Primary
    Term "*" Primary
    Term "/" Primary
    Term "%" Primary
  Primary:
    Number
    "(" Expression ")"
    "-" Primary
    "+" Primary
  Number:
    floating-point-literal

  Input comes from cin through the Token_stream called ts.
*/

import std;
using namespace std;

constexpr char number = '8'; // t.kind==number means that t is a number Token
constexpr char quit = 'q';   // t.kind==quit means that t is a quit Token
constexpr char print_token = ';';  // t.kind==print means that t is a print Token
constexpr string prompt = "> ";
constexpr string result = "= "; // used to indicate that what follows is a result

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
  void ignore(char c);   // discard characters up to and including a c
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

Token Token_stream::get() { // read characters from cin and compose a Token
  if (full) {               // check if we already have a Token ready
    full = false;
    return buffer;
  }
  char ch;
  cin >> ch; // note that >> skips whitespace (space, newline, tab, etc.)

  switch (ch) {
  case print_token:
  case quit:
  case '(':
  case ')':
  case '+':
  case '-':
  case '*':
  case '/':
  case '%':
    return Token{ch}; // let each character represent itself
  case '.':           // a floating-point-literal can start with a dot
  case '0': case '1': case '2': case '3': case '4':
  case '5': case '6': case '7': case '8': case '9': // numeric literals
  {
    cin.putback(ch); // put digit back into the input stream
    double val;
    cin >> val; // read floating-point number
    return Token{number, val};
  }
  default:
    throw runtime_error("Bad Token");
  }
}

void Token_stream::ignore(char c) { // c represents the kind of Token
  if (full && c==buffer.kind) {     // first look in buffer
    full = false;
    return;
  }
  full = false;

  // now search input:
  char ch = 0;
  while (cin>>ch)
    if (ch==c)
      return;
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
  case number:
    return t.value; // return the number's value
  case '-':
    return -primary();
  case '+':
    return primary();
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
    case '%': {
      double d =primary();
      if (d == 0)
        throw runtime_error("%: divide by zero");
      left = fmod(left,d);
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

void clean_up_mess() {
  ts.ignore(print_token);
}

void calculate() { // expression evaluation loop
  while (cin) try {
    cout << prompt;
    Token t = ts.get();
    while (t.kind == print_token)
      t = ts.get(); // first discard all "prints"
    if (t.kind == quit)
      return;
    ts.putback(t);
    cout << result << expression() << '\n';
  } catch (exception& e) {
    cerr << e.what() << '\n'; // write error message
    clean_up_mess();
  }
}

int main() try {
  calculate();
  return 0;
} catch (exception &e) {
  cerr << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "exception \n";
  return 2;
}
