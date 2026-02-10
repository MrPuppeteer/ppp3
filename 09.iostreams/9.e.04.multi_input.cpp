import std;
using namespace std;

struct NumberEntry {
  string raw_input;
  string base_type;
  int decimal_value;
};

string get_base_type(const string& s);

int main() try {
  vector<NumberEntry> entries;
  string input;
  cout << "Enter several integers (octal, decimal, or hex). Press CTRL+D to quit: ";

  while (cin >> input) {
    try {
      size_t idx = 0;
      int val = stoi(input, &idx, 0);
      if (idx < input.length()) {
        string leftover = input.substr(idx);
        cout << "Ignored '" << leftover << "' at the end of " << input << ".\n";
        input = input.substr(0, idx);
      }
      entries.push_back({input, get_base_type(input), val});
    } catch (...) {
      cout << "Invalid input: " << input << " skipped.\n";
    }
  }

  cout << '\n';
  for (const auto& entry : entries) {
    cout << setw(10) << entry.raw_input
         << setw(12) << entry.base_type << " converts to "
         << setw(10) << entry.decimal_value << " decimal" << '\n';
  }
} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "unexpected error!\n";
  return 2;
}

string get_base_type(const string& s) {
  if (s.size() > 1 && s[0] == '0') {
    if (s[1] == 'x' || s[1] == 'X') return "hexadecimal";
    return "octal";
  }
  return "decimal";
}
