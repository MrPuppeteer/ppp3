// convert from yen/euros/pounds to dollars
// a suffix 'y', 'e', or 'p' indicates the currency of the input
import std;
using namespace std;

int main() {
  // Data taken from XE on 4 May 2025, 4:50 PM GMT+7
  constexpr double yen_dollar_rate = 0.0068999592;
  constexpr double euro_dollar_rate = 1.1301552;
  constexpr double pound_dollar_rate = 1.3278529;

  double amount = 0;
  char currency = ' ';
  cout << "Please enter any amount of money followed by the currency (y/e/p):\n"
       << "y=yen, e=euro, p=pound\n";
  cin >> amount >> currency;

  if (currency == 'y')
    cout << "¥" << amount << " == $" << amount*yen_dollar_rate << "\n";
  else if (currency == 'e')
    cout << "€" << amount << " == $" << amount*euro_dollar_rate << '\n';
  else if (currency == 'p')
    cout << "£" << amount << " == $" << amount*pound_dollar_rate << '\n';
  else
    cout << "Sorry, I don't recognize a currency called '" << currency << "'\n";
}
