import std;
using namespace std;

struct Point {
  int x;
  int y;
};

bool operator==(const Point &a, const Point &b) { return a.x == b.x && a.y == b.y; }

bool operator!=(const Point &a, const Point &b) { return !(a == b); }

istream& operator>>(istream& is, Point& p) {
  char ch1, ch2, ch3;
  int x, y;

  if (is >> ch1 && ch1 != '(') { // Look for (
    is.unget();
    is.clear(ios_base::failbit);
    return is;
  }

  if (is >> x >> ch2 >> y >> ch3 && ch2 == ',' && ch3 == ')') p = {x,y}; // Look for x , y )
  else is.clear(ios_base::failbit);

  return is;
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << '(' << p.x << ',' << p.y << ')';
}

void fill_into_file(vector<Point>& points, const string& name);
void fill_from_file(vector<Point>& points, const string& name);

int main() {
  vector<Point> original_points;
  cout << "Please enter seven (x,y) pairs (e.g., (1,2) (3,4) ...):\n";
  for (int i = 0; i < 7; ++i) {
    Point p;
    if (cin >> p) original_points.push_back(p);
    else {
      cout << "Invalid format! Try again.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      --i;
    }
  }

  cout << "\nOriginal points:\n";
  for (const auto &p : original_points) cout << p << " ";
  cout << "\n";

  string filename = "mydata.txt";
  fill_into_file(original_points, filename);

  vector<Point> processed_points;
  fill_from_file(processed_points, filename);

  cout << "Processed points from file:\n";
  for (const auto &p : processed_points) cout << p << " ";
  cout << '\n';

  if (original_points != processed_points) cout << "Something's wrong!\n";
}

void fill_into_file(vector<Point>& points, const string& name) {
  ofstream ost{name};
  if (!ost) throw runtime_error("can't open output file " + name);
  for (const auto& p : points) ost << p << '\n';
}

void fill_from_file(vector<Point>& points, const string& name) {
  ifstream ist{name};
  if (!ist) throw runtime_error("can't open input file " + name);
  Point temp;
  while (ist >> temp) points.push_back(temp);
}
