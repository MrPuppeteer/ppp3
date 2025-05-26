import std;
using namespace std;

pair<pair<string, string>, pair<vector<string>, int>> find_mmm(vector<string> strings);

int main() {
  vector<string> strings;
  string str;

  cout << "Insert a sequence of strings:\n";
  while (cin >> str)
    strings.push_back(str);

  if (strings.size() == 0) {
    cout << "No data inserted\n";
    return 1;
  }

  pair<pair<string, string>, pair<vector<string>, int>> res = find_mmm(strings);
  pair<string, string> minmax = res.first;
  pair<vector<string>, int> modes = res.second;

  cout << "The minimum of the sequence of strings is " << minmax.first << '\n'
       << "The maximum of the sequence of strings is " << minmax.second << '\n'
       << "The mode(s) of the sequence of strings is \"";

  for (size_t i = 0; i < modes.first.size(); ++i) {
    cout << modes.first[i];
    if (i != modes.first.size() - 1)
        cout << ", ";
  }
  
  cout << "\" with " << modes.second << " appearances.\n";
}

// function to find min, max, and mode(s)
pair<pair<string, string>, pair<vector<string>, int>> find_mmm(vector<string> strings) {
  map<string, int> hash;
  int freq = 0;

  for (string str : strings) {
    hash[str]++;
    if (hash[str] > freq) {
      freq = hash[str];
    }
  }

  vector<string> modes;
  string min = strings[0];
  string max = strings[0];

  for (auto pair : hash) {
    if (pair.second == freq) {
      modes.push_back(pair.first);
    }

    if (pair.first < min)
      min = pair.first;

    if (pair.first > max)
      max = pair.first;
  }

  return {{min, max}, {modes, freq}};
}
