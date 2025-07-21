import std;
using namespace std;

struct Stats {
  double max {0};
  double min {0};
  double mean {0};
  double median {0};
};

void print_dv(const string& label, const vector<double>& v);

void print_stats(const Stats& stats);

double mean(const vector<double>& v);

double median(const vector<double>& v);

Stats get_stats(const vector<double>& v);

// void get_stats(const vector<double>& v, Stats& stats);

int main() try {
  // Mean: 5.28571, Median: 6
  vector<double> odd {3, 9, 1, 8, 7, 6, 3};
  // Mean: 4.75, Median: 4.5
  vector<double> even {4, 1, 9, 8, 5, 3, 2, 6};
  // Stats odd_stats;
  // Stats even_stats;

  print_dv("Odd (number of elements) data", odd);
  print_stats(get_stats(odd));
  // get_stats(odd, odd_stats);
  // print_stats(odd_stats);
  cout << '\n';

  print_dv("Even (number of elements) data", even);
  print_stats(get_stats(even));
  // get_stats(even, even_stats);
  // print_stats(even_stats);
  cout << '\n';
} catch (exception& e) {
  cerr << e.what() << endl;
  return 1;
} catch (...) {
  cerr << "Unknown exception!" << endl;
  return 2;
}

void print_dv(const string& label, const vector<double>& v) {
  cout << label << ": { ";
  for (double i : v)
    cout << i << ' ';
  cout << "}\n";
}

void print_stats(const Stats& stats) {
  cout << "Statistics:\n"
       << "\tMin: " << stats.min << '\n'
       << "\tMax: " << stats.max << '\n'
       << "\tMean: " << stats.mean << '\n'
       << "\tMedian: " << stats.median << '\n';
}

double mean(const vector<double>& v) {
  double sum {0};
  for (double d : v) sum += d;
  return sum / double(v.size());
}

double median(const vector<double>& v) {
  if ((v.size()%2) == 1) return v[v.size()/2];
  auto idx {v.size()/2};
  return (v[idx-1] + v[idx]) / 2;
}

Stats get_stats(const vector<double>& v) {
  vector<double> sorted_v {v};
  sort(sorted_v.begin(), sorted_v.end());
  Stats stats;
  stats.min = sorted_v[0];
  stats.max = sorted_v[sorted_v.size()-1];
  stats.mean = mean(sorted_v);
  stats.median = median(sorted_v);

  return stats;
}

// void get_stats(const vector<double>& v, Stats& stats) {
//   vector<double> sorted_v {v};
//   sort(sorted_v.begin(), sorted_v.end());
//   stats.min = sorted_v[0];
//   stats.max = sorted_v[sorted_v.size()-1];
//   stats.mean = mean(sorted_v);
//   stats.median = median(sorted_v);
// }
