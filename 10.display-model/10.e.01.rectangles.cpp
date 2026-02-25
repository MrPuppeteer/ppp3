#include "PPP/Graph.h"         // get access to our graphics library facilities
#include "PPP/Simple_window.h" // get access to our window library

int main() {
  using namespace Graph_lib; // our graphics facilities are in Graph_lib

  Application app; // start a Graphics/GUI application

  Point tl{900, 500}; // to become top left corner of window

  Simple_window win{tl, 600, 400, "Canvas"}; // make a simple window

  Rectangle r{Point{50, 50}, 200, 200}; // top left corner, width, height
  win.attach(r);
  win.wait_for_button();

  Polygon poly;               // make a shape (a polygon)
  poly.add(Point{350, 50});  // add a point
  poly.add(Point{550, 50});  // add another point
  poly.add(Point{550, 250});  // add a third point
  poly.add(Point{350, 250});  // add a fourth point

  win.attach(poly); // connect poly to the window
  win.wait_for_button(); // give control to the display engine

  poly.set_color(Color::red); // adjust properties of poly
  poly.set_style(Line_style(Line_style::solid, 4));
  r.set_color(Color::blue);
  r.set_style(Line_style(Line_style::solid, 4));
  win.wait_for_button(); // give control to the display engine
}
