import std;
using namespace std;

double fct(int a, double d);  // declaration of fct (no body)

double fct(int a, double d) { // definition of fct
  return a*d;
}

int current_power();  // current_power doesn't take an argument

void increase_power_to(int level);  // increase_power_to() doesn't return a value

int my_find(vector<string> vs, string s, int hint); // naming arguments: search starting from hint

int my_find(vector<string>, string, int); // not naming arguments

// int my_find(vector<string> vs, string s, int hint) {  // search for s in vs starting at hint
//   if (hint<0 || vs.size()<=hint) hint = 0;
//   for (int i = hint; i<vs.size(); ++i)  // search starting from hint
//     if (vs[i]==s) return i;
//   for (int i = 0; i<hint; ++i)  // if we didn't find s, so search before hint
//     if (vs[i]==s) return i;
//   return -1;
// }

int my_find(vector<string> vs, string s, int) { // 3rd argument unused
  for (int i = 0; i<vs.size(); ++i)
    if (vs[i]==s) return i;
  return -1;
}
