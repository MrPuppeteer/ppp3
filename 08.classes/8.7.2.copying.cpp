import std;
using namespace std;

int main() {
  Date holiday {Year{1978}, Month::jul, 4}; // initialization
  Date d2 = holiday;
  Date d3 = Date{Year{1978}, Month::jul, 4};
  holiday = Date{Year{1978}, Month::dec, 24};
  d3 = holiday;

  cout << Date{Year{1978}, Month::dec, 24};
}
