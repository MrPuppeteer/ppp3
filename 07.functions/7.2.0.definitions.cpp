import std;
using namespace std;

// double sqrt(double d) { /* ... */ }
// int a = 7;
// vector<double> v;

// not-definitions declarations
double sqrt(double);  // no function body here
extern int a;         // "extern plus no initializer" means "not definition"

// double sqrt(double d) { /* ... */ } // definition
// double sqrt(double d) { /* ... */ } // error: double definition

// int a;  // definition
// int a;  // error: double definition

int x = 7;    // definition
extern int x; // declaration
extern int x; // another declaration

double sqrt(double);                // declaration
double sqrt(double d) { /* ... */ } // definition
double sqrt(double);                // another declaration of sqrt
double sqrt(double);                // yet another declaration of sqrt

// int sqrt(double);                // error: inconsistent declarations of sqrt
