#include "PPP/Graph.h"         // get access to our graphics library facilities
#include "PPP/Simple_window.h" // get access to our window library

int main() {
  using namespace Graph_lib; // our graphics facilities are in Graph_lib

  Application app; // start a Graphics/GUI application

  Point tl{900, 500}; // to become top left corner of window

  Simple_window win{tl, 600, 600, "Canvas"}; // make a simple window

  Rectangle r1{Point{0, 0}, 200, 200};
  Rectangle r2{Point{200, 0}, 200, 200};
  Rectangle r3{Point{400, 0}, 200, 200};
  Rectangle r4{Point{0, 200}, 200, 200};
  Rectangle r5{Point{200, 200}, 200, 200};
  Rectangle r6{Point{400, 200}, 200, 200};
  Rectangle r7{Point{0, 400}, 200, 200};
  Rectangle r8{Point{200, 400}, 200, 200};
  Rectangle r9{Point{400, 400}, 200, 200};

  r1.set_fill_color(Color::white);
  r2.set_fill_color(Color::red);
  r3.set_fill_color(Color::white);
  r4.set_fill_color(Color::red);
  r5.set_fill_color(Color::white);
  r6.set_fill_color(Color::red);
  r7.set_fill_color(Color::white);
  r8.set_fill_color(Color::red);
  r9.set_fill_color(Color::white);

  r1.set_style(Line_style(Line_style::none, 0));
  r2.set_style(Line_style(Line_style::none, 0));
  r3.set_style(Line_style(Line_style::none, 0));
  r4.set_style(Line_style(Line_style::none, 0));
  r5.set_style(Line_style(Line_style::none, 0));
  r6.set_style(Line_style(Line_style::none, 0));
  r7.set_style(Line_style(Line_style::none, 0));
  r8.set_style(Line_style(Line_style::none, 0));
  r9.set_style(Line_style(Line_style::none, 0));

  win.attach(r1);
  win.attach(r2);
  win.attach(r3);
  win.attach(r4);
  win.attach(r5);
  win.attach(r6);
  win.attach(r7);
  win.attach(r8);
  win.attach(r9);

  win.wait_for_button();
}
