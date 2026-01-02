import std;
using namespace std;

enum class Day {
  sun, mon, tue, wed, thu, fri, sat
};

ostream &operator<<(ostream &os, const Day &d) {
  switch (d) {
    case Day::sun: os << "sun"; break;
    case Day::mon: os << "mon"; break;
    case Day::tue: os << "tue"; break;
    case Day::wed: os << "wed"; break;
    case Day::thu: os << "thu"; break;
    case Day::fri: os << "fri"; break;
    case Day::sat: os << "sat"; break;
    default: throw runtime_error("invalid day");
  }

  return os;
}

enum class Month {
  jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month operator++(Month &m) {
  m = (m == Month::dec) ? Month::jan : Month{static_cast<int>(m) + 1};
  return m;
}

vector<string> month_tbl = {"Not a month",
                            "January",   "February", "March",    "April",
                            "May",       "June",     "July",     "August",
                            "September", "October",  "November", "December"};

ostream &operator<<(ostream &os, Month m) {
  return os << month_tbl[static_cast<size_t>(m)];
}

struct Year {
  int y;
};

ostream &operator<<(ostream &os, Year yy) {
  return os << yy.y;
}

class Date {
public:
  class Invalid {};
  Date();
  Date(Year y, Month m, int d);

  int day() const { return d; }
  Month month() const { return m; }
  Year year() const { return y; }

  void add_day(int n);
  void add_month(int n);
  void add_year(int n);

  bool is_valid();

private:
  Year y{2001};
  Month m = Month::jan;
  int d = 1;
};

Date::Date(Year yy, Month mm, int dd) : y{yy}, m{mm}, d{dd} {
  if (!is_valid()) throw Invalid{};
}

int days_in_month(Month m, int year);

void Date::add_day(int n) {
  if (n > 0) {
    while (n > 0) {
      int max_d = days_in_month(m, y.y);

      if (d + n <= max_d) {
        d += n;
        n = 0;
      } else {
        n -= (max_d - d + 1);
        d = 1;
        add_month(1);
      }
    }
  } else if (n < 0) {
    n = -n;
    while (n > 0) {
      if (d > n) {
        d -= n;
        n = 0;
      } else {
        n -= d;
        add_month(-1);
        d = days_in_month(m, y.y);
      }
    }
  }
}

void Date::add_month(int n) {
  if (n == 0) return;

  int total_m = static_cast<int>(m) + n;
  int new_y = y.y;
  int new_m = total_m;

  if (total_m> 12) {
    new_y += (total_m - 1) / 12;
    new_m = (total_m - 1) % 12 + 1;
  } else if (total_m < 1) {
    new_y += (total_m - 12) / 12;
    new_m = 12 + (total_m % 12);
    if (new_m > 12)
      new_m -= 12;
  }

  y.y = new_y;
  m = static_cast<Month>(new_m);

  int max_d = days_in_month(m, y.y);
  if (d > max_d) {
    d = max_d;
  }
}

void Date::add_year(int n) {
  y.y += n;
}

bool Date::is_valid() {
  if (static_cast<int>(m) < 1 || static_cast<int>(m) > 12) return false;
  if (d < 1 || d > days_in_month(m, y.y)) return false;
  return true;
}

ostream &operator<<(ostream &os, Date d) {
  // return os << d.year() << '/' << d.month() << '/' << d.day();
  return os << d.month() << ' ' << d.day() << ", " << d.year();
}

bool leapyear(int y) {
  return (((y % 4 == 0) && !(y % 100 == 0)) || (y % 400 == 0));
}

Day day_of_week(const Date &d) {
  int y = d.year().y;
  int m = static_cast<int>(d.month());
  int day = d.day();

  if (m <= 2) {
    m += 12;
    y -= 1;
  }

  int k = y % 100;
  int j = y / 100;
  int h = (day + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

  return Day{(h + 6) % 7};
}

Date next_workday(Date d) {
  Day dw = day_of_week(d);

  switch (dw) {
  case Day::fri:
    d.add_day(3);
    break;
  case Day::sat:
    d.add_day(2);
    break;
  default:
    d.add_day(1);
    break;
  }
  return d;
}

int days_in_month(Month m, int year) {
  switch (m) {
  case Month::feb:
    return leapyear(year) ? 29 : 28;
  case Month::apr:
  case Month::jun:
  case Month::sep:
  case Month::nov:
    return 30;
  default:
    return 31;
  }
}

int week_of_year(const Date &d) {
  // assuming week 1 is jan 1, and first day of week is sunday
  int days_since_jan1 = 0;
  for (int i = 1; i < static_cast<int>(d.month()); ++i) {
    days_since_jan1 += days_in_month(Month{i}, d.year().y);
  }
  days_since_jan1 += (d.day() - 1);

  Day jan1_day = day_of_week(Date{d.year(), Month::jan, 1});

  return (days_since_jan1 + static_cast<int>(jan1_day)) / 7 + 1;
}

int main() try {
  Date date = Date{Year{2025}, Month::dec, 27};
  cout << "Next workday to " << date << " (" << day_of_week(date)
       << ") is " << next_workday(date) << " ("
       << day_of_week(next_workday(date)) << ")\n";

  date = Date{Year{2025}, Month::jan, 1};
  cout << "For date " << date << " week of the year is " 
       << week_of_year(date) << '\n';

  return 0;
} catch (exception &e) {
  cerr << e.what() << '\n';
  return 1;
} catch (Date::Invalid) {
  cerr << "Invalid date!\n";
  return 2;
} catch (...) {
  cerr << "Unknown exception!\n";
  return 3;
}
