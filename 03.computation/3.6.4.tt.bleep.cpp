// bleeps words you don't like
import std;
using namespace std;

int main() {
  vector<string> bleeps = {"Broccoli", "Fish", "Bacon", "Dog"};

  for (string word; cin >> word;) {
    bool isBleep = false;

    for (string bleep : bleeps) {
      if (word == bleep) {
        isBleep = true;
        break;
      }
    }

    if (isBleep)
      cout << "BLEEP" << '\n';
    else
      cout << word << '\n';
  }
}
