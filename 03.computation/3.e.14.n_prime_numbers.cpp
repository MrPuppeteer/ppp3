import std;
using namespace std;

bool isPrime(int x, vector<int> primes);

int main() {
  vector<int> primes = {2};

  size_t n = 0;
  cout << "How many number of primes do you want to find?\n";
  cin >> n;

  for (int i = 3; primes.size() < n; ++i) {
    if (isPrime(i, primes))
      primes.push_back(i);
  }

  cout << "The first " << n << " primes:\n";
  for (int p : primes) {
    cout << p << '\n';
  }
}

bool isPrime(int x, vector<int> primes) {
  for (int p : primes) {
    if (x % p == 0)
      return false;
  }
  return true;
}


