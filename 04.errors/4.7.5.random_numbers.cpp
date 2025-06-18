import std;
using namespace std;

default_random_engine& get_rand();

// seed s
void seed(int s);

// seed with a really unpredictable value
void seed();

int random_int(int min, int max);

int random_int(int max);

// generate a string with between 4 and 24 random lower-case characters
string random_letters(int n, int m);

// generate n random (name, value) pairs
vector<pair<string, int>> generate(int n);

int main() {
  // default_random_engine engine;             // the simplest engine
  // uniform_int_distribution<int> dist(1,6);  // the distribution we want
  // for (int i = 0; i<10; ++i)
  //   cout << dist(engine) << ' ';            // get a value from the distribution using the engine

  // default_random_engine engine2(7777);      // use 7777 instead of the default starting value
  // // ...
  // engine2.seed(9876)                        // start a new sequence from 9876

  for (int i=0; i<10; ++i)
    cout << random_int(1,6) << ' ';         // get a value from the distribution using the engine
}

default_random_engine& get_rand() {
  static default_random_engine ran;
  return ran;
}

void seed(int s) { get_rand().seed(size_t(s)); }

void seed() { get_rand().seed(); }

int random_int(int min, int max) {
  return uniform_int_distribution<>{min, max}(get_rand());
}

int random_int(int max) {
  return random_int(0, max);
}

string random_letters(int n, int m) {
  string s(size_t(random_int(n, m)),'x');           // a string with a size in the [n:m] range
  for (char& ch : s)
    ch = static_cast<char>(random_int('a','z')); // a lower-case letter
  return s;
}

vector<pair<string, int>> generate(int n) {
  vector <pair<string, int>> res;
  for (int i = 0; i < n; ++i)
    res.push_back({random_letters(4,24),random_int(1'000'000)});
  return res;
}
