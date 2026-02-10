import std;
using namespace std;

int main() try {
  string iname;
  cout << "Please enter input file name: ";
  cin >> iname;
  ifstream ist{iname};
  if (!ist) throw runtime_error("can't open input file " + iname);

  string oname;
  cout << "Please enter output file name: ";
  cin >> oname;
  ofstream ost{oname};
  if (!ost) throw runtime_error("can't open output file " + oname);

  ost << scientific << setprecision(8);

  double d;
  int count = 0;
  while (ist >> d) {
    ost << left << setw(20) << d;
    
    count++;
    if (count % 4 == 0) ost << '\n';
  }

  if (count % 4 != 0) ost << '\n';

  cout << "Formatting complete. Check " << oname << " for results.\n";

} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "unexpected error\n";
  return 2;
}
