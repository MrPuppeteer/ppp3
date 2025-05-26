import std;
using namespace std;

int main() {
  int min = 1;
  int max = 100;
  int q = 0;
  int guess = -1;
  char ans = ' ';

  cout << "Think a number between 1 and 100\n"
       << "And I will ask questions to figure out what the number is.\n";

  while (min != max) {
    if (max-min == 1) 
      guess = max;
    else
      guess = (min+max)/2;

    cout << "Is the number you are thinking of less than " << guess << "? (y/n)\n";
    cin >> ans;
    if (ans == 'y') {
      max = guess-1;
      ++q;
    } else if (ans == 'n') {
      min = guess;
      ++q;
    } else
      cout << "invalid answer!\n";
  }
  cout << "The number is " << (min+max)/2 << '\n';
  cout << "I only need " << q << " questions to guess.\n";
}
