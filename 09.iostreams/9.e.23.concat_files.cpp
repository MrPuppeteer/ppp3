import std;
using namespace std;

int main() try {
  string file1, file2, output_file;

  cout << "Enter the first source file name: ";
  cin >> file1;
  cout << "Enter the second source file name: ";
  cin >> file2;
  cout << "Enter the name for the merged output file: ";
  cin >> output_file;

  ifstream ifs1{file1};
  if (!ifs1) throw runtime_error("could not open " + file1);

  ifstream ifs2{file2};
  if (!ifs2) throw runtime_error("could not open " + file2);

  ofstream ofs{output_file};
  if (!ofs) throw runtime_error("could not create " + output_file);

  ofs << ifs1.rdbuf();
  ofs << ifs2.rdbuf();

  cout << "Success! " << file1 << " and " << file2 << " have been merged into "
       << output_file << ".\n";
} catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  return 1;
} catch (...) {
  cerr << "unexpected error!\n";
  return 2;
}
