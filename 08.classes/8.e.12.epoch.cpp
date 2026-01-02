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

  int day() const;
  Month month() const;
  Year year() const;

  void add_day(int n);
  void add_month(int n);
  void add_year(int n);

  bool is_valid(Year y, Month m, int d);

private:
  long int days_since_epoch = 0; // 0 = 1 Jan 1970
};

bool leapyear(int y);
int days_in_month(Month m, int year);

long int date_to_days(Year y, Month m, int d) {
  long int total = 0;

  for (int i = 1970; i < y.y; ++i) total += (leapyear(i) ? 366 : 365);

  for (int i = 1; i < static_cast<int>(m); ++i)
    total += days_in_month(static_cast<Month>(i), y.y);

  total += (d-1);
  return total;
}

Date::Date(Year yy, Month mm, int dd) {
  if (yy.y < 1970 || !is_valid(yy, mm, dd)) throw Invalid{};
  days_since_epoch = date_to_days(yy, mm, dd);
}

Year Date::year() const {
  long int temp = days_since_epoch;
  int y = 1970;

  while (true) {
    int d_in_y = leapyear(y) ? 366 : 365;
    if (temp < d_in_y) break;
    temp -= d_in_y;
    y++;
  }
  return Year{y};
}

Month Date::month() const {
  long int temp = days_since_epoch;
  int y = 1970;

  while (true) {
    int d_in_y = (leapyear(y) ? 366 : 365);
    if (temp < d_in_y) break;
    temp -= d_in_y;
    y++;
  }

  int m = 1;
  while (true) {
    int d_in_m = days_in_month(static_cast<Month>(m), y);
    if (temp < d_in_m) break;
    temp -= d_in_m;
    m++;
  }

  return static_cast<Month>(m);
}

int Date::day() const {
  long int temp = days_since_epoch;
  int y = 1970;

  while (true) {
    int d_in_y = leapyear(y) ? 366 : 365;
    if (temp < d_in_y)
      break;
    temp -= d_in_y;
    y++;
  }

  int m = 1;
  while (true) {
    int d_in_m = days_in_month(static_cast<Month>(m), y);
    if (temp < d_in_m)
      break;
    temp -= d_in_m;
    m++;
  }

  return static_cast<int>(temp + 1);
}

void Date::add_day(int n) {
  if (days_since_epoch + n < 0) throw Invalid{};
  days_since_epoch += n;
}

void Date::add_month(int n) {
  Year y = year();
  Month m = month();
  int d = day();

  int total_m = static_cast<int>(m) + n;
  int new_y = y.y + (total_m - 1) / 12;
  int new_m_idx = (total_m - 1) % 12 + 1;
  if (new_m_idx <= 0) {
    new_m_idx += 12;
    new_y--;
  }

  Month new_m = static_cast<Month>(new_m_idx);
  int max_d = days_in_month(new_m, new_y);
  if (d > max_d) d = max_d;

  days_since_epoch = date_to_days(Year{new_y}, new_m, d);
}

void Date::add_year(int n) {
  Year curr_y = year();
  Month curr_m = month();
  int curr_d = day();

  if (curr_m == Month::feb && curr_d == 29 && !leapyear(curr_y.y + n)) curr_d = 28;

  days_since_epoch = date_to_days(Year{curr_y.y + n}, curr_m, curr_d);
}

bool Date::is_valid(Year y, Month m, int d) {
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
  Date epoch{Year{1970}, Month::jan, 1};
  cout << "Epoch Date: " << epoch << " (Week " << week_of_year(epoch) << ")\n\n";

  Date leap_day{Year{2024}, Month::feb, 28};
  cout << "Starting date: " << leap_day << " (" << day_of_week(leap_day) << ")\n";
  leap_day.add_day(1);
  cout << "Added 1 day:   " << leap_day << " (" << day_of_week(leap_day) << ")\n";
  leap_day.add_day(1);
  cout << "Added 1 day:   " << leap_day << " (" << day_of_week(leap_day) << ")\n\n";

  Date end_of_august{Year{2025}, Month::aug, 31};
  cout << "Starting date: " << end_of_august << '\n';
  end_of_august.add_month(1);
  cout << "Added 1 month: " << end_of_august << " (Should be Sept 30)\n\n";

  Date friday{Year{2025}, Month::dec, 26};
  cout << "Friday: " << friday << " (" << day_of_week(friday) << ")\n";
  cout << "Next workday: " << next_workday(friday) << " ("
       << day_of_week(next_workday(friday)) << ")\n\n";

  cout << "Testing boundary (1969): ";
  try {
    Date pre_epoch{Year{1969}, Month::dec, 31};
  } catch (Date::Invalid) {
    cout << "Invalid date!\n";
  }

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
