import std;
using namespace std;

bool is_punct(char c);
void replace_punct(string &s);

int main() {
  cout << "Enter text (Press Ctrl+D to finish):\n";

  string line;
  while (getline(cin, line)) {
    replace_punct(line);
    cout << line << '\n';
  }
}

bool is_punct(char c) {
  static const string puncts = ".;,?-'";
  return puncts.find(c) != string::npos;
}

void replace_punct(string &s) {
  bool in_quotes = false;

  for (char &c : s) {
    if (c == '"') {
      in_quotes = !in_quotes;
      continue;
    }

    if (!in_quotes && is_punct(c)) c = ' ';
  }
}
