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

  double median = 0;
  if (temps.size() % 2 == 0)
    median = (temps[temps.size()/2] + temps[(temps.size()/2)-1]) / 2;
  else
    median = temps[temps.size()/2];

  cout << "Median temperature: " << median << '\n';
}
