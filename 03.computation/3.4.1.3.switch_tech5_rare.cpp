import std;
using namespace std;

enum checkState {
  unchecked,
  checked
};

int main() {
  checkState check = checked;
  int val = -5;

  switch (check) {
    case checked:
      if (val<0)
        val=0;
      [[fallthrough]];
    case unchecked:
      //...use val...
      break;
  }
}
