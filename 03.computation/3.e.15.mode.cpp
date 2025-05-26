import std;
using namespace std;

pair<vector<int>, int> find_mode(vector<int> numbers);

int main() {
  vector<int> numbers;
  int n;

  cout << "Insert a series of positive integers:\n";
  while (cin >> n)
    numbers.push_back(n);

  if (numbers.size() == 0) {
    cout << "No data inserted\n";
    return 1;
  }

  pair<vector<int>, int> res = find_mode(numbers);
  vector<int> modes = res.first;
  int max = res.second;

  cout << "The mode(s) of the series of numbers is ";

  for (int m : modes)
    cout << m << " ";
  
  cout << "with " << max << " appearances.\n";
}

pair<vector<int>, int> find_mode(vector<int> numbers) {
  map<int, int> hash;
  int max = 0;

  for (int num : numbers) {
    hash[num]++;
    if (hash[num] > max) {
      max = hash[num];
    }
  }

  vector<int> modes;
  for (auto pair : hash) {
    if (pair.second == max) {
      modes.push_back(pair.first);
    }
  }

  return {modes, max};
}
