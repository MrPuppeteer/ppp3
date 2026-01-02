import std;
using namespace std;

// int main() {
//   Date d;
//   const Date start_of_term;
//
//   int a = d.day();             // OK
//   int b = start_of_term.day(); // should be OK (why?), but isn’t
//
//   d.add_day(3);             // OK
//   start_of_term.add_day(3); // error
// }

enum Month { jan, feb };
struct Year {
  int y;
};

class Date {
public:
  Date(int y, Month m, int d);
  // ...
  int day() const;     // const member: can’t modify the object
  Month month() const; // const member: can’t modify the object
  Year year() const;   // const member: can’t modify the object

  void add_day(int n);   // non-const member: can modify the object
  void add_month(int n); // non-const member: can modify the object
  void add_year(int n);  // non-const member: can modify the object
private:
  Year y;
  Month m;
  int d; // day of month
};

int Date::day() const {
  ++d; // error: attempt to change object from const member function
  return d;
}

int main() {
  Date d{2000, Month::jan, 20};
  const Date cd{2001, Month::feb, 21};
  cout << d.day() << " − " << cd.day() << '\n'; // OK
  d.add_day(1);                                 // OK
  cd.add_day(1);                                // error: cd is a const
}
