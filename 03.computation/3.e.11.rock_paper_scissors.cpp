import std;
using namespace std;

int main() {
  const vector<string> hands = {"rock", "paper", "scissors"};
  
  string hand = "";
  string cphand = "";
  string randomizer = "";

  int rand = 0;
  int score = 0;
  int cpscore = 0;
  
  cout << "Enter some random values!\n";
  cin >> randomizer;
  
  cout << "Rock, Paper, Scissors!\n";
  while (cin >> hand) {
    if (hand == "|")
      break;

    bool hand_rps = false;
    for (string h : hands) {
      if (h == hand) {
        hand_rps = true;
        break;
      }
    }

    if (!hand_rps) {
      cout << "Wrong input! Try again!\n"
           << "Rock, Paper, Scissors!\n";
      continue;
    }

    rand = (rand + 1) % int(randomizer.size());
    cphand = hands[size_t(randomizer[size_t(rand)]) % hands.size()];

    cout << "You choose " << hand << " and Computer choose "
         << cphand << '\n';

    if (hand[0] == cphand[0])
      cout << "DRAW!\n";

    switch (hand[0]) {
      case 'r':
        switch (cphand[0]) {
          case 's':
            cout << "You win!\n";
            score++;
            break;
          case 'p':
            cout << "Computer win!\n";
            cpscore++;
            break;
          default:
            break;
        }
        break;
      case 'p':
        switch (cphand[0]) {
          case 'r':
            cout << "You win!\n";
            score++;
            break;
          case 's':
            cout << "Computer win!\n";
            cpscore++;
            break;
          default:
            break;
        }
        break;
      case 's':
        switch (cphand[0]) {
          case 'p':
            cout << "You win!\n";
            score++;
            break;
          case 'r':
            cout << "You lose!\n";
            cpscore++;
            break;
          default:
            break;
        }
        break;
      default:
        break;
    }

    cout << "Score so far: " << score << ":" << cpscore << '\n';
  }

  cout << "Final score: " << score << ":" << cpscore << '\n';
  
  if (score > cpscore)
    cout << "You win!\n";
  else if (score < cpscore)
    cout << "Computer win!\n";
  else
    cout << "Draw!\n";
}
