import std;
using namespace std;

void init(vector<double>& v) {  // pass-by-reference
  for (int i = 0; i<v.size(); ++i)
    v[i] = i;
}

void g(int x) {
  vector<double> vd1(10);       // small vector
  vector<double> vd2(1000000);  // large vector
  vector<double> vd3(x);        // vector of some unknown size

  init(vd1);
  init(vd2);
  init(vd3);
}

// vector<vector<double>> v; // vector of vector of double
//
// double val = v[f(x)][g(y)]; // val is the value of v[f(x)][g(y)]
//
// double& var = v[f(x)][g(y)]; // val is the reference of v[f(x)][g(y)]
//
// var = var/2+sqrt(var);

void swap(double& d1, double& d2) {
  double temp = d1; // copy d1's value to temp
  d1 = d2;          // copy d2's value to d1
  d2 = temp;        // copy d1's old value to d2
}

int main() {
  double x = 1;
  double y = 2;
  cout << "x==" << x << " y==" << y << '\n';  // write: x==1 y==2
  swap(x,y);
  cout << "x==" << x << " y==" << y << '\n';  // write: x==2 y==1
}
