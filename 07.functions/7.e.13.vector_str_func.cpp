import std;
using namespace std;

void print_v(const string& label, const vector<int>& v);
void print_v(const string& label, const vector<string>& v);

// Generates a vector<int> with the lengths of strings on v.
vector<int> gen_len_vector(const vector<string>& v);

vector<string> find_long_str(const vector<string>& v);

vector<string> find_short_str(const vector<string>& v);

string first_str(const vector<string>& v);

string last_str(const vector<string>& v);

int main() try {
  vector<string> data {"one", "two", "three", "four", "five", "six", "seven"};

  print_v("The strings vector is", data);
  print_v("The corresponding lengths are", gen_len_vector(data));
  print_v("The longest strings area", find_long_str(data));
  print_v("The shortest strings are", find_short_str(data));
  cout << "The first lexicographically string is: \"" << first_str(data) << "\"\n"
       << "The last lexicographically string is: \"" << last_str(data) << "\"\n";

  return 0;
} catch (exception &e) {
  cerr << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "Unknown exception!\n";
  return 2;
}

void print_v(const string& label, const vector<int>& v) {
  cout << label << ": { ";
  for (int i : v)
    cout << i << ' ';
  cout << "}\n";
}

void print_v(const string& label, const vector<string>& v) {
  cout << label << ": { ";
  for (string i : v)
    cout << "\"" << i << "\" ";
  cout << "}\n";
}

vector<int> gen_len_vector(const vector<string>& v) {
  vector<int> lv;
  for (string s : v)
    lv.push_back(int(s.size()));
  return lv;
}

vector<string> find_long_str(const vector<string>& v) {
  if (v.size() == 0) throw runtime_error("empty vector");

  size_t max {v[0].size()};

  for (string s : v)
    if (s.size() > max) max = s.size();

  vector<string> lv;
  for (string s : v)
    if (s.size() == max) lv.push_back(s);

  return lv;
}

vector<string> find_short_str(const vector<string>& v) {
  if (v.size() == 0) throw runtime_error("empty vector");

  size_t min {v[0].size()};

  for (string s : v)
    if (s.size() < min) min = s.size();

  vector<string> sv;
  for (string s : v)
    if (s.size() == min) sv.push_back(s);

  return sv;
}

string first_str(const vector<string>& v) {
  if (v.size() == 0) throw runtime_error("empty vector");

  string first {v[0]};
  for (string str : v)
    if (str < first) first = str;

  return first;
}

string last_str(const vector<string>& v) {
  if (v.size() == 0) throw runtime_error("empty vector");

  string last {v[0]};
  for (string str : v)
    if (str > last) last = str;

  return last;
}
