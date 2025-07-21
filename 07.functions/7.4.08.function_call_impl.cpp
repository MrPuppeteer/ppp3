import std;
using namespace std;

// double expression(Token_stream& ts) {
//   double left = term(ts);
//   Token t = ts.get();
//   // ...
// }
//
// double term(Token_stream& ts) {
//   double left = primary(ts);
//   Token t = ts.get();
//   // ...
//     case '/': {
//       double d = primary(ts);
//       // ...
//     }
//   // ...
// }
//
// double primary(Token_stream& ts) {
//   Token t = ts.get();
//   switch (t.kind) {
//     case '(': {
//       double d = expression(ts);
//       // ...
//     }
//     // ...
//   }
// }
