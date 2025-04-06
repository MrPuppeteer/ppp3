import std;
using namespace std;

int main() {
  string first_name = "";
  cout << "Enter the name of the person you want to write to: ";
  cin >> first_name;

  string friend_name = "";
  cout << "Enter the name of another friend: ";
  cin >> friend_name;

  int age = 0;
  cout << "Enter the age of the recipient: ";
  cin >> age;

  if (age <= 0 || age >= 110) {
		cerr << "error: you're kidding!" << '\n';
		exit(1);
  }

  cout << "\nDear " << first_name << ", \n"
       << "\tHow are you? I am fine. I miss you.\n"
       << "Have you seen " << friend_name << " lately?\n"
       << "I hear you just had a birthday and you are " << age << " years old.\n";

  if (age < 12)
    cout << "Next year you will be " << age+1 << ".\n";
  else if (age == 17)
    cout << "Next year you will be able to vote.\n";
  else if (age > 70)
    cout << "Are you retired?\n";

  cout << "\nYours sincerely,\n\nBagas\n";
}
