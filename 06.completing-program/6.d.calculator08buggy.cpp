/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

/*
  Simple calculator

  This program implements a basic expression calculator.
  Input from cin; output to cout.
  The grammar for input is:

  Calculation:
    Statement
    Print
    Quit
    Calculation Statement
  Statement:
    Declaration
    Expression
  Print:
    ";"
  Quit:
    "exit"
  Declaration:
    let Name "=" Expression
  let:
    "#"
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
    [alphabetic-char]
    Name[alphabetic-char]
    Name[digit-char]

  Input comes from cin through the Token_stream called ts.
*/

import std;
using namespace std;

// Token are initialized depending on the needs of each kind
struct Token {
	char kind;
	double value;
	string name;

  // add missing constructor
  Token() :kind{0} {}
	Token(char ch) :kind{ch} {}
	Token(char ch, double val) :kind{ch}, value{val} {}
  Token(char ch, string n) :kind{ch}, name{n} {}
};

class Token_stream {
public:
	Token get();
	void putback(Token t);  // rename unget function to putback
	void ignore(char c);  // fix missing variable name
private:  // make variable private and add default value
	bool full = false;
	Token buffer = 0;
};

void Token_stream::putback(Token t) {
  if (full)
    throw runtime_error("putback() into a full buffer");
  buffer = t;
  full = true;
}

// Token kinds
constexpr char let = '#';
constexpr char quit = 'q';  // change the value from uppercase to lowercase
constexpr char print_token = ';'; // fix ambigous reference
constexpr char number = '8';
constexpr char name = 'a';
constexpr char sqrtfunc = 's';
constexpr char powfunc = 'p';
// Keywords
constexpr string quitkey = "exit";
// Builtin functions
constexpr string sqrtkey = "sqrt";
constexpr string powkey = "pow";

// get literals from the implemented grammar
Token Token_stream::get() {
	if (full) { full = false; return buffer; }

	char ch;
	cin >> ch;
	
  switch (ch) {
	case print_token: // change from ';' to print_token for adapting if token value changes
  case let:
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
    cin.putback(ch);  // add missing ch
	  double val;
	  cin >> val;
	  return Token{number, val};
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;  // fix assigment
			cin.putback(ch);  // add missing ch
			if (s == quitkey) return Token{quit}; // change "quit" into quitkey to adapt changes
      if (s == sqrtkey) return Token{sqrtfunc};
      if (s == powkey) return Token{powfunc};
			return Token{name, s};
		}
		throw runtime_error("Bad token");
	}
}

// clear input until c is found
void Token_stream::ignore(char c) {
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch = 0;  // add default value, just in case
	while (cin >> ch)
		if (ch == c) return;
}

// change it from struct into class
class Variable {
public:
	string name;
	double value;
};

vector<Variable> var_table; // change names to var_table

double get_value(string s) {
  for (const Variable& v : var_table)
    if (v.name == s)
      return v.value;
  throw runtime_error("trying to read undefined variable " + s);
}

void set_value(string s, double d) {
  for (Variable& v : var_table)
    if (v.name == s) {
      v.value = d;
      return;
    }
  throw runtime_error("trying to write undefined variable " + s);
}

bool is_declared(string var) {
  for (const Variable& v : var_table)
    if (v.name == var)
      return true;
  return false;
}

// add define_name funtion
double define_name(string var, double val) {
  if (is_declared(var))
    throw runtime_error(var + " declared twice");
  var_table.push_back(Variable{var,val});
  return val;
}

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
    return pow(args[0], static_cast<int>(args[1])); // change narrow to static_cast
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
    return d; // fix missing return the result
	}
	case '-':
		return -primary();
  case '+': // add missing positive
    return primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
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
    case '%': { // add missing % operation
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

double declaration() {
	Token t = ts.get();
  // change 'a' to name to adapt name token value changes
	if (t.kind != name) throw runtime_error("name expected in declaration");

	string var_name = t.name; // change name to var_name
	if (is_declared(var_name)) throw runtime_error(var_name + " declared twice");

	Token t2 = ts.get();
	if (t2.kind != '=') throw runtime_error("= missing in declaration of " + var_name);
  
	double d = expression();
  define_name(var_name,d);
	return d;
}

double statement() {
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.putback(t);
		return expression();
	}
}

void clean_up_mess() {
	ts.ignore(print_token);
}

const string prompt = "> ";
const string result = "= ";

void calculate() {
	while (cin) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print_token) t = ts.get();
		if (t.kind == quit) return;
		ts.putback(t);
		cout << result << statement() << '\n';  // change endl to '\n' (preference)
	} catch (exception& e) {  // fix by changing runtime_error to exception
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main() try {
  // predefine names
  define_name("k", 1000);

	calculate();
	return 0;
} catch (exception& e) {
	cerr << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "exception\n";
	return 2;
}
