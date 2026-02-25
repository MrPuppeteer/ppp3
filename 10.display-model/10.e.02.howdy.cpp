#include "PPP/Graph.h"         // get access to our graphics library facilities
#include "PPP/Simple_window.h" // get access to our window library

int main() {
  using namespace Graph_lib; // our graphics facilities are in Graph_lib

  Application app; // start a Graphics/GUI application

  Point tl{900, 500}; // to become top left corner of window

  Simple_window win{tl, 600, 400, "Canvas"}; // make a simple window

  Rectangle r{Point{50, 50}, 100, 30}; // top left corner, width, height
  win.attach(r);
  win.wait_for_button();

  Text t{Point{70, 55}, "Howdy!"};
  win.attach(t);
  win.wait_for_button();
}
