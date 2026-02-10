import std;
using namespace std;

bool is_vowel(char c);
void remove_vowels(string& s);

int main() try {
  ifstream ist{"disemvowels"};
  if (!ist) throw runtime_error("can't open input file disemvowels");

  string line;

  while (getline(ist, line)) {
    remove_vowels(line);
    cout << line << '\n';
  }
} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
}

bool is_vowel(char c) {
  static const string vowels = "aiueoAIUEO";
  return vowels.find(c) != string::npos;
}

void remove_vowels(string& s) {
  string res;
  res.reserve(s.length());

  for (char& x : s) {
    if (is_vowel(x)) continue;

    if (x == ' ' && !res.empty() && res.back() == ' ') continue;
    res.push_back(x);
  }
  s = res;
}
