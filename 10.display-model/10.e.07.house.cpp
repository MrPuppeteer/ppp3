#include "PPP/Graph.h"         // get access to our graphics library facilities
#include "PPP/Simple_window.h" // get access to our window library

int main() {
  using namespace Graph_lib; // our graphics facilities are in Graph_lib

  Application app; // start a Graphics/GUI application

  Point tl{900, 500};
  Simple_window win{tl, 800, 600, "Canvas"};

  Rectangle ground{Point{0, 550}, 800, 50};
  ground.set_style(Line_style::none);
  ground.set_fill_color(Color::green);
  win.attach(ground);

  Rectangle base{Point{200, 300}, 400, 250};
  base.set_fill_color(Color::red);
  base.set_style(Line_style(Line_style::solid, 2));
  win.attach(base);

  Rectangle chimney{Point{480, 170}, 35, 80};
  chimney.set_style(Line_style(Line_style::solid, 2));
  chimney.set_fill_color(Color(169, 169, 169));
  win.attach(chimney);

  Polygon roof;
  roof.add(Point{200, 300}); // bottom left
  roof.add(Point{600, 300}); // bottom right
  roof.add(Point{400, 150}); // peak
  roof.set_fill_color(Color::blue);
  roof.set_style(Line_style(Line_style::solid, 2));
  win.attach(roof);

  Rectangle door{Point{360, 430}, 80, 120};
  door.set_fill_color(Color::dark_red);
  door.set_style(Line_style(Line_style::solid, 2));
  win.attach(door);

  Circle knob{Point{430, 490}, 5};
  knob.set_fill_color(Color::yellow);
  win.attach(knob);

  Rectangle win_left{Point{250, 350}, 80, 80};
  win_left.set_fill_color(Color::cyan);
  win_left.set_style(Line_style(Line_style::solid, 2));
  win.attach(win_left);

  Rectangle win_right{Point{470, 350}, 80, 80};
  win_right.set_fill_color(Color::cyan);
  win_right.set_style(Line_style(Line_style::solid, 2));
  win.attach(win_right);

  Line left_hor{Point{250, 390}, Point{330, 390}};
  Line left_ver{Point{290, 350}, Point{290, 430}};
  left_hor.set_style(Line_style(Line_style::solid, 2));
  left_ver.set_style(Line_style(Line_style::solid, 2));

  Line right_hor{Point{470, 390}, Point{550, 390}};
  Line right_ver{Point{510, 350}, Point{510, 430}};
  right_hor.set_style(Line_style(Line_style::solid, 2));
  right_ver.set_style(Line_style(Line_style::solid, 2));

  win.attach(left_hor);
  win.attach(left_ver);
  win.attach(right_hor);
  win.attach(right_ver);

  Circle s1{Point{520, 150}, 15};
  Circle s2{Point{540, 120}, 20};
  Circle s3{Point{570, 90}, 25};

  s1.set_fill_color(Color(211, 211, 211));
  s2.set_fill_color(Color(211, 211, 211));
  s3.set_fill_color(Color(211, 211, 211));

  s1.set_color(Color::invisible);
  s2.set_color(Color::invisible);
  s3.set_color(Color::invisible);

  win.attach(s1);
  win.attach(s2);
  win.attach(s3);

  win.wait_for_button();
}
