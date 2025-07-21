module Tokenstream; // we are defining a module called "Tokenstream"

import std; // implementation "details"
using namespace std;  // implicitly accessing std - only within Tokenstream
export class Token {
public:
  char kind;  // what kind of token
  double value; // for numbers: a value
  Token(char k) :kind{k}, value{0.0} {} // construct from one value
  Token(char k, double v) :kind{k}, value{v} {} // construct from two values
};

export class Token_stream {
public:
  Token get();  // get a Token
  void putback(Token t);  // put a Token back
private:
  bool full = false;  // is there a Token in the buffer?
  Token buffer; // putback() saves its token here
};

void Token_stream::putback(Token t) {
  if (full) throw runtime_error("Token_stream::putback() into a full buffer");
  buffer = t; // copy t to buffer
  full = true;  // buffer is now full
}

Token Token_stream::get() {
  if (full) { // do we already have a Token ready?
    full = false; // remove Token from buffer
    return buffer;
  }

  // ... use iostream and create a Token ...
}
