import std;
using namespace std;

vector<string> split(const string& s) {
  vector<string> words;
  istringstream iss{s};
  string w;

  while (iss >> w) words.push_back(w);
  return words;
}
