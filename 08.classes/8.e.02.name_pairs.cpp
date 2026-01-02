import std;
using namespace std;

class Name_pairs {
public:
  void read_names();
  void read_ages();
  void print() const;
  void sort();
private:
  const string stop {"stop"};
  vector<string> names;
  vector<double> ages;
  bool is_in(const string& n) const;
  size_t name_idx(const string& n) const;
};

bool Name_pairs::is_in(const string& n) const {
  for (string name : names) if (n == name) return true;
  return false;
}

void Name_pairs::read_names() {
  cout << "Write people names (write " << stop <<  " when there's enough)...\n: ";
  string name;
  while (cin >> name && name != stop) {
    if (is_in(name)) cout << "Duplicated name " << name << "! Try again...\n";
    else names.push_back(name);
    cout << ": ";
  }
}

void Name_pairs::read_ages() {
  if (names.size() == 0) {
    throw runtime_error("Please provide the names first!");
  }
  cout << "Give the ages of each person...\n";
  for (string name : names) {
    cout << "How old is " << name << "? ";
    double age {0};
    while (!(cin >> age) || age < 0) {
      cout << "Input invalid. How old is " << name << "? ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    ages.push_back(age);
  }
}

size_t Name_pairs::name_idx(const string& n) const {
  size_t limit = names.size();
  for (size_t i = 0; i < limit; ++i) if (names[i] == n) return i;
  throw runtime_error("No element found!");
}

void Name_pairs::sort() {
  if (names.size() != ages.size()) throw runtime_error("names and ages sizes differ");
  vector<string> sorted_names {names};
  vector<double> sorted_ages {ages};

  using std::sort;
  sort(sorted_names.begin(), sorted_names.end());
  size_t limit = sorted_names.size();
  for (size_t i = 0; i < limit; ++i) sorted_ages[i] = ages[name_idx(sorted_names[i])];

  names = sorted_names;
  ages = sorted_ages;
}

void Name_pairs::print() const {
  if (names.size() != ages.size()) throw runtime_error("names and ages sizes differ");
  size_t limit = names.size();
  for (size_t i = 0; i < limit; ++i) cout << "\t(" << names[i] << ", " << ages[i] << ")\n";
}

int main() try {
  Name_pairs pairs;

  pairs.read_names();
  pairs.read_ages();
  cout << "\nOK! So you tell me about these people are:\n";
  pairs.print();
  pairs.sort();
  cout << "\nThat sorted alphabetically by name are:\n";
  pairs.print();
  cout << '\n';

  return 0;
} catch (exception& e) {
  cerr << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "Unknown exception!\n";
  return 2;
}
