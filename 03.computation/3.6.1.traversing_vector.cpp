import std;
using namespace std;

int main() {
  vector<int> v = {5, 7, 9, 4, 6, 8};

  for (size_t i = 0; i<v.size(); ++i)
    cout << v[i] << '\n';

  for (int x : v)         // for each x in v
    cout << x << '\n';
}
