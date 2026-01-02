#include <stdexcept>
import std;
using namespace std;

enum class Genre {
  fiction, nonfiction, periodical, biography, children
};

class Book {
public:
  class Invalid {};
  Book(string i, string t, string a, string cd, Genre g, bool ico);
  string get_isbn() const { return isbn; }
  string get_title() const { return title; }
  string get_author() const { return author; }
  string get_copyright_date() const { return copyright_date; }
  Genre get_genre() const { return genre; }
  bool is_book_checked_out() const { return is_checked_out; }
  void check_book_in() { is_checked_out = false; }
  void check_book_out() { is_checked_out = true; }
  bool is_isbn_valid();
private:
  string isbn;
  string title;
  string author;
  string copyright_date;
  Genre genre;
  bool is_checked_out;
};

Book::Book(string i, string t, string a, string cd, Genre g, bool ico)
    : isbn{i}, title{t}, author{a}, copyright_date{cd}, genre{g}, is_checked_out{ico} {
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

class Patron {
public:
  Patron(string n, int cn, double f) : name{n}, card_number{cn}, fees{f} {}
  string get_name() const { return name; }
  int get_card_number() const { return card_number; }
  double get_fees() const { return fees; }
  void set_fee(double fee) { if (fee < 0) throw runtime_error("Negative fees"); fees = fee; }
private:
  string name;
  int card_number;
  double fees;
};

bool is_patron_owes_fee(Patron p) {
  if (p.get_fees() > 0) return true;
  return false;
}

int main() try {
  Book book1 {"1234-5678-91011-X", "A tale", "Mr. B", "2025", Genre::fiction, false};
  Book book2 {"1234-5678-91011-A", "the Chronicle", "the D", "2026", Genre::fiction, true};
  cout << book1 << book2
       << "Is " << book1.get_title() << " and " << book2.get_title() << " the same?\n"
       << ((book1 == book2) ? "True" : "False") << '\n';
  Patron user1 {"Andy", 1, 0};
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
