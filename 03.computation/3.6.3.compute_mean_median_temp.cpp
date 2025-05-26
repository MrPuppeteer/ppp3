// compute mean and median temperatures
import std;
using namespace std;

int main() {
  vector<double> temps;         // temperatures
  for (double temp; cin>>temp;) // read into temp
    temps.push_back(temp);      // put temp into vector

  // compute mean temperature:
  double sum = 0;
  for (double x : temps)
    sum += x;
  cout << "Average temperature: " << sum/double(temps.size()) << '\n';

  // compute median temperature:
  ranges::sort(temps);
  cout << "Median temperature: " << temps[temps.size()/2] << '\n';
}
