import std;
using namespace std;

int main() {
  double num = 1234567.89;
  cout << "number\t\t" << "defaultfloat\t" << "fixed\t\t" << "scientific\n";
  cout << num << '\t' << defaultfloat << num << '\t' << fixed << num << '\t'
       << scientific << num << '\n' << defaultfloat;
}
