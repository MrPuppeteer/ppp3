// find repeated words
import std;
using namespace std;

int main() {
  int number_of_words = 0;
  string previous;          // previous word; initialized to ""
  string current;
  while (cin>>current) {
    ++number_of_words;      // increase word count
    if (previous == current)
      cout << "word number " << number_of_words << " repeated: " << current << '\n';
    previous = current;
  }
}
