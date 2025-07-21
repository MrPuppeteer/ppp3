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
  Input from is; output to cout.
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

  Input comes from is through the Token_stream called ts.
*/

import std;
using namespace std;

constexpr char number = '8'; // t.kind==number means that t is a number Token
constexpr char quit = 'q';   // t.kind==quit means that t is a quit Token
constexpr char print_token = ';';  // t.kind==print means that t is a print Token

constexpr char name = 'a';        // name token
constexpr char let = 'L';         // declaration token
constexpr string declkey = "let"; // declaration keyword

constexpr string prompt = "> ";
constexpr string result = "= "; // used to indicate that what follows is a result

class Token {
public:
  char kind;
  double value;
  string name;
  Token() :kind{0} {}                                 // default constructor
  Token(char ch) :kind{ch} {}                         // initialize ind with ch
  Token(char ch, double val) :kind{ch}, value{val} {} // initialize kind and value
  Token(char ch, string n) :kind{ch}, name{n} {}      // initialize kind and name
};

class Token_stream {
public:
  Token_stream(istream& s) :is{s} {}  // initialize
  Token get();           // get a Token
  void putback(Token t); // put a Token back
  void ignore(char c);   // discard characters up to and including a c
private:
  bool full = false; // is there a Token in the buffer?
  Token buffer = 0;  // where we store a 'putback' Token
  istream& is;       // the input stream we read from
};

void Token_stream::putback(Token t) {
  if (full)
    throw runtime_error("putback() into a full buffer");
  buffer = t;  // copy t to buffer
  full = true; // buffer is now full
}

Token Token_stream::get() { // read characters from is and compose a Token
  if (full) {               // check if we already have a Token ready
    full = false;
    return buffer;
  }
  char ch;
  is >> ch; // note that >> skips whitespace (space, newline, tab, etc.)

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
  case '=':
    return Token{ch}; // let each character represent itself
  case '.':           // a floating-point-literal can start with a dot
  case '0': case '1': case '2': case '3': case '4':
  case '5': case '6': case '7': case '8': case '9': // numeric literals
  {
    is.putback(ch); // put digit back into the input stream
    double val;
    is >> val; // read floating-point number
    return Token{number, val};
  }
  default:
    if (isalpha(ch)) {
      string s;
      s+=ch;
      while (is.get(ch) && (isalpha(ch) || isdigit(ch)))
        s+=ch;
      is.putback(ch);
      if (s == declkey)
        return Token{let};  // declaration keyword
      return Token{name,s};
    }
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
  while (is>>ch)
    if (ch==c)
      return;
}

class Variable {
public:
  string name;
  double value;
};

vector<Variable> var_table;

double get_value(string s) { // return the value of the Variable named s
  for (const Variable& v : var_table)
    if (v.name == s)
      return v.value;
  throw runtime_error("trying to read undefined variable " + s);
}

void set_value(string s, double d) {  // set the Variable named s to d
  for (Variable& v : var_table)
    if (v.name == s) {
      v.value = d;
      return;
    }
  throw runtime_error("trying to write undefined variable " + s);
}

bool is_declared(string var) {  // is var already in var_table?
  for (const Variable& v : var_table)
    if (v.name == var)
      return true;
  return false;
}

double define_name(string var, double val) {  // add {var,val} to var_table
  if (is_declared(var))
    throw runtime_error(var + " declared twice");
  var_table.push_back(Variable{var,val});
  return val;
}

// Token_stream ts;     // provides get() and putback()
double expression(Token_stream& ts); // declaration so that primary() can call expression()

double primary(Token_stream& ts) { // deal with numbers and parentheses
  Token t = ts.get();
  switch (t.kind) {
  case '(': { // handle '(' expression ')'
    double d = expression(ts);
    t = ts.get();
    if (t.kind != ')')
      throw runtime_error("')' expected");
    return d;
  }
  case number:
    return t.value; // return the number's value
  case name:
    return get_value(t.name);
  case '-':
    return -primary(ts);
  case '+':
    return primary(ts);
  default:
    throw runtime_error("primary expected");
  }
}

double term(Token_stream& ts) { // deal with *, /, and %
  double left = primary(ts);
  Token t = ts.get();
  while (true) {
    switch (t.kind) {
    case '*':
      left *= primary(ts);
      t = ts.get();
      break;
    case '/': {
      double d = primary(ts);
      if (d == 0)
        throw runtime_error("divide by zero");
      left /= d;
      t = ts.get();
      break;
    }
    case '%': {
      double d = primary(ts);
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

double expression(Token_stream& ts) {   // deal with + and -
  double left = term(ts); // read and evaluate an Term
  Token t = ts.get();   // get the next token

  while (true) {
    switch (t.kind) {
    case '+':
      left += term(ts); // evaluate Term and add
      t = ts.get();
      break;
    case '-':
      left -= term(ts); // evaluate Term and subtract
      t = ts.get();
      break;
    default:
      ts.putback(t);
      return left; // finally: no more + or -; return the answer
    }
  }
}

double declaration(Token_stream& ts) {  // assume we have seen "let"
                        // handle: name = expression
                        // declare a variable called "name" with the initial value "expression"
  Token t = ts.get();
  if (t.kind != name)
    throw runtime_error("name expected in declaration");

  Token t2 = ts.get();
  if (t2.kind != '=')
    throw runtime_error("= missing in declaration of " + t.name);
  double d = expression(ts);
  define_name(t.name,d);
  return d;
}

double statement(Token_stream& ts) {
  Token t = ts.get();
  switch (t.kind) {
  case let:
    return declaration(ts);
  default:
    ts.putback(t);
    return expression(ts);
  }
}

void clean_up_mess(Token_stream& ts) {
  ts.ignore(print_token);
}

void calculate(istream& is) { // expression evaluation loop
  Token_stream ts{is};  // Token_stream read from the provided istream
  while (is) try {
    cout << prompt;
    Token t = ts.get();
    while (t.kind == print_token)
      t = ts.get(); // first discard all "prints"
    if (t.kind == quit)
      return;
    ts.putback(t);
    cout << result << statement(ts) << '\n';
  } catch (exception& e) {
    cerr << e.what() << '\n'; // write error message
    clean_up_mess(ts);
  }
}

int main() try {
  // predefine names:
  define_name("pi",3.1415926535);
  define_name("e",2.7182818284);

  calculate(cin);
  return 0;
} catch (exception &e) {
  cerr << e.what() << endl;
  return 1;
} catch (...) {
  cerr << "exception " << endl;
  return 2;
}
