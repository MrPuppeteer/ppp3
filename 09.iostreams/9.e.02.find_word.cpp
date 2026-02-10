import std;
using namespace std;

int main() try {
  string iname;
  string word;

  cout << "Please enter input file name: ";
  cin >> iname;
  ifstream ist{iname};  // ist reads from the file named iname
  if (!ist) throw runtime_error("can't open input file " + iname);

  cout << "Please enter target word: ";
  cin >> word;

  string line;
  int line_num = 0;
  bool found = false;

  while (getline(ist, line)) {
    line_num++;

    if (line.find(word) != string::npos) {
      cout << line_num << ": " << line << '\n';
      found = true;
    }
  }

  if (!found) cout << "the word " << word << " was not found in file " << iname << ".\n";
} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
}
