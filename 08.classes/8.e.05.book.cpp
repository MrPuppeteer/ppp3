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

int main() try {
  Book book1 {"1234-5678-91011-X", "A tale", "Mr. B", "2025", false};
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
