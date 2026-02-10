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
  uniform_real_distribution<double> dist_f(60.0, 85.0);
  uniform_real_distribution<double> dist_c(15.0, 30.0);
  uniform_int_distribution<int> unit_choice(0, 1); // 0 for F, 1 for C

  const int total_readings = 50;

  for (int i = 0; i < total_readings; ++i) {
    int hour = i % 24;
    char unit = (unit_choice(re) == 0) ? 'f' : 'c';
    double temp = (unit == 'f') ? dist_f(re) : dist_c(re);

    ost << hour << ' ' << temp << ' ' << unit << '\n';
  }

  cout << "Successfully created " << oname << " with " << total_readings << " readings.\n";

} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "unexpected error!\n";
  return 2;
}
