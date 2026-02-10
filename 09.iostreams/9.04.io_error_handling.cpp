import std;
using namespace std;

int main() {
  int i = 0;
  cin >> i;
  if (!cin) { // we get here (only) if an input operation failed
    if (cin.bad()) throw runtime_error("cin is bad"); // let's get out of here!
    if (cin.eof()) {
      // ... this is often how we want a sequence of input operations to end ...
    }
    if (cin.fail()) { // stream encountered something unexpected
      cin.clear();  // make ready for more input
      // ... somehow recover ...
    }
  }
}

// read integers from ist into v until we reach eof() or terminator
void fill_vector(istream& ist, vector<int>& v, char terminator) {
  for (int x; ist>>x; ) v.push_back(x);
  if (ist.eof()) return;  // fine: we found the end of file
  // if (ist.bad()) throw runtime_error("ist is bad"); // stream corrupted; let's get out of here
  // if (ist.fail()) { // clean up the mess as best we can and report the problem
  //   ist.clear();  // clear stream state, so that we can look for terminator
  //   char c = 0;
  //   ist  >> c;  // read a character, hopefully terminator
  //   if (c != terminator) {  // unexpected character
  //     ist.unget();  // put that character back
  //     ist.clear(ios::failbit);  // set the state to fail()
  //   }
  // }

  ist.exceptions(ist.exceptions()|ios::badbit); // make ist throw if it goes bad
  
  // if we get here ist is not good, bad(), nor eof(), so ist must be fail()
  ist.clear();  // clear stream state
  char c = 0;
  ist >> c; // read a character, hopefully terminator
  if (c != terminator) {  // ouch: not the terminator, so we must fail
    ist.unget();  // maybe the caller can use that character
    ist.clear(ios::failbit);  // set the state to fail()
  }

  ist.exceptions(ist.exceptions()|ios::badbit|ios::failbit); // throw on any failure
}

// read integers from ist into v until we reach eof()
void fill_vector2(istream& ist, vector<int>& v) {
  for (int x; ist>>x; ) v.push_back(x);
}
