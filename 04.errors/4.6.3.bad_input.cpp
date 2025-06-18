import std;
using namespace std;

// double some_function();

void error(string s);

void error(string s1, string s2);

// int main() {
  // double d = 0;
  // cin >> d;
  // if (cin) {
  //   // ... all is well, and we can try reading again ..
  // } else {
  //   // ... the last read didn't succeed, so we take some other action ...
  // }
// }

int main() try {
  // ... our program ...
  return 0;         // 0 indicates success
} catch(runtime_error& e) {
  cerr << "runtime_error: " << e.what() << '\n';
  return 1;         // 1 indicates failure
} catch (...) {
  cerr << "Oops: unknown exception!\n";
  return 2;         // 2 indicates failure
}

void error(string s) {
  throw runtime_error{s};
}


void error(string s1, string s2) {
  throw runtime_error{s1+s2};
}

// double some_function() {
//   double d = 0;
//   cin >> d;
//   if (!cin)
//     throw runtime_error("couldn't read a double in 'some_function()'");
//   // ... use d ...
//   return d;
// }


