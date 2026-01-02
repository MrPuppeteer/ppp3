import std;
using namespace std;

bool leapyear(int y);

int main() {
  constexpr int inc {5};

  for (int i = 1700; i < 2200; i+=inc) {
    cout << i << ": ";
    if (leapyear(i)) cout << "Leap year\n";
    else cout << "Common year\n";
  }
}

bool leapyear(int y) {
  return (((y % 4 == 0) && !(y % 100 == 0)) || (y % 400 == 0));
}
