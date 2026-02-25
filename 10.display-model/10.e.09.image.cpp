#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

int main() {
  using namespace Graph_lib;

  Application app;

  Point tl{900, 500};
  Simple_window win{tl, 370, 420, "Canvas"};

  Image image{Point{50, 50}, "gentoo.png"};
  win.attach(image);

  Text caption{Point{100, 370}, "Gentoo Linux"};
  caption.set_font(Font::helvetica_bold);
  caption.set_font_size(20);
  caption.set_color(Color::dark_blue);
  win.attach(caption);

  win.set_label("Gentoo Linux");
  win.wait_for_button();
}
