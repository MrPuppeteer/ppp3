import std;
using namespace std;

class Name_value {
public:
  string name;
  int value;
  Name_value(string n, int v) : name{n}, value{v} {}
};

bool check_name(string name, vector<Name_value> names_values);

vector<int> find_score(int score, vector<Name_value> names_values);

int main() {
  vector<Name_value> names_scores;
  string name;
  int score;

  cout << "Enter a set of name-and-value pairs: ";

  while (cin >> name >> score) {
    if (name == "NoName" && score == 0)
      break;

    if (check_name(name, names_scores)) {
      cout << "Error: Name '" << name << "' is entered twice!\n";
      continue;
    }

    names_scores.push_back(Name_value{name, score});
  }

  cout << "Enter a score to output all the corresponding name with that "
          "score:\n";

  while (cin >> score) {
    vector<int> indexes = find_score(score, names_scores);

    if (indexes[0] == -1) {
      cout << "score not found\n";
      continue;
    }

    for (int i : indexes) {
      cout << names_scores[size_t(i)].name << ' ';
    }
    cout << '\n';
  }
}

bool check_name(string name, vector<Name_value> names_values) {
  for (Name_value nv : names_values) {
    if (name == nv.name)
      return true;
  }
  return false;
}

vector<int> find_score(int score, vector<Name_value> names_values) {
  vector<int> res;

  for (size_t i = 0; i < names_values.size(); ++i) {
    if (score == names_values[i].value)
      res.push_back(int(i));
  }

  if (res.size() == 0)
    res.push_back(-1);

  return res;
}
