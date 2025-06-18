import std;
using namespace std;

int main()
try {
  // [1]
  // error: use of undeclared identifier 'Cout'; did you mean 'cout'?
  // Cout << "Success!\n";

  // cout << "Success!\n";

  // [2]
  // warning: missing terminating '"' character
  // error: expected expression
  // cout << "Success!\n;

  // cout << "Success!\n";

  // [3]
  // error: expected expression
  // warning: missing terminating '"' character
  // cout << "Success" << !\n"

  // cout << "Success" << "!\n";

  // [4]
  // error: unexpected character <U+2019>
  // error: expected expression
  // error: use of undeclared identifier 'success'
  // error character <U+2019> not allowed in an identifier
  // cout << success << ’\n’;

  // cout << "Success" << '\n';

  // [5]
  // error: no viable conversion from 'int' to 'string' (aka 'basic_string<char>')
  // error: assigning to 'value_type' (aka 'int') from incompatible type 'string' (aka
  // 'basic_string<char>')
  // string res = 7;
  // vector<int> v(10);
  // v[5] = res;

  // cout << "Success!\n";
  // int res = 7;
  // vector<int> v(10);
  // v[5] = res;
  // cout << "Success!\n";

  // [6]
  // error: type 'vector<int>' does not provide a call operator
  // error: type 'vector<int>' does not provide a call operator
  // vector<int> v(10);
  // v(5) = 7;
  // if (v(5)!=7)
  //   cout << "Success!\n";

  // vector<int> v(10);
  // v[5] = 7;
  // if (v[5]==7)
  //   cout << "Success!\n";

  // [7]
  // error: use of undeclared identifier 'cond'
  // if (cond)
  //   cout << "Success!\n";
  // else
  //   cout << "Fail!\n";

  // if (true)
  //   cout << "Success!\n";
  // else  
  //   cout << "Fail!\n";  // warning: code will never be executed

  // [8]
  // ouput: Fail!
  // bool c = false;
  // if (c)
  //   cout << "Success!\n";
  // else
  //   cout << "Fail!\n";

  // bool c = true;
  // if (c)
  //   cout << "Success!\n";
  // else
  //   cout << "Fail!\n";

  // [9]
  // error: use of undeclared identifier 'boo'; did you mean 'bool'?
  // string s = "ape";
  // boo c = "fool"<s;
  // if (c)
  //   cout << "Success!\n";

  // string s = "ape";
  // bool c = "fool">s;
  // if (c)
  //   cout << "Success!\n";

  // [10]
  // output nothing
  // string s = "ape";
  // if (s=="fool")
  //   cout << "Success!\n";

  // string s = "ape";
  // if (s!="fool")
  //   cout << "Success!\n";

  // [11]
  // warning: result of comparison against a string literal is unspecified (use an explicit
  // string comparison function instead)
  // error: invalid operands to binary expression ('ostream' (aka 'basic_ostream<char>') and 
  // 'const char[10]')
  // string s = "ape";
  // if (s=="fool")
  //   cout < "Success!\n";

  // string s = "ape";
  // if (s!="fool")
  //   cout << "Success!\n";

  // [12]
  // error: no viable conversion from 'basic_string<char>' to 'bool'
  // warning: result of comparison against a string literal is unspecified (use an explicit
  // string comparison function instead)
  // error: invalid operands to binary expression ('ostream' (aka 'basic_ostream<char>') and 
  // 'const char[10]')
  // string s = "ape";
  // if (s+"fool")
  //   cout < "Success!\n";

  // string s = "ape";
  // if (s!="fool")
  //   cout << "Success!\n";

  // [13]
  // warning: variable 'i' set but not used
  // infinite loop
  // vector<char> v(5);
  // for (int i = 0; 0<v.size(); ++i) ;
  // cout << "Success!\n";

  // vector<char> v(5);
  // for (size_t i = 0; i<v.size(); ++i) ;
  // cout << "Success!\n";

  // [14]
  // off-by-one
  // warning: comparison of integers of different signs: 'int' and 'size_type' (aka 
  // 'unsigned long')
  // vector<char> v(5);
  // for (int i = 0; i<=v.size(); ++i) ;
  // cout << "Success!\n";

  // vector<char> v(5);
  // for (size_t i = 0; i<v.size(); ++i) ;
  // cout << "Success!\n";

  // [15]
  // output: Succes
  // warning: implicit conversion changes signedness: 'int' to 'size_type' (aka 'unsigned long')
  // string s = "Success!\n";
  // for (int i = 0; i<6; ++i)
  //   cout << s[i];

  // string s = "Success!\n";
  // for (size_t i = 0; i<s.length(); ++i)
  //   cout << s[i];

  // [16]
  // error: unknown type name 'then'
  // warning: declaration shadows a variable in namespace 'std::__1'
  // error: expected ';' at end of declaration
  // if (true) then
  //   cout << "Success!\n";
  // else
  //   cout << "Fail!\n";

  // if (true)
  //   cout << "Success!\n";
  // else
  //   cout << "Fail!\n";  // warning: code will never be executed

  // [17]
  // output nothing
  // warning: implicit conversion loses integer precision: 'int' to 'char'
  // warning: result of comparison of constant 2000 with expression of type 'char' is always
  // false
  // int x = 2000;
  // char c = x;
  // if (c==2000)
  //   cout << "Success!\n";

  // int x = 2000;
  // int c = x;
  // if (c==2000)
  //   cout << "Success!\n";

  // [18]
  // off-by-one
  // warning: implicit conversion changes signedness: 'int' to 'size_type' (aka 'unsigned long')
  // string s = "Success!\n";
  // for (int i = 0; i<10; ++i)
  //   cout << s[i];

  // string s = "Success!\n";
  // for (size_t i = 0; i<s.length(); ++i)
  //   cout << s[i];

  // [19]
  // off-by-one
  // error: no viable constructor or deduction guide for deduction of template arguments of
  // 'vector'
  // vector v(5);
  // for (int i = 0; i<=v.size(); ++i) ;
  // cout << "Success!\n";

  // vector<int> v(5);
  // for (size_t i = 0; i<v.size(); ++i) ;
  // cout << "Success!\n";

  // [20]
  // infinite loop
  // int i = 0;
  // int j = 9;
  // while (i<10)
  //   ++j;
  // if (j<i)
  //   cout << "Success!\n";

  // int i = 0;
  // int j = 9;
  // while (i<10)
  //   ++i;
  // if (j<i)
  //   cout << "Success!\n";

  // [21]
  // warning: comparing floating point with == or != is unsafe
  // terminated bu signal SIGFPE (Floating point exception)
  // int x = 2;
  // double d = 5/(x-2);
  // if (d==2*x+0.5)
  //   cout << "Success!\n";

  // int x = 3;
  // double d = 5/(x-2);
  // if (d!=2*x+0.5) // warning: comparing floating point with == or != is unsafe
  //   cout << "Success!\n";

  // [22]
  // off-by-one
  // error: expected unqualified-id
  // error: use of undeclared identifier 's'
  // string<char> s = "Success!\n";
  // for (int i = 0; i<=10; ++i)
  //   cout << s[i];

  // string s = "Success!\n";
  // for (size_t i = 0; i<s.length(); ++i)
  //   cout << s[i];

  // [23]
  // infinite loop
  // error: use of undeclared identifier 'j'
  // error: use of undeclared identifier 'j'
  // int i = 0;
  // while (i<10)
  //   ++j;
  // if (j<i)
  //   cout << "Success!\n";

  // int i = 0;
  // int j = 9;
  // while (i<10)
  //   ++i;
  // if (j<i)
  //   cout << "Success!\n";

  // [24]
  // warning: using the result of an assignment as a condition without parentheses
  // warning: implicit conversion turns floating-point number into integer: 'double' to 'bool'
  // int x = 4;
  // double d = 5/(x-2);
  // if (d=2*x+0.5)
  //   cout << "Success!\n";

  // int x = 4;
  // double d = 5/(x-2);
  // if (d!=2*x+0.5) // comparing floating point with == or != is unsafe
  //   cout << "Success!\n";

  // [25]
  // error: invalid operands to binary expression ('istream' (aka 'basic_istream<char>') and
  // 'const char[10]')
  cout << "Success!\n";

  return 0;
} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "Oops: unknown exception!\n";
  return 2;
}
