import std;
using namespace std;

int main() {
  cout << "Please enter input file name: ";
  string iname;
  cin >> iname;
  ifstream ist{iname};  // ist is an input stream for the file named name
  if (!ist) throw runtime_error("can't open input file " + iname);

  vector<Point> points;
  for (Point p; ist>>p;) points.push_back(p);

  cout << "Please enter name of output file: ";
  string oname;
  cin >> oname;
  ofstream ost {oname}; // ost is an output stream for a file named oname
  if (!ost) throw runtime_error("can't open output file " + oname);

  for (Point p : points) ost << '(' << p.x << ',' << p.y << ")\n";
}

void fill_from_file(vector<Point>& points, string& name) {
  ifstream ist {name};  // open file for reading
  if (!ist) throw runtime_error("can't open input file " + name);
  // ... use ist ...
  // the file is implicitly closed when we leave the function
}


void fill_from_file2(vector<Point>& points, string& name) {
  ifstream ifs;
  ifs.open(name, ios::in);  // open file named name for reading
  // ...
  ifs.close(); // close file
}
