#include "PPP/Graph.h"         // get access to our graphics library facilities
#include "PPP/Simple_window.h" // get access to our window library

int main() {
  using namespace Graph_lib; // our graphics facilities are in Graph_lib

  Application app; // start a Graphics/GUI application

  Point tl{900, 500}; // to become top left corner of window

  Simple_window win{tl, 600, 400, "Canvas"}; // make a simple window

  int rect_w = (win.x_max() * 2) / 3;
  int rect_h = (win.y_max() * 3) / 4;

  int x_offset = (win.x_max() - rect_w) / 2;
  int y_offset = (win.y_max() - rect_h) / 2;

  // 1/4 inch = 24 pixels
  Rectangle frame{Point{x_offset - 24, y_offset - 24}, rect_w + 48, rect_h + 48};
  frame.set_fill_color(Color::red);
  frame.set_style(Line_style(Line_style::none, 0));
  win.attach(frame);

  Rectangle rect{Point{x_offset, y_offset}, rect_w, rect_h};
  rect.set_fill_color(Color::white);
  rect.set_style(Line_style(Line_style::none, 0));
  win.attach(rect);

  win.wait_for_button();
}
