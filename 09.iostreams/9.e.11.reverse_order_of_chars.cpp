import std;
using namespace std;

int main() try {
  string iname;
  cout << "Enter the name of the file to reverse: ";
  cin >> iname;

  ifstream ist{iname};
  if (!ist) throw runtime_error("Could not open " + iname);
  
  vector<char> buffer;
  ist >> noskipws;
  for (char c; ist >> c;) buffer.push_back(c);

  reverse(buffer.begin(), buffer.end());

  for (char c : buffer) cout << c;
  cout << '\n';
} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "unexpected error!\n";
  return 2;
}
