import std;
using namespace std;

/*
 * bitwise logical expression grammar:
 * or_expr:
 *   xor_expr
 *   or_expr "|" xor_expr
 * xor_expr:
 *   and_expr
 *   xor_expr "^" and_expr
 * and_expr:
 *   unary_expr
 *   and_expr "&" unary_expr
 * unary_expr:
 *   primary
 *   "~" unary_expr
 *   "!" unary_expr
 * primary:
 *   integer
 *   "(" or_expr ")"
 * integer:
 *   integer-literal
 */

class Token {
public:
  char kind;
  int value;
  Token(char k) : kind{k}, value{0} {}
  Token(char k, int v) : kind{k}, value{v} {}
};

class Token_stream {
public:
  Token get();
  void putback(Token t);
private:
  bool full = false;
  Token buffer = 0;
};

void Token_stream::putback(Token t) {
  if (full) throw runtime_error("putback() into a full buffer");
  buffer = t;
  full = true;
}

Token Token_stream::get() {
  if (full) {
    full = false;
    return buffer;
  }

  char ch;
  cin >> ch;
  
  switch (ch) {
  case '=':
  case 'x':
  case '(':
  case ')':
  case '!':
  case '~':
  case '&':
  case '|':
  case '^':
    return Token{ch};
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
    cin.putback(ch);
    int val;
    cin >> val;
    return Token{'8', val};
  }
  default:
    throw runtime_error("Bad token");
  }
}

Token_stream ts;
int or_expr();

int primary() {
  Token t = ts.get();
  switch (t.kind) {
  case '(': {
    int i = or_expr();
    t = ts.get();
    if (t.kind != ')') throw runtime_error("')' expected");
    return i;
  }
  case '8':
    return t.value;
  default:
    throw runtime_error("primary expected");
  }
}

int unary_expr() {
  Token t = ts.get();
  
  switch (t.kind) {
  case '~':
    return ~unary_expr();
  case '!':
    return !unary_expr();
  default:
    ts.putback(t);
    return primary();
  }
}

int and_expr() {
  int left = unary_expr();
  Token t = ts.get();
  while (true) {
    switch (t.kind) {
    case '&':
      left &= unary_expr();
      t = ts.get();
      break;
    default:
      ts.putback(t);
      return left;
    }
  }
}

int xor_expr() {
  int left = and_expr();
  Token t = ts.get();
  while (true) {
    switch (t.kind) {
    case '^':
      left ^= and_expr();
      t = ts.get();
      break;
    default:
      ts.putback(t);
      return left;
    }
  }
}

int or_expr() {
  int left = xor_expr();
  Token t = ts.get();
  while (true) {
    switch (t.kind) {
    case '|':
      left |= xor_expr();
      t = ts.get();
      break;
    default:
      ts.putback(t);
      return left;
    }
  }
}

int main()
try {
  int val = 0;

  cout << "Welcome to our bitwise calculator\n"
       << "Please enter expressions using integers and |, ^, &, ~, and ! operators.\n"
       << "Use = to evaluate the expression and x to exit.\n";

  while (cin) {
    Token t = ts.get();
    if (t.kind == 'x') break;
    if (t.kind == '=') cout << '=' << val << '\n';
    else {
      ts.putback(t);
      val = or_expr();
    }
  }
} catch (exception &e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "Oops: unknown exception!\n";
  return 2;
}
