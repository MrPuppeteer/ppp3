import std;
using namespace std;

int main() {
  vector<double> values;
  double sum = 0;
  double sm = numeric_limits<double>::max();
  double lg = numeric_limits<double>::min();

  for (double val; cin >> val;) {
    if (val < sm)
      sm = val;

    if (val > lg)
      lg = val;

    sum += val;
    values.push_back(val);
  }

  cout << "the total distance: " << sum << '\n'
       << "the smallest distance between two neightboring cities: " << sm << '\n'
       << "the greatest distance between two neightboring cities: " << lg << '\n'
       << "the mean distance between two neightboring cities: "
       << sum / double(values.size()) << '\n';
}
