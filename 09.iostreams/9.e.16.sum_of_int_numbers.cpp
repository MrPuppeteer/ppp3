import std;
using namespace std;

int main() try {
  string iname;
  cout << "Please enter the input file name: ";
  cin >> iname;

  ifstream ist{iname};
  if (!ist) throw runtime_error("could not open input file: " + iname);

  long long sum = 0;
  int val = 0;
  int count = 0;

  while (ist >> val) {
    sum += val;
    ++count;
  }

  if (ist.fail() && !ist.eof()) throw runtime_error("Non-integer data found in file.");

  cout << "Processed " << count << " numbers.\n";
  cout << "The total sum is: " << sum << '\n';

} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "unexpected error!\n";
  return 2;
}
