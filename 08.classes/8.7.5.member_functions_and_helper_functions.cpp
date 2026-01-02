import std;
using namespace std;

// helper function
Date next_Sunday(const Date &d) {
  // access d using d.day(), d.month(), and d.year()
  // make new Date to return
}

Date next_weekday(const Date &d) { /* ... */ }

bool leapyear(int y) { /* ... */ }

bool operator==(const Date &a, const Date &b) {
  return a.year() == b.year() && a.month() == b.month() && a.day() == b.day();
}

bool operator!=(const Date &a, const Date &b) { return !(a == b); }

namespace Chrono {
enum class Month { /* ... */ };
class Date { /* ... */
};
bool is_date(int y, Month m, int d); // true for valid date
Date next_Sunday(const Date &d) { /* ... */ }
Date next_weekday(const Date &d) { /* ... */ }

bool leapyear(int y) { /* ... */ } // see exercise 10
bool operator==(const Date &a, const Date &b) { /* ... */ }
// ...
} // namespace Chrono
