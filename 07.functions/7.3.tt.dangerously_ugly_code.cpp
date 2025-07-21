// dangerously ugly code
struct X {
  void f(int x) {
    struct Y {
      int f() {
        return 1;
      }
      int m;  // never initialized or used
    };

    int m;  // variable shadow
    m = x;
    Y m2;
    return f(m2.f()); // inifinite recursion; also return value inside void function
  }

  int m;  // never used; always shadowed

  // defined but never called
  void g(int m) { // variable shadow
    if (0<m) 
      f(m+2);
    else {
      g(m+2.3); // implicit float-to-int conversion
    }
  }

  X() { }

  int m3() { }  // defined but never called

  void main() { // main inside struct will result in failed to compile and link
    X a;
    a.f(2);
  }
};
