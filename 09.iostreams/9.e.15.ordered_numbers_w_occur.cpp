import std;
using namespace std;

int main() try {
  string iname;
  cout << "Enter input file name: ";
  cin >> iname;

  ifstream ist{iname};
  if (!ist) throw runtime_error("could not open input file.");

  vector<double> numbers;
  double d;
  while (ist >> d) numbers.push_back(d);

  if (numbers.empty()) throw runtime_error("empty file.");

  sort(numbers.begin(), numbers.end());

  cout << "\nResult:\n";

  double current_val = numbers[0];
  int count = 0;

  for (size_t i = 0; i < numbers.size(); ++i) {
    if (numbers[i] == current_val) count++;
    else {
      cout << current_val;
      if (count > 1) cout << '\t' << count;
      cout << '\n';

      current_val = numbers[i];
      count = 1;
    }
  }

  cout << current_val;
  if (count > 1) cout << '\t' << count;
  cout << '\n';
} catch (exception &e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "unexpected error!\n";
  return 2;
}
