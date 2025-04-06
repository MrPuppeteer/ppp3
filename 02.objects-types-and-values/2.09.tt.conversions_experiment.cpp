// Conversions from double to int and from int to char
import std;
using namespace std;

int main() {
  double d = 0;
  while (cin>>d) {  // repeat the statements below as long as we type in numbers
    int i = d;      // try to squeeze a floating-point value into an integer
    char c = i;     // try to squeeze an integer into a char
    cout << "d==" << d                // the original double
         << " i==" << i                // double converted to int
         << " c==" << c                // int value of char
         << " char(" << c << ")\n";   // the char
  }
}

// input: 2
// output: d==2 i==2 c== char()

// input: 3
// output: d==3 i==3 c== char()

// input: 128
// output: d==128 i==128 c==� char(�)

// input: 1001
// output: d==1001 i==1001 c==� char(�)

// input: -1
// output: d==-1 i==-1 c==� char(�)

// input: 56
// output: d==56 i==56 c==8 char(8)

// input: 89
// output: d==89 i==89 c==Y char(Y)

// input: 127
// output: d==127 i==127 c== char()

// input: 56.9
// output: d==56.9 i==56 c==8 char(8)

// input: 56.2
// output: d==56.2 i==56 c==8 char(8)
