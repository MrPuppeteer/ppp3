import std;
using namespace std;

// simple Date (too simple?)
struct Date {
  int y;  // year
  int m;  // month in year
  int d;  // day of month
};

void init_day(Date& dd, int y, int m, int d) {
  // ... check that (y,m,d) is a valid date. If it is, use it to initialize dd ...
}

void add_day(Date& dd, int n) {
  // ... increase dd by n days ...
}

int main() {
  // Date today; // a Date variable (a named object)
  //
  // today.y = 2025; // set today to December 24, 2025
  // today.m = 24;
  // today.d = 12;

  Date y;
  y.y = 2000;
  y.m = 2;
  y.d = 29;

  Date today;
  init_day(today, 12, 24, 2025);  // oops! (no day 2025 in year 12)
  add_day(today,1);
}
