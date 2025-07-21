import std;
using namespace std;

string program_name = "silly";
vector<string> v; // v is global

void f() {
  string s; // s is local to f
  while (cin>>s && s!="quit") {
    string stripped;  // stripped is local to the loop
    string not_letters;
    for (char x : s)  // x has statement scope
      if (isalpha(x)) stripped += x;
      else not_letters += x;
    v.push_back(stripped);
  }
  // ... we can still use s here ...
}
