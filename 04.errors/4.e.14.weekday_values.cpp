import std;
using namespace std;

const array<array<string, 6>, 7> weekday_names = {{
    {"Sunday", "sunday", "SUNDAY", "Sun", "sun", "SUN"},
    {"Monday", "monday", "MONDAY", "Mon", "mon", "MON"},
    {"Tuesday", "tuesday", "TUESDAY", "Tue", "tue", "TUE"},
    {"Wednesday", "wednesday", "WEDNESDAY", "Wed", "wed", "WED"},
    {"Thursday", "thursday", "THURSDAY", "Thu", "thu", "THU"},
    {"Friday", "friday", "FRIDAY", "Fri", "fri", "FRI"},
    {"Saturday", "saturday", "SATURDAY", "Sat", "sat", "SAT"}
}};

int get_day_idx(string name);

int main()
try {
  vector<vector<int>> values(7);
  int reject = 0;
  pair<string, int> day_val;

  cout << "Insert pairs of a day of the week and a value\n"
       << "e.g. Tuesday 23\tMon -3\tthursday 99\n"
       << "End your input with Ctrl+Z (Windows) or Ctrl-D (Linux)\n";

  while (cin >> day_val.first >> day_val.second) {
    int day_idx = get_day_idx(day_val.first);
    if (day_idx == -1) {
      cerr << day_val.first << ' ' << day_val.second
           << " is rejected since it's not a day of the week.\n";
      ++reject;
      continue;
    }

    values[size_t(day_idx)].push_back(day_val.second);
  }

  if (!cin.eof()) throw runtime_error("bad input!");

  cout << "\nNumber of rejected values: " << reject << "\n\n";
  for (size_t i = 0; i < 7; ++i) {
    cout << weekday_names[i][0] << " values: ";
    
    int sum = 0;
    for (size_t j = 0; j < values[i].size(); ++j) {
      cout << values[i][j] << ' ';
      sum += values[i][j];
    }

    cout << "\nThe sum of the values in " << weekday_names[i][0]
         << " is " << sum << "\n\n";
  }

  return 0;
} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "Oops: unknown exception!\n";
  return 2;
}

int get_day_idx(string name) {
  int idx = -1;

  for (size_t i = 0; i < 7; ++i) {
    for (string n : weekday_names[i])
      if (n == name) {
        idx = int(i);
        return idx;
      }
  }

  return idx;
}
