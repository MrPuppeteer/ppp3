import std;
using namespace std;

// double expression(Token_stream& ts);  // double is the result of calling expression(ts)
//
// auto expression(Token_stream& ts) -> double;  // call expression(ts) and get a double
//
// auto Token_stream::get() -> Token;
// auto statement() -> double;
// auto find_all(string s) -> vector<Variable>;
//
// Token Token_stream::get();
// double statement();
// vector<Variable> find_all(string s);

// auto expression(Token_stream& ts) { // deduce the return type from the definition
//   double left = term(ts);
//   // ...
//   return left;
// }
