import std;
using namespace std;

istream& operator>>(istream& is, Date& dd) {
  int y, m, d;
  char ch1, ch2, ch3, ch4;
  is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
  if (!is) return is;
  if (ch1!='(' || ch2!=',' || ch3!=',' || ch4!=')') { // oops: format error
    is.clear(ios::failbit);
    return is;
  }
  dd = Date{y,Month(m),d};  // update dd
  return is;
}
