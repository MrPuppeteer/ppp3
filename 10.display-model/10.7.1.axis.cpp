#include "PPP/Graph.h"         // get access to our graphics library facilities
#include "PPP/Simple_window.h" // get access to our window library

int main() {
  using namespace Graph_lib; // our graphics facilities are in Graph_lib

  Application app; // start a Graphics/GUI application

  Point tl{900, 500}; // to become top left corner of window

  Simple_window win{tl, 600, 400, "Canvas"}; // make a simple window

  Axis xa{Axis::x, Point{20, 300}, 280, 10, "x axis"}; // make an Axis
    // an Axis is a kind of Shape
    // Axis::x means horizontal
    // starting at (20,300)
    // 280 pixels long
    // with 10 "notches"
    // label the axis "x axis"

  win.attach(xa);          // attach xa to the window, win
  win.set_label("X axis"); // re-label the window
  win.wait_for_button();   // display!

  Axis ya{Axis::y, Point{20, 300}, 280, 10, "y axis"};
  ya.set_color(Color::cyan);           // choose a color for the y axis
  ya.label.set_color(Color::dark_red); // choose a color for the text
  win.attach(ya);
  win.set_label("Y axis");
  win.wait_for_button(); // display!
}
