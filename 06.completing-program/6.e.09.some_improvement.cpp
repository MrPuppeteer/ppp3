/*
  Simple calculator

  This program implements a basic expression calculator.
  Input from cin; output to cout.
  The grammar for input is:

  Calculation:
    Statement
    Command
    Print
    Calculation Statement
  Statement:
    Declaration
    Assignment
    Expression
  Command:
    "help"
    "symbols"
    "quit"
  Print:
    ";"
    "\n"
  Declaration:
    "let" Name "=" Expression
    "const" Name "=" Expression
  Assignment:
    Name "=" Expression
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
    Name
    Function"("Arguments")"
  Function:
    "sqrt"
    "pow"
  Arguments:
    Expression
    Argument","Expression
  Number:
    floating-point-literal
  Name:
    "_"
    [alphabetic-char]
    Name[alphabetic-char]
    Name[digit-char]
    Name"_"

  Input comes from cin through the Token_stream called ts.
*/

import std;
using namespace std;

// Token are initialized depending on the needs of each kind
struct Token {
	char kind;
	double value;
	string name;

  Token() :kind{0} {}
	Token(char ch) :kind{ch} {}
	Token(char ch, double val) :kind{ch}, value{val} {}
  Token(char ch, string n) :kind{ch}, name{n} {}
};

class Token_stream {
public:
	Token get();
	void putback(Token t);
	void ignore(char c);
private:
  vector<Token> buffer;
};

void Token_stream::putback(Token t) {
  buffer.push_back(t);
}

// Token kinds
constexpr char let = 'l';
constexpr char constant = 'c';
constexpr char command = '#';
constexpr char print_token = ';';
constexpr char number = '8';
constexpr char name = 'a';
constexpr char sqrtfunc = 's';
constexpr char powfunc = 'p';
// Keywords
constexpr string helpkey = "help";
constexpr string symkey = "symbols";
constexpr string quitkey = "quit";
constexpr string letkey = "let";
constexpr string constkey = "const";
// Builtin functions
constexpr string sqrtkey = "sqrt";
constexpr string powkey = "pow";

// get literals from the implemented grammar
Token Token_stream::get() {
	// if (full) { full = false; return buffer; }

  if (!buffer.empty()) {
    Token t = buffer.back();
    buffer.pop_back();
    return t;
  }

	char ch = ' ';
  while (isspace(ch) && ch != '\n')
    ch = cin.get();
	
  switch (ch) {
	case print_token:
  case '\n':
    return Token{print_token};
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '=': // symbol literals
  case ',': // separator for function argument
		return Token{ch};
	case '.': // a floating-point-literal can start with a dot
  case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9': // numeric literals
	{
    cin.putback(ch);
	  double val;
	  cin >> val;
	  return Token{number, val};
	}
	default:
		if (isalpha(ch) || ch == '_') {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
			cin.putback(ch);
			if (s == letkey) return Token{let};
			if (s == constkey) return Token{constant};
			if (s == helpkey) return Token{command, helpkey};
			if (s == symkey) return Token{command, symkey};
			if (s == quitkey) return Token{command, quitkey};
      if (s == sqrtkey) return Token{sqrtfunc};
      if (s == powkey) return Token{powfunc};
			return Token{name, s};
		}
		throw runtime_error("Bad token");
	}
}

// clear input until c is found
void Token_stream::ignore(char c) {
	// if (full && c == buffer.kind) {
	// 	full = false;
	// 	return;
	// }
	// full = false;

  while (!buffer.empty() && buffer.back().kind != c)
    buffer.pop_back();

  if (!buffer.empty()) return;

	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;
}

class Variable {
public:
	string name;
	double value;
  bool constant;
};

class Symbol_table {
public:
  double get(string s);
  void set(string s, double d);
  bool is_declared(string s);
  double declare(string s, double d, bool c);
  void print();
private:
  vector<Variable> var_table;
};

double Symbol_table::get(string s) {
  for (const Variable& v : var_table)
    if (v.name == s)
      return v.value;
  throw runtime_error("trying to read undefined variable " + s);
}

void Symbol_table::set(string s, double d) {
  for (Variable& v : var_table)
    if (v.name == s) {
      if (v.constant) throw runtime_error(s + " is a constant");
      v.value = d;
      return;
    }
  throw runtime_error("trying to write undefined variable " + s);
}

bool Symbol_table::is_declared(string s) {
  for (const Variable& v : var_table)
    if (v.name == s)
      return true;
  return false;
}

double Symbol_table::declare(string s, double d, bool c = false) {
  if (is_declared(s))
    throw runtime_error(s + " declared twice");
  var_table.push_back(Variable{s,d,c});
  return d;
}

void Symbol_table::print() {
  for (Variable v : var_table) {
    cout << v.name << " = " << v.value;
    if (v.constant) cout << " (constant)";
    cout << '\n';
  }
}

Symbol_table symbols;
Token_stream ts;

double expression();

// Evaluates function of kind c. The next input must be "("Expression")"
double func(char c) {
  vector<double> args;  // store function Arguments

  Token t = ts.get();
  if (t.kind != '(') throw runtime_error("'(' expected after function");

  switch (c) {
  case sqrtfunc:
    args.push_back(expression());
    break;
  case powfunc:
    args.push_back(expression());
    t = ts.get();
    if (t.kind != ',') throw runtime_error("Bad number of function arguments");
    args.push_back(expression());
    break;
  }

  t = ts.get();
  if (t.kind != ')') throw runtime_error("Bad number of function arguments");

  // Implement evaluation & restrictions
  switch (c) {
  case sqrtfunc:
    if (args[0] < 0) throw runtime_error("sqrt() is undefined for negative numbers");
    return sqrt(args[0]);
  case powfunc:
    return pow(args[0], static_cast<int>(args[1]));
  default:
    throw runtime_error("Function not implemented yet");
  }
}

double primary() {
	Token t = ts.get();
	switch (t.kind) {
	case '(': {
    double d = expression();
	  t = ts.get();
	  if (t.kind != ')') throw runtime_error("'(' expected");
    return d;
	}
	case '-':
		return -primary();
  case '+':
    return primary();
	case number:
		return t.value;
	case name:
		return symbols.get(t.name);
  case sqrtfunc: case powfunc:
    return func(t.kind);
	default:
		throw runtime_error("primary expected");
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
		  if (d == 0) throw runtime_error("divide by zero");
		  left /= d;
      t = ts.get();
		  break;
		}
    case '%': {
      double d =primary();
      if (d == 0)
        throw runtime_error("%: divide by zero");
      left = fmod(left, d);
      t = ts.get();
      break;
    }
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression() {
	double left = term();
  Token t = ts.get();

	while (true) {
		switch (t.kind) {
		case '+':
			left += term();
      t = ts.get();
			break;
		case '-':
			left -= term();
      t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double assignment() {
  Token t = ts.get();
  string var_name = t.name;
  if (!symbols.is_declared(var_name)) throw runtime_error(var_name + " has not been declared");

  ts.get(); // get rid of the "="
  double d = expression();
  symbols.set(var_name, d);
  return d;
}

double declaration() {
  bool is_const = false;
	Token t = ts.get();
  if (t.kind == constant) is_const = true;

	Token t2 = ts.get();
	if (t2.kind != name) throw runtime_error("name expected in declaration");

	string var_name = t2.name;
	if (symbols.is_declared(var_name)) throw runtime_error(var_name + " declared twice");

	Token t3 = ts.get();
	if (t3.kind != '=') throw runtime_error("= missing in declaration of " + var_name);
  
	double d = expression();
  symbols.declare(var_name,d,is_const);
	return d;
}

double statement() {
	Token t = ts.get();
	switch (t.kind) {
	case let:
  case constant:
    ts.putback(t);
		return declaration();
  case name: {
    Token t2 = ts.get();
    ts.putback(t2);
    ts.putback(t);
    if (t2.kind == '=') {
      return assignment();
    }
    return expression();
  }
	default:
		ts.putback(t);
		return expression();
	}
}

void clean_up_mess() {
	ts.ignore(print_token);
}

void print_help() {
  cout << "\nCalculator help.\n"
       << "\n\tBASIC SYNTAX\n\n"
       << "\tFinish an expression with ; or new line to print results.\n"
       << "\tSupported operands: *, /, %, +, -, = (assignment).\n"
       << "\tYou can use parenthesis to group expression: 4*(2+3).\n"
       << "\n\tCOMMANDS\n\n"
       << "\thelp     Prints this help message.\n"
       << "\tsymbols  Prints currently declared variables and constants.\n"
       << "\tquit     Exit the program.\n"
       << "\n\tBUILT-IN FUNCTIONS\n\n"
       << "\tsqrt(n)  Square root of n.\n"
       << "\tpow(n,e) e power of n, with e an integer number.\n"
       << "\n\tVARIABLES\n\n"
       << "\tVariable names must be composed of alphanumeric characters and '_',\n"
       << "\tand must start with an alphabetic character or '_'.\n\n"
       << "\tlet var = expr   Declares a variable var and initializes it\n"
       << "\t                 with expr expression evaluation value.\n\n"
       << "\tconst var = expr Declares and initializes a constant named var.\n\n"
       << "\tvar = expr       Assigns a new value to a previously declared\n"
       << "\t                 variable.\n\n"
       << "\tPredefined variables:\n"
       << "\t\tpi 3.14159265359 (constant)\n"
       << "\t\te  2.71828182846 (constant)\n"
       << "\t\tk  1000\n\n";
}

const string prompt = "> ";
const string result = "= ";

void calculate() {
	while (cin) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print_token) t = ts.get();
    if (t.kind == command) {
      if (t.name == quitkey) return;
      if (t.name == helpkey) print_help();
      if (t.name == symkey) symbols.print();
      ts.ignore(print_token); // Ignore whatever comes after a command
    } else {
		  ts.putback(t);
		  cout << result << statement() << '\n';
    }
	} catch (exception& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main() try {
  // predefined variable and constant names
  symbols.declare("k", 1000);
  symbols.declare("pi", 3.14159265359, true);
  symbols.declare("e", 2.71828182846, true);

  cout << "Welcome to calculator. Write help; for ... help.\n";
	calculate();
	return 0;
} catch (exception& e) {
	cerr << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "exception\n";
	return 2;
}
