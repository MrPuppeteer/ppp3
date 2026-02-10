import std;
using namespace std;

void classify_char(char c);

int main() {
  cout << "Enter strings to classify (Press Ctrl+D to exit):\n";
  string input;

  while (getline(cin, input)) {
    cout << "Line: " << input << '\n';
    for (char c : input) classify_char(c);
    cout << '\n';
  }
}

void classify_char(char c) {
  cout << '\'' << c << "' is ";
  vector<string> cat;

  if (isspace(c)) cat.push_back("whitespace");
  if (isalpha(c)) cat.push_back("letter");
  if (isdigit(c)) cat.push_back("digit");
  if (isxdigit(c)) cat.push_back("hex-digit");
  if (isupper(c)) cat.push_back("uppercase");
  if (islower(c)) cat.push_back("lowercase");
  if (isalnum(c)) cat.push_back("alphanumeric");
  if (iscntrl(c)) cat.push_back("control-char");
  if (ispunct(c)) cat.push_back("punctuation");
  if (isprint(c)) cat.push_back("printable");
  if (isgraph(c)) cat.push_back("graphic");

  for (size_t i = 0; i < cat.size(); ++i) {
    cout << cat[i] << (i < cat.size() - 1 ? ", " : "");
  }
  cout << '\n';
}
