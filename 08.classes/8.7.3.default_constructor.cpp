import std;
using namespace std;

enum Month { jan };
struct Year {
  int y;
};

// class Date {
// public:
//   Date(Year y, Month m, int d); // check for valid date and initialize
// };
//
// int main() {
//   Date d0;                         // error: no initializer
//   Date d1{};                       // error: empty initializer
//   Date d2{Year{1998}};             // error: too few arguments
//   Date d3{Year{1}, 2, 3, 4};       // error: too many arguments
//   Date d4{Year{1}, "jan", 2};      // error: wrong argument type
//   Date d5{Year{1}, Month::jan, 2}; // OK: use the three-argument constructor
//   Date d6{d5};                     // OK: use the copy constructor
//
//   string s1;         // default value: the empty string ""
//   vector<string> v1; // default value: the empty vector; no elements
//
//   string s;                          // imagine that s could be uninitialized
//   for (int i = 0; i < s.size(); ++i) // oops: loop an undefined number of
//   times
//     s[i] = toupper(s[i]); // oops: read and write a random memory location
//
//   vector<string> v;   // imagine that v could be uninitialized
//   v.push_back("bad"); // oops: write to random address
//
//   string s2 = "";
//   vector<string> v2{};
// }

// class Date {
// public:
//   Date() // default constructor (takes no arguments)
//       : y{Year{2001}}, m{Month::jan}, d{1} {}
//   // ...
// private:
//   Year y;
//   Month m;
//   int d;
// };
//
// int main() {
//   Date d; // d = {Year{2001},Month::jan,1}
// }

class Date {
public:
  // ...
  Date() {}
  Date(Year y, Month m, int d);
  Date(Year y); // January 1 of year y
  // ...
  bool is_valid();

private:
  Year y{2001};
  Month m = Month::jan;
  int d = 1;
};

Date::Date(Year yy) // January 1 of year y
    : y{yy} {}

int main() {
  string{};         // default value: the empty string ""
  vector<string>{}; // default value: the empty vector;       no elements

  string s1;         // default value: the empty string ""
  vector<string> v1; // default value: the empty vector; no elements
}

void test() {
  double x0;     // uninitialized; don’t do that
  double x1{0};  // initialize to 0
  double x2 = 0; // initialize to 0
  double x3{};   // initialize to 0
}
