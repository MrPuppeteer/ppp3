import std;
using namespace std;

bool is_punct(char c);
string expand_contr(const string& word);
void extract_words(string& s, map<string, int>& dict);

int main() try {
  string iname;
  cout << "Enter input file name: ";
  cin >> iname;
  ifstream ist{iname};

  if (!ist) throw runtime_error("Can't open " + iname + "\n");

  map<string, int> dict;
  string line;
  while (getline(ist, line)) extract_words(line, dict);

  cout << "Sorted list of words and its frequency\n";
  for (const auto& [word, count] : dict) {
    cout << "  " << left << setw(10) << word << " : " << count << '\n';
  }
} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "unknown error\n";
  return 2;
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

void extract_words(string& s, map<string, int>& dict) {
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
  string word;
  while (iss >> word) {
    istringstream expanded_iss{expand_contr(word)};
    string fword;
    while(expanded_iss >> fword)
      if (fword.size() > 1 || fword == "a" || fword == "i") dict[fword]++;
  }
}
