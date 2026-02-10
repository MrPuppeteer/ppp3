import std;
using namespace std;

struct Char_class {
  int space = 0; int alpha = 0; int digit = 0; int xdigit = 0; int upper = 0;
  int lower = 0; int alnum = 0; int cntrl = 0; int punct = 0; int print = 0; int graph = 0;
};

int main() try {
  string iname;
  cout << "Please enter input file name: ";
  cin >> iname;

  ifstream ist{iname};
  if (!ist) throw runtime_error("Could not open " + iname);

  Char_class cc;
  char ch;

  while (ist.get(ch)) {
    unsigned char c = static_cast<unsigned char>(ch);
    if (isspace(c)) ++cc.space;
    if (isalpha(c)) ++cc.alpha;
    if (isdigit(c)) ++cc.digit;
    if (isxdigit(c)) ++cc.xdigit;
    if (isupper(c)) ++cc.upper;
    if (islower(c)) ++cc.lower;
    if (isalnum(c)) ++cc.alnum;
    if (iscntrl(c)) ++cc.cntrl;
    if (ispunct(c)) ++cc.punct;
    if (isprint(c)) ++cc.print;
    if (isgraph(c)) ++cc.graph;
  }

  cout << "\nCharacter classification stats for " << iname << ":\n";
  cout << "------------------------------\n";
  auto print_row = [](string label, int count) {
    cout << left << setw(14) << label << ": " << count << '\n';
  };

  print_row("Whitespace", cc.space);
  print_row("Letters", cc.alpha);
  print_row("Digits", cc.digit);
  print_row("Hex-Digits", cc.xdigit);
  print_row("Uppercase", cc.upper);
  print_row("Lowercase", cc.lower);
  print_row("Alphanumeric", cc.alnum);
  print_row("Control-Chars", cc.cntrl);
  print_row("Punctuation", cc.punct);
  print_row("Printable", cc.print);
  print_row("Graphic", cc.graph);
} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "unexpected error!\n";
  return 2;
}
