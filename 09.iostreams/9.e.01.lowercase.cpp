import std;
using namespace std;

void to_lowercase(string& s);

int main() try {
  cout << "Please enter input file name: ";
  string iname;
  cin >> iname;
  ifstream ist{iname};  // ist reads from the file named iname
  if (!ist) throw runtime_error("can't open input file " + iname);

  string oname;
  cout << "Please enter name of output file: ";
  cin >> oname;
  ofstream ost{oname};  // ost writes to a file named oname
  if (!ost) throw runtime_error("can't open output file " + oname);

  string line;
  while (getline(ist, line)) {
    to_lowercase(line);
    ost << line << '\n';
  }

  cout << "success! file " << iname << " converted to lowercase and saved as " << oname << ".\n";
} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
}

void to_lowercase(string& s) {
  for (char& x : s) x = static_cast<char>(tolower(x));
}
