import std;
using namespace std;

// extract {x,y} from "(x,y)"
Point get_coordinates(const string& s) {
  istringstream is {s}; // make a stream so that we can read from s
  Point xy;
  char left_paren, ch, right_paren;
  is >> left_paren >> xy.x >> ch >> xy.y >> right_paren;
  if (!is || left_paren !='(' || ch!=',' || right_paren!=')')
    throw runtime_error("format error: " + s);
  return xy;
}

int main() {
  // testing
  auto c1 = get_coordinates("(2,3)");
  auto c2 = get_coordinates("( 200, 300) ");
  auto c3 = get_coordinates("100,400"); // will call error()
  
  int seq_no = get_next_number(); // get the number of a log file
  ostringstream name;
  name << "myfile" << seq_no << ".log"; // e.g., myfile17.log
  ofstream logfile{name.str()}; // e.g., open myfile17.log

  name << "myfile" << setw(6) << setfill('0') << seq_no << ".log"; // e.g., myfile000017.log
}
