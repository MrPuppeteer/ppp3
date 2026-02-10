import std;
using namespace std;

int main() try {
  string iname;
  cout << "Enter the name of the file to reverse: ";
  cin >> iname;

  ifstream ist{iname};
  if (!ist) throw runtime_error("Could not open " + iname);
  
  vector<string> words;
  for (string w; ist >> w;) words.push_back(w);

  reverse(words.begin(), words.end());

  for (size_t i = 0; i < words.size(); ++i)
    (i < words.size()-1) ? cout << words[i] << " " : cout << words[i]; 
  cout << '\n';
} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "unexpected error!\n";
  return 2;
}
