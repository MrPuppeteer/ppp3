// void f() {
//   g();  // error: g() isn't (yet) in scope
// }
//
// void g() {
//   f();  // OK: f() is in scope
// }
//
// void h() {
//   int x = y;  // error: y isn't (yet) in scope
//   int y = x;  // OK: x is in scope
//   g();        // OK: g() is in scope
// }

// --------------------------------------------------------

int max(int a, int b) { // max is global; a and b are local
  int m;  // m is local
  if (a>=b) m=a;
  else m=b;
  return m;
}

int abs(int a) {  // abs is global; a is local
  return (a>=0) ? a : -a;
}


// --------------------------------------------------------

// // no r, i, or v here
// class My_vector {
//   vector<int> v;  // v is in class scope
// public:
//   int largest() {
//     int r = 0;  // r is local
//     for (int i = 0; i<v.size(); ++i)
//       r = max(r,abs(v[i])); // i is in the for's statement scope
//     // ... no i here ...
//     return r;
//   }
//   // ... no r here ...
// };
// // no v here

int x = 0;  // a global variable - avoid those where you can
int y = 0;

int f() {
  int x = 0;  // a local fariable, hides the global x
  x = 7;      // the local x
  {
    int x = y;  // local x initialized by global y, hides the previous local x
    ++x;        // the x from the previous line
  }
  ++x;  // the x from the first line of f()
  return x;
}

// --------------------------------------------------------

// class C {
// public:
//   void f();
//   void g() { /* ... */ }  // a member function can be defined within its class
//   // ...
// };
// void C::f() { // a member definition can be outside its class
//   // ...
// }

// --------------------------------------------------------
//
// class C {
// public:
//   class M {
//     // ...
//   };
//   // ...
// };

// --------------------------------------------------------

// void f() {
//   class L {
//     // ...
//   };
//   // ...
// }

// --------------------------------------------------------

// void f() {
//   void g() { /* ... */ } // error: nested function
//   // ...
// }

// --------------------------------------------------------

// void f(int x, int y) {
//   if (x>y) {
//     // ...
//   } else {
//     // ...
//     {
//       // ...
//     }
//     // ...
//   }
// }

// --------------------------------------------------------

// // dangerously ugly code
// struct X {
// void f(int x) {
// struct Y {
// int f() { return 1; } int m; };
// int m;
// m=x; Y m2;
// return f(m2.f()); }
// int m; void g(int m) {
// if (0<m) f(m+2); else {
// g(m+2.3); }}
// X() { } int m3() {
// }
//
// void main() {
// X a; a.f(2);}
// };
