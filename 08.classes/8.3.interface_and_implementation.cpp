import std;
using namespace std;

// class X { // this class's name is X
// public:
//   // the interface to users (accessible by all)
//   // functions, types, and data (data is often best kept private)
// private:
//   // the implementation details (used by members of this class only)
//   // functions, types, and data
// };

// // class members are private by default
// class X {
//   int mf(int);
//   // ...
// };

// // means:
// class X {
// private:
//   int mf(int);
//   // ...
// };

// int main() {
//   X x; // variable x of type X
//   int y = x.mf(); // error: mf is private (i.e., inaccessible)
// }

// user cannot directly refer to a private member; instead, go through public function to use it
class X {
  int m;
  int mf(int);
public:
  int f(int i) { m=i; return mf(i); }
};

int main() {
  X x;
  int y = x.f(2);
}

// // struct is class where members are public by default
// struct X {
//   int m;
// };

// // means:
// class X {
// public:
//   int m;
//   // ...
// };
