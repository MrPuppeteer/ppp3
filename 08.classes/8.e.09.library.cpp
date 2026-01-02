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
  return a.get_isbn() == b.get_isbn();
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

bool operator==(const Patron& a, const Patron& b) {
  return a.get_card_number() == b.get_card_number();
}

bool operator!=(const Patron& a, const Patron& b) {
  return !(a == b);
}

bool is_patron_owes_fee(Patron p) {
  if (p.get_fees() > 0) return true;
  return false;
}

struct Transaction {
  Book book;
  Patron patron;
  string date;
};

class Library {
public:
  void add_book(Book b) { books.push_back(b); }
  void add_patron(Patron p) { patrons.push_back(p); }
  void checkout_book(const Patron& p, const Book& b);
  vector<Patron> get_fee_holders() const;
private:
  vector<Book> books;
  vector<Patron> patrons;
  vector<Transaction> transactions;
};

void Library::checkout_book(const Patron& p, const Book& b) {
  auto p_it = find(patrons.begin(), patrons.end(), p);
  if (p_it == patrons.end()) throw runtime_error("Patron not found in Library!");

  auto b_it = find(books.begin(), books.end(), b);
  if (b_it == books.end()) throw runtime_error("Book not found in Library!");

  if (b_it->is_book_checked_out()) throw runtime_error("Book is already checked out!");

  if (is_patron_owes_fee(*p_it)) throw runtime_error("Patron owes fees!");

  b_it->check_book_out();
  string curr_date = format("{:%Y-%m-%d}", chrono::floor<chrono::days>(chrono::system_clock::now()));
  transactions.push_back(Transaction{*b_it, *p_it, curr_date});
}

vector<Patron> Library::get_fee_holders() const {
  vector<Patron> fee_holders;
  for (Patron p : patrons) {
    if (is_patron_owes_fee(p)) fee_holders.push_back(p);
  }
  return fee_holders;
}

int main() try {
    Library lib;

    Book b1{"1-2-3-a", "The C++ Programming Language", "Stroustrup", "2013", Genre::nonfiction, false};
    Book b2{"5-5-5-5", "The Hobbit", "J.R.R. Tolkien", "1937", Genre::fiction, false};
    
    Patron p1{"Andy", 1001, 0.0};
    Patron p2{"Bobby", 1002, 25.50};

    lib.add_book(b1);
    lib.add_book(b2);
    lib.add_patron(p1);
    lib.add_patron(p2);

    cout << "--- Library Initialized ---\n";
    cout << b1;

    cout << "\nAttempting checkout for Andy...\n";
    lib.checkout_book(p1, b1);
    cout << "Success!\n";

    cout << "\nAttempting checkout for Bobby (who owes fees)...\n";
    try {
        lib.checkout_book(p2, b2);
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << '\n';
    }

    cout << "\nAttempting to create a book with an invalid ISBN...\n";
    Book b3{"bad-isbn-format", "Broken Book", "No Author", "2024", Genre::fiction, false};
} catch (exception &e) {
  cerr << "Error: " << e.what() << '\n';
  return 1;
} catch (Book::Invalid) {
  cerr << "Invalid ISBN" << '\n';
  return 2;
} catch (...) {
  cerr << "Unknown exception!\n";
  return 3;
}
