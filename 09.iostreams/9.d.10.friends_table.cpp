import std;
using namespace std;

int main() {
  vector<vector<string>> friends = {
    {"Nuriksan", "Bagas", "081234567890", "bagasn@gmail.com"},
    {"Taylor", "Andy", "082345678901", "andyt@gmail.com"},
    {"Stone", "Brett", "083456789012", "brett_stone@gmail.com"},
    {"Watson", "Chelsea", "084567890123", "chls.wtsn@gmail.com"},
    {"Daniel", "David", "085678901234", "da.dan@gmail.com"},
    {"Erika", "Eric", "086789012345", "erika@gmail.com"}
  };

  cout << "Last Name\t" << "First Name\t" << "Phone Number\t" << "Email\n";
  for (const auto& f : friends)
    cout << setw(9) << f[0] << '\t' << setw(10) << f[1] << '\t' << f[2] << '\t' << f[3] << '\n';
}
