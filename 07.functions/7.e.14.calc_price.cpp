import std;
using namespace std;

double calc_final_price(double initial_price, double rate);

int main() {
  double initial_price {100.0};
  double rate {0.1};

  cout << "Initial price: $" << initial_price << '\n'
       << "Rate: " << rate << '\n'
       << "Final price: $" << calc_final_price(initial_price, rate) << '\n';
  return 0;
}

double calc_final_price(const double initial_price, const double rate) {
  // rate = 0.05;
  return initial_price * (1.0 + rate);
}
