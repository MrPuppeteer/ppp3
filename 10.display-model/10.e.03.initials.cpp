#include "PPP/Graph.h"         // get access to our graphics library facilities
#include "PPP/Simple_window.h" // get access to our window library

int main() {
  using namespace Graph_lib; // our graphics facilities are in Graph_lib

  Application app; // start a Graphics/GUI application

  Point tl{900, 500}; // to become top left corner of window

  Simple_window win{tl, 600, 400, "Canvas"}; // make a simple window

  Text x{Point{150, 125}, "X"};
  Text r{Point{285, 125}, "R"};
  win.attach(r);
  win.attach(x);
  win.set_label("Text");

  x.set_font(Font::times_bold);
  r.set_font(Font::times_bold);
  x.set_font_size(150);
  r.set_font_size(150);
  x.set_color(Color::dark_magenta);
  r.set_color(Color::dark_green);
  win.set_label("initials");
  win.wait_for_button();
}
