import std;
using namespace std;

bool is_punct(char c);
string expand_contr(const string& word);
void process_line(string &s);

int main() {
  cout << "Enter text (Press Ctrl+D to finish):\n";

  string line;
  while (getline(cin, line)) {
    process_line(line);
    cout << line << '\n';
  }
}

bool is_punct(char c) {
  static const string puncts = ".;,?-'";
  return puncts.find(c) != string::npos;
}

string expand_contr(const string &word) {
  static const auto* contr_map = new map<string, string>{
    {"don't", "do not"},
    {"can't", "cannot"},
  };

  auto it = contr_map->find(word);
  if (it != contr_map->end()) return it->second;
  return word;
}

void process_line(string &s) {
  bool in_quotes = false;
  for (char& c : s) c = static_cast<char>(tolower(c));

  for (auto it = s.begin(); it != s.end(); ++it) {
    if (*it == '"') {
      in_quotes = !in_quotes;
      continue;
    }

    if (!in_quotes && is_punct(*it)) {
      if (it != s.begin() && it != prev(s.end()) && isalnum(*prev(it)) && isalnum(*next(it)) &&
         (*it == '-' || *it == '\'')) continue;
      *it = ' ';
    }
  }

  istringstream iss{s};
  string word, output;
  while (iss >> word) output += expand_contr(word) + ' ';
  s = output;
}
