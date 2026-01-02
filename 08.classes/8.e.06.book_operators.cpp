import std;
using namespace std;

class Book {
public:
  class Invalid {};
  Book(string i, string t, string a, string cd, bool ico);
  string get_isbn() const { return isbn; }
  string get_title() const { return title; }
  string get_author() const { return author; }
  string get_copyright_date() const { return copyright_date; }
  bool is_book_checked_out() const { return is_checked_out; }
  void check_book_in() { is_checked_out = false; }
  void check_book_out() { is_checked_out = true; }
  bool is_isbn_valid();
private:
  string isbn;
  string title;
  string author;
  string copyright_date;
  bool is_checked_out;
};

Book::Book(string i, string t, string a, string cd, bool ico)
    : isbn{i}, title{t}, author{a}, copyright_date{cd}, is_checked_out{ico} {
  if (!is_isbn_valid()) throw Invalid{};
}

bool Book::is_isbn_valid() {
  // accepted form: n-n-n-x
  // where n is an integer and x is a digit or a letter
  const regex accepted_form(R"(\d+-\d+-\d+-[a-zA-Z0-9])");
  return regex_match(isbn, accepted_form);
}

bool operator==(const Book& a, const Book& b) {
  const string& isbn_a = a.get_isbn();
  const string& isbn_b = b.get_isbn();

  return isbn_a == isbn_b;
}

bool operator!=(const Book& a, const Book& b) {
  return !(a == b);
}

ostream& operator<<(ostream& os, const Book& b) {
  os << "Title: " << b.get_title() << '\n'
     << "Author: " << b.get_author() << '\n'
     << "ISBN: " << b.get_isbn() << '\n';
  return os;
}

int main() try {
  Book book1 {"1234-5678-91011-X", "A tale", "Mr. B", "2025", false};
  Book book2 {"1234-5678-91011-A", "the Chronicle", "the D", "2026", true};
  cout << book1 << book2
       << "Is " << book1.get_title() << " and " << book2.get_title() << " the same?\n"
       << ((book1 == book2) ? "True" : "False") << '\n';
} catch (exception &e) {
  cerr << e.what() << '\n';
  return 1;
} catch (Book::Invalid) {
  cerr << "Invalid ISBN" << '\n';
  return 2;
} catch (...) {
  cerr << "Unknown exception!\n";
  return 3;
}
