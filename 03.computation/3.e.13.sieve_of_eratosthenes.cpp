import std;
using namespace std;

int main() {
  vector<bool> numbers(101,true);

  for (size_t i = 2; i*i <= 100; ++i) {
    if (numbers[i] == true) {
      for (size_t j = i*i; j <= 100; j += i) {
        numbers[j] = false;
      }
    }
  }

  cout << "Primes between 1 and 100:\n";
  for (size_t i = 2; i <= 100; ++i) {
    if (numbers[i] == true)
      cout << i << '\n';
  }
}
