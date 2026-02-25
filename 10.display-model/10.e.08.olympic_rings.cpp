#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

int main() {
  using namespace Graph_lib;

  Application app;

  Point tl{900, 500};
  Simple_window win{tl, 600, 400, "Canvas"};

  int radius = 50;
  int thickness = 10;

  Circle blue_ring{Point{150, 150}, radius};
  blue_ring.set_color(Color::blue);
  blue_ring.set_style(Line_style(Line_style::solid, thickness));
  win.attach(blue_ring);

  Circle black_ring{Point{275, 150}, radius};
  black_ring.set_color(Color::black);
  black_ring.set_style(Line_style(Line_style::solid, thickness));
  win.attach(black_ring);

  Circle red_ring{Point{400, 150}, radius};
  red_ring.set_color(Color::red);
  red_ring.set_style(Line_style(Line_style::solid, thickness));
  win.attach(red_ring);

  Circle yellow_ring{Point{212, 200}, radius};
  yellow_ring.set_color(Color::yellow);
  yellow_ring.set_style(Line_style(Line_style::solid, thickness));
  win.attach(yellow_ring);

  Circle green_ring{Point{337, 200}, radius};
  green_ring.set_color(Color::green);
  green_ring.set_style(Line_style(Line_style::solid, thickness));
  win.attach(green_ring);

  win.wait_for_button();
}
