import std;
using namespace std;

class Roman_int {
public:
  Roman_int() : val{0} {}
  Roman_int(int v) : val{v} {}

  int as_int() const { return val; }
  string as_roman() const;
private:
  int val;
};

// Helper to get value of single Roman character
int char_to_roman(char c) {
  switch (toupper(c)) {
  case 'I': return 1;
  case 'V': return 5;
  case 'X': return 10;
  case 'L': return 50;
  case 'C': return 100;
  case 'D': return 500;
  case 'M': return 1000;
  default: return 0;
  }
}

// Convert string to int
int roman_to_int(string s) {
  int total = 0;

  for (size_t i = 0; i < s.length(); ++i) {
    int s1 = char_to_roman(s[i]);
  
    if (i + 1 < s.length()) {
      int s2 = char_to_roman(s[i + 1]);
      if (s1 >= s2) total += s1;
      else total -= s1;
    } else total += s1;
  }
  return total;
}

// Convert int to string
string Roman_int::as_roman() const {
  struct Roman_Map {
    int v;
    string s;
  };

  const vector<Roman_Map> table = {
      {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
      {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
      {5, "V"},    {4, "IV"},   {1, "I"}
  };

  string res = "";
  int temp = val;
  for (auto const& entry : table) {
    while (temp >= entry.v) {
      res += entry.s;
      temp -= entry.v;
    }
  }
  return res;
}

istream& operator>>(istream& is, Roman_int& r) {
  string s;
  if (!(is >> s)) return is;
  r = Roman_int{roman_to_int(s)};
  return is;
}

ostream& operator<<(ostream& os, const Roman_int& r) {
  return os << r.as_roman();
}

int main() try {
  Roman_int r;
  cout << "Enter a Roman numeral (e.g., MCMXCIX): ";
  while (cin >> r) {
    cout << "Roman " << r << " equals " << r.as_int() << '\n';
    cout << "Enter another: ";
  }
} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "unexpected error!\n";
  return 2;
}
