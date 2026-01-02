import std;
using namespace std;

class Name_pair {
public:
  Name_pair(string n): name{n} {}

  string get_name() const { return name; }
  double get_age() const { return age; }
  void set_age(double a) {
    if (a < 0) throw runtime_error("Age cannot be below 0");
    age = a;
  }
private:
  string name;
  double age {0};
};

bool operator<(const Name_pair& a, const Name_pair& b) {
    return a.get_name() < b.get_name();
}

bool operator==(const Name_pair& a, const Name_pair& b) {
    return (a.get_name() == b.get_name() && a.get_age() == b.get_age());
}

class Name_pairs {
public:
  void read_names();
  void read_ages();
  void sort();
  vector<string> get_names() const;
  vector<double> get_ages() const;
  const vector<Name_pair>& get_pairs() const { return name_pairs; }
private:
  const string stop {"stop"};
  vector<Name_pair> name_pairs;
  bool is_in(const string& n) const;
};

bool Name_pairs::is_in(const string& n) const {
  for (const Name_pair& np : name_pairs) if (n == np.get_name()) return true;
  return false;
}

void Name_pairs::read_names() {
  cout << "Write people names (write " << stop <<  " when there's enough)...\n: ";
  string name;
  while (cin >> name && name != stop) {
    if (is_in(name)) cout << "Duplicated name " << name << "! Try again...\n";
    else name_pairs.push_back(Name_pair{name});
    cout << ": ";
  }
}

void Name_pairs::read_ages() {
  if (name_pairs.size() == 0) {
    throw runtime_error("Please provide the names first!");
  }
  cout << "Give the ages of each person...\n";
  for (Name_pair& np : name_pairs) {
    cout << "How old is " << np.get_name() << "? ";
    double age {0};
    while (!(cin >> age) || age < 0) {
      cout << "Input invalid. How old is " << np.get_name() << "? ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    np.set_age(age);
  }
}

void Name_pairs::sort() {
  using std::sort;
  sort(name_pairs.begin(), name_pairs.end());
}

vector<string> Name_pairs::get_names() const {
  vector<string> names;
  for (const Name_pair& np : name_pairs) names.push_back(np.get_name());
  return names;
}
vector<double> Name_pairs::get_ages() const {
  vector<double> ages;
  for (const Name_pair& np : name_pairs) ages.push_back(np.get_age());
  return ages;
}

ostream& operator<<(ostream& os, const Name_pairs& np) {
  const vector<Name_pair>& pairs {np.get_pairs()};

  for (const Name_pair& pair : pairs) os << "\t(" << pair.get_name() << ", " << pair.get_age() << ")\n";
  return os;
}

bool operator==(const Name_pairs& a, const Name_pairs& b) {
  const vector<Name_pair>& pairs_a = a.get_pairs();
  const vector<Name_pair>& pairs_b = b.get_pairs();

  return pairs_a == pairs_b;
}

bool operator!=(const Name_pairs& a, const Name_pairs& b) {
  return !(a == b);
}

int main() try {
  Name_pairs pairs;

  pairs.read_names();
  pairs.read_ages();
  cout << "\nOK! So you tell me about these people are:\n";
  cout << pairs;
  pairs.sort();
  cout << "\nThat sorted alphabetically by name are:\n";
  cout << pairs;
  cout << '\n';

  Name_pairs etc;
  etc.read_names();
  etc.read_ages();
  etc.sort();
  cout << "\nOK! So you tell me about these people are:\n";
  cout << etc;
  if (pairs == etc) cout << "Exactly the same people!\n";
  else if (pairs != etc) cout << "Just another set of people.\n";

  return 0;
} catch (exception& e) {
  cerr << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "Unknown exception!\n";
  return 2;
}
