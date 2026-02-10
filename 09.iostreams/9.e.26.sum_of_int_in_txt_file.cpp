import std;
using namespace std;

int main() try {
  cout << "Please enter the input filename: ";
  string iname;
  cin >> iname;

  ifstream ifs{iname};
  if (!ifs) throw runtime_error("could not open file: " + iname);

  int sum = 0;
  int temp;

  while (ifs) {
    if (ifs >> temp) {
      sum += temp;
    } else if (ifs.fail() && !ifs.eof()) {
      ifs.clear();
      string s;
      ifs >> s;
    }
  }

  cout << "The sum of all integers in " << iname << " file is: " << sum << '\n';
} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "unexpected error!\n";
  return 2;
}
