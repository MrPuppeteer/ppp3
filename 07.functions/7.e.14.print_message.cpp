import std;
using namespace std;

void print_message(const string& message, int repetitions);

int main() try {
  print_message("Hello, World!", 3);
  return 0;
} catch (exception& e) {
  cerr << e.what() << endl;
  return 1;
} catch (...) {
  cerr << "Unknown exception!" << endl;
  return 2;
}

void print_message(const string& message, const int repetitions = 1) {
  if (repetitions < 1) throw runtime_error("repetitions cannot be lower than 1");
  for (int i = 0; i < repetitions; ++i) cout << message << '\n';
}
