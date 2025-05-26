import std;
using namespace std;

int main() {
  int square = 1;
  int square_rice = 1;
  int total_rice = 1;
  vector<int> milestones = {1000, 1000000, 1000000000};
  vector<int> milestone_flag(3, 0);
  int milestone_hits = 0;

  while (milestone_hits < 3) {
    cout << "Square: " << square << '\n'
         << "Number of grains on the current square: " << square_rice << '\n'
         << "Total grains: " << total_rice << "\n\n";

    for (size_t i = 0; i < 3; ++i)
      if (total_rice >= milestones[i] && milestone_flag[i] == 0) {
        cout << "At " << square << " squares, "
             << "the inventor has at least "
             << milestones[i] << " grains of rice\n\n";

        milestone_flag[i] = 1;
        ++milestone_hits;
      }

    ++square;
    square_rice *= 2;
    total_rice += square_rice;
  }
}
