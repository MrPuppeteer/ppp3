import std;
using namespace std;

int main() {
  cout << "birthday: " << chrono::November/28/2021 << '\n';
  cout << "zt: " << chrono::zoned_time{chrono::current_zone(), chrono::system_clock::now()} << '\n';
}
