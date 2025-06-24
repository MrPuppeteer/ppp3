import std;
using namespace std;

bool guess_check(string guess, int len);
int get_bulls(string guess, string answer);
int get_cows(string guess, string answer);

int main()
try {
  string answer = "aswu";
  int bulls = 0;
  int cows = 0;
  string guess = "0000";
  
  cout << "Welcome to Bulls and Cows (now in letters)!\n"
       << "Guess a xenodrome 4 lowercase letters\n"
       << "with 'bulls' being correct letters\n"
       << "and 'cows' being correct letters but in the wrong position\n"
       << "Your guess?\n";

  while (bulls != 4) {
    cin >> guess;

    if (!guess_check(guess, int(answer.size()))) {
      cout << "Another guess?\n";
      continue;
    }

    bulls = get_bulls(guess, answer);
    cows = get_cows(guess, answer);

    cout << "You've got " << bulls << " bulls\n"
         << "and " << cows << " cows\n";
    if (bulls != 4) cout << "Another guess?\n";
  }

  bulls == 4
      ? cout << "Congratulations! You guessed it right!\n"
      : cout << "Better luck next time!\n";

  return 0;
} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "Oops: unknown exception!\n";
  return 2;
}

bool guess_check(string guess, int len) {
  if (int(guess.length()) != len) {
    cerr << "guess must be " << len << " letters length!\n";
    return false;
  }

  for (char c : guess) {
    if (c < 'a' || c > 'z') {
      cerr << "guess must be lowercase letters!\n";
      return false;
    }
  }

  for (int i = 0; i < len - 1; ++i)
    for (int j = i + 1; j < len; ++j)
      if (guess[size_t(i)] == guess[size_t(j)]) {
        cerr << "guess must be a non-repeated letters\n";
        return false;
      }
  return true;
}

int get_bulls(string guess, string answer) {
  int len = int(answer.size());
  int bulls = 0;

  if (int(guess.size()) != len)
    throw runtime_error("guess and answer doesn't have same length!\n");

  for (int i = 0; i < len; ++i)
    if (guess[size_t(i)] == answer[size_t(i)]) ++bulls;

  return bulls;
}

int get_cows(string guess, string answer) {
  int len = int(answer.size());
  int cows = 0;

  if (int(guess.size()) != len)
    throw runtime_error("guess and answer doesn't have same length!\n");

  for (int i = 0; i < len; ++i)
    for (int j = 0; j < len; ++j)
      if (i != j && guess[size_t(i)] == answer[size_t(j)]) ++cows;

  return cows;
}
