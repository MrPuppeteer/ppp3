import std;
using namespace std;

int main() {
  double val = 0;
  string unit = "";

  vector<double> values;
  double sum = 0;

  double sm = numeric_limits<double>::max();
  double lg = numeric_limits<double>::min();

  while (cin >> val >> unit) {
    if (unit == "cm")
      values.push_back(val / 100);
    else if (unit == "m")
      values.push_back(val);
    else if (unit == "in")
      values.push_back(val * 2.54 / 100);
    else if (unit == "ft")
      values.push_back(val * 12 * 2.54 / 100);
    else {
      cout << "Illegal unit!\n";
      continue;
    }

    double value = values.back();
    sum += value;
    
    if (value < sm) {
      sm = value;
      cout << "the smallest so far: " << sm << "m\n";
    }

    if (value > lg) {
      lg = value;
      cout << "the largest so far: " << lg << "m\n";
    }
  }

  cout << "the smallest: " << sm << "m\n"
       << "the largest: " << lg << "m\n"
       << "the number of values: " << values.size() << '\n'
       << "the sum of values: " << sum << '\n';

  ranges::sort(values);

  cout << "values: \n";
  for (double value : values)
    cout << '\t' << value << "m\n";
}
