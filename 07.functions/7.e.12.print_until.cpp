import std;
using namespace std;

void print_sv(const string& label, const vector<string>& v);

// print until the string called "quit" is found
void print_until_s(const vector<string>& v, const string& quit);

void print_until_ss(const vector<string>& v, const string& quit);

void test(const string& label, const vector<string>& v, const string& quit, bool is_s);

int main() try {
  string exit {"exit"};
  string quit {"quit"};
  string s {"first"};
  string ss {"second"};
  vector<string> test1 {"Hi!", "Hello", "Bye", quit, "Until tomorrow"};
  vector<string> test2 {"1", "2", "3", "4", "5"};
  const vector<string> test3 {};
  vector<string> test4 {quit, "Hello", "Bye", quit, "Until tomorrow"};
  vector<string> test5 {"Hi!", "Hello", "Bye", quit, exit};
  vector<string> test6 {"Hi!", "Hello", "Bye", quit, "Until tomorrow", quit, "No more"};
  vector<string> test7 {"Hi!", "Hello", exit, "Bye", exit, quit, exit};

  cout << "print_until_s() tests:\n";
  test("test1", test1, quit, true);
  test("test2", test2, "", true);
  test("test3", test3, exit, true);
  test("test4", test4, quit, true);
  test("test5", test5, exit, true);

  cout << "\nprint_until_ss() tests:\n";
  test("test6", test6, quit, false);
  test("test7", test7, exit, false);

  return 0;
} catch (exception& e) {
  cerr << e.what() << endl;
  return 1;
} catch (...) {
  cerr << "Unknown exception" << endl;
  return 2;
}

void print_sv(const string& label, const vector<string>& v) {
  cout << label << ": { ";
  for (string i : v) cout << i << ' ';
  cout << "}\n";
}

void print_until_s(const vector<string>& v, const string& quit) {
  for (string s : v) {
    if (s==quit) return;
    cout << s << '\n';
  }
}

void print_until_ss(const vector<string>& v, const string& quit) {
  bool seen {false};
  for (string s : v) {
    if (s == quit) {
      if (!seen) seen = true;
      else return;
    }
    cout << s << '\n';
  }
}

void test(const string& label, const vector<string>& v, const string& quit, bool is_s) {
  cout << "Print until the "
       << ((is_s == true) ? "first" : "second")
       << " appearance of '" << quit << "' ...\n";

  print_sv(label, v);
  if (is_s == true)
    print_until_s(v, quit);
  else if (is_s == false)
    print_until_ss(v, quit);
}
