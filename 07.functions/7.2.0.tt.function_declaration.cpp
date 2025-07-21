import std; // we find the declaration of cout in here

// int f(int); // declaration of f
int f(int i); // declaration of f

int main() {
  // error: use of undeclared identifier 'std'  // without import std

  // error: use of undeclared identifier 'i'    // without declaration of f and i
  
  // undefined reference to `f(int)`            // without definition of f
  // error: linker command failed with exit code 1

  int i = 7;  // declaration of i
  std::cout << f(i) << '\n';
}

int f(int i) { return i; }
