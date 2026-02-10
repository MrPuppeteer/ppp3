import std;
using namespace std;

void func(istream& ist) {
  for (My_type var; ist>>var; ) { // read until end-of-file
    // ...maybe check that var is valid ...
    // ... do something with var ...
  }
  // we can rarely recover from bad; don't try unless you really have to:
  if (ist.bad()) throw runtime_error("bad input stream");

  if (ist.fail()) { /* was it an acceptable terminator? */ }
  // ... carry on: we found end-of-file
}

void func2(istream& ist) {
  // somewhere: make ist throw an exception if it goes bad:
  ist.exceptions(ist.exceptions()|ios::badbit);

  for (My_type var; ist>>var; ) { // read until end-of-file
    // ...maybe check that var is valid ...
    // ... do something with var ...
  }

  if (ist.fail()) { // use '|' as terminator and/or separator
    ist.clear();
    char ch;
    if (!(ist>>ch && ch=='|')) throw runtime_error("bad termination of input");
  }

  // carry on: we found end-of-file or a terminator
}

void end_of_loop(istream& ist, char term, const string& message) {
  if (ist.fail()) { // use term as terminator and/or separator
    ist.clear();
    char ch = 0;
    if (ist>>ch && ch==term) return;  // all is fine
    throw runtime_error(message);
  }
}

void func3(istream& ist) {
  for (My_type var; ist>>var; ) { // read until end-of-file
    // ... maybe check that var is valid ...
    // ... do something with var ...
  }
  end_of_loop(ist, '|', "bad termination of file"); // test if we can continue
  // carry on: we found end-of-file or a terminator
}
