import std;
using namespace std;

struct Reading {
  int hour;           // hour after midnight [0:23]
  double temperature; // in Fahrenheit
};

int main() try {
  string iname = "raw_temps.txt";
  ifstream ist{iname};
  if (!ist) throw runtime_error("can't open input file " + iname);

  vector<double> temps;
  int hour;
  double temp;

  while (ist >> hour >> temp) {
    if (hour < 0 || hour > 23) throw runtime_error("hour out of range");
    temps.push_back(temp);
  }

  if (temps.empty()) throw runtime_error("no data in file");

  double sum = 0;
  for (double t : temps) sum += t;

  double mean = sum / static_cast<double>(temps.size());

  sort(temps.begin(), temps.end());
  double median;
  size_t mid = temps.size() / 2;

  if (temps.size() % 2 == 0) median = (temps[mid - 1] + temps[mid]) / 2;
  else median = temps[mid];

  cout << "Number of readings: " << temps.size() << '\n'
       << "Mean temperature:   " << mean << '\n'
       << "Median temperature: " << median << '\n';

} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "unexpected error!\n";
  return 2;
}
