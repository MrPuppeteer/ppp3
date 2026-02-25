#include "PPP/Graph.h"         // get access to our graphics library facilities
#include "PPP/Simple_window.h" // get access to our window library

int main() {
  using namespace Graph_lib; // our graphics facilities are in Graph_lib

  Application app; // start a Graphics/GUI application

  Point tl{900, 500}; // to become top left corner of window

  Simple_window win{tl, 600, 400, "Canvas"}; // make a simple window

  Rectangle sh{Point{0, 0}, 800, 300};
  sh.set_fill_color(Color::blue);
  sh.set_style(Line_style(Line_style::none, 0));
  win.attach(sh);

  win.wait_for_button();
}
