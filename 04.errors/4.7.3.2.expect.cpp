import std;
using namespace std;

void expect(bool cond, string mess);

// bool ordered_positive(int a, int b, int c);

// the arguments are positive and a < b < c
int my_complicated_function(int a, int b, int c);

int main() {
  my_complicated_function(1,2,3);
}

// // better: save time and grief
// int my_complicated_function(int a, int b, int c) {
//   if (!(0<a && a<b && b<c))   // ! means "not" and && means "and"
//     throw runtime_error("bad arguments for mcf");
//   // ...
//   return 0;
// }

// // simpler but bad
// int my_complicated_function(int a, int b, int c) {
//   // ...
//   return 0;
// }

void expect(bool cond, string mess) {
  if (!cond) {
    throw runtime_error(mess);
  }
}

// bool ordered_positive(int a, int b, int c) {
//   return 0<a && a<b && b<c;
// }

int my_complicated_function(int a, int b, int c) {
  // expect(ordered_positive(a,b,c), "bad arguments for mcf");
  expect([&]{return 0<a && a<b && b<c;}(), "bad arguments for mcf");
  // ...
  return 0;
}
