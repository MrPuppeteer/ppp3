import std;
using namespace std;

// the arguments are positive and a < b < c
int my_complicated_function(int a, int b, int c);

int main() {}

int my_complicated_function(int a, int b, int c) {
  if (!(0<a && a<b && b<c))   // ! means "not" and && means "and"
    throw runtime_error("bad arguments for mcf");
  // ...
  return 0;
}
