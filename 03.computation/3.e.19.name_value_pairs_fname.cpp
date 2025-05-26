import std;
using namespace std;

bool check_name(string name, vector<string> names);

int find_name(string name, vector<string> names);

int main() {
  vector<string> names;
  vector<int> scores;
  string name;
  int score;

  cout << "Enter a set of name-and-value pairs: ";

  while (cin >> name >> score) {
    if (name == "NoName" && score == 0)
      break;

    if (check_name(name, names)) {
      cout << "Error: Name '" << name << "' is entered twice!\n";
      continue;
    }
    
    names.push_back(name);
    scores.push_back(score);
  }

  cout << "Enter a name to output the corresponding score:\n";

  while (cin >> name) {
    int idx = find_name(name, names);

    if (idx == -1) {
      cout << "name not found\n";
      continue;
    }
    
    cout << scores[size_t(idx)] << '\n';
  }
}

bool check_name(string name, vector<string> names) {
  for (string n : names) {
    if (name == n)
      return true;
  }
  return false;
}

int find_name(string name, vector<string> names) {
  for (size_t i = 0; i < names.size(); ++i) {
    if (name == names[i])
      return int(i);
  }
  return -1;
}
