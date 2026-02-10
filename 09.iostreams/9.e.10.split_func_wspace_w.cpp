import std;
using namespace std;

vector<string> split(const string& s) {
  vector<string> words;
  istringstream iss{s};
  string w;

  while (iss >> w) words.push_back(w);
  return words;
}

vector<string> split(const string& s, const string& w) {
  string snow = s;
  for (char& c : snow)
    if (w.find(c) != string::npos) c = ' ';

  vector<string> words;
  istringstream iss{snow};
  string word;

  while (iss >> word) words.push_back(word);
  return words;
}
