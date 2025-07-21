import std;
using namespace std;

// Checks if string s is already present on vector v
bool check_dupl(const vector<string>& v, const string& s);

// Read max string n into vector names, no duplicate allowed
void get_names(vector<string>& names, size_t max);

// get ages for people in vector names
void get_ages(const vector<string>& names, vector<double>& ages);

void print_pairs(const vector<string>& names, const vector<double>& ages);

size_t find_idx_name(const vector<string>& names, const string& name);

void sort_pairs(vector<string>& names, vector<double>& ages);

int main() try {
  vector<string> names;
  vector<double> ages;
  constexpr size_t max {5};

  get_names(names, max);
  get_ages(names, ages);

  cout << "\nOK! So the people you mentioned are:\n";
  print_pairs(names, ages);

  sort_pairs(names, ages);
  cout << "\nThat sorted by name are:\n";
  print_pairs(names, ages);
  cout << '\n';

  return 0;
} catch (exception& e) {
  cerr << e.what() << endl;
  return 1;
} catch (...) {
  cerr << "Unknown exception!" << endl;
  return 2;
}

bool check_dupl(const vector<string>& v, const string& s) {
  for (string x : v)
    if (x == s) return true;
  return false;
}

void get_names(vector<string>& names, size_t max) {
  cout << "Write " << max << " people names...\n";
  for (size_t i = 0; i < max; ++i) {
    cout << ": ";
    string n;
    while (cin >> n && check_dupl(names, n)) {
      cout << "Duplicated name " << n << "! Try again...\n: ";
    }
    names.push_back(n);
  }
}

void get_ages(const vector<string>& names, vector<double>& ages) {
  cout << "Give me the ages of each person...\n";
  for (string name : names) {
    cout << "How old is " << name << "? ";
    double age {0};
    while (!(cin >> age)) {
      cout << "Sorry, I don't understand what you mean...\n"
           << "How old is " << name << "? ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    ages.push_back(age);
  }
}

void print_pairs(const vector<string>& names, const vector<double>& ages) {
  auto limit = names.size();
  for (size_t i = 0; i < limit; ++i)
    cout << "  " << names[i] << " is " << ages[i] << " years old.\n";
}

size_t find_idx_name(const vector<string>& names, const string& name) {
  auto limit = names.size();
  for (size_t i = 0; i < limit; ++i)
    if (names[i] == name) return i;
  throw runtime_error("No element found!");
}

void sort_pairs(vector<string>& names, vector<double>& ages) {
  vector<string> og_names {names};
  vector<double> og_ages {ages};

  sort(names.begin(), names.end());
  auto limit = names.size();
  for (size_t i = 0; i < limit; ++i)
    ages[i] = og_ages[find_idx_name(og_names, names[i])];
}
