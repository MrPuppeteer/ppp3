import std;
using namespace std;

double compute_sum(const vector<double>& price, const vector<double>& weight);

int main() try {
  vector<double> price {1, 2, 3};
  vector<double> weight {1, 2, 3};

  cout << compute_sum(price, weight) << '\n';

  // vector<double> price_err {1, 2};
  // cout << compute_sum(price_err, weight) << '\n';

  return 0;
} catch (exception& e) {
  cerr << e.what() << endl;
  return 1;
} catch (...) {
  cerr << "Unknown exception!" << endl;
  return 2;
}

double compute_sum(const vector<double>& price, const vector<double>& weight) {
  if (price.size() != weight.size()) throw runtime_error("vectors have different sizes.");

  double sum {0};
  auto limit {price.size()};
  for (size_t i = 0; i < limit; ++i)
    sum += price[i] * weight[i];
  return sum;
}
