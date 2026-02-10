import std;
using namespace std;

// struct Reading {
//   int hour;           // hour after midnight [0:23]
//   double temperature; // in Fahrenheit
// };

int main() try {
  string oname = "raw_temps.txt";
  ofstream ost{oname};
  if (!ost) throw runtime_error("can't open output file " + oname);

  default_random_engine re;
  uniform_real_distribution<double> temp_dist(60.0, 85.0);

  const int total_readings = 50;

  for (int i = 0; i < total_readings; ++i) {
    int hour = i % 24;
    double temperature = temp_dist(re);

    ost << hour << ' ' << temperature << '\n';
  }

  cout << "Successfully created " << oname << " with " << total_readings << " readings.\n";

} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "unexpected error!\n";
  return 2;
}
