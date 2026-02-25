#include "PPP/Graph.h"         // get access to our graphics library facilities
#include "PPP/Simple_window.h" // get access to our window library

double dsin(double d); // chose the right sin()

int main() {
  using namespace Graph_lib; // our graphics facilities are in Graph_lib

  Application app; // start a Graphics/GUI application

  Point tl{900, 500}; // to become top left corner of window

  Simple_window win{tl, 600, 400, "My window"}; // make a simple window

  Axis xa{Axis::x, Point{20, 350}, 300, 10, "x"}; // make an Axis
    // an Axis is a kind of Shape
    // Axis::x means horizontal
    // starting at (20,300)
    // 280 pixels long
    // with 10 "notches"
    // label the axis "x axis"

  win.attach(xa);          // attach xa to the window, win
  win.set_label("X axis"); // re-label the window
  win.wait_for_button();   // display!

  Axis ya{Axis::y, Point{20, 350}, 300, 10, "y"};
  ya.set_color(Color::green);           // choose a color for the y axis
  ya.label.set_color(Color::dark_blue); // choose a color for the text
  win.attach(ya);
  win.set_label("Y axis");
  win.wait_for_button(); // display!


  Function sine{ dsin, 0, 100, Point{20, 250}, 1000, 100, 100}; // sine curve
    // plot sin() in the range [0:100) with (0,0) at (20,150)
    // using 1000 points; scale x values *50, scale y values *50

  win.attach(sine);
  win.set_label("Sine");
  win.wait_for_button();

  sine.set_color(Color::dark_red); // we changed our mind about sine’s color

  Polygon poly;              // a polygon; a Polygon is a kind of Shape
  poly.add(Point{300, 200}); // three points make a triangle
  poly.add(Point{350, 100});
  poly.add(Point{400, 200});
  poly.set_color(Color::dark_green);
  win.attach(poly);
  win.set_label("Triangle");
  win.wait_for_button();

  Rectangle r{Point{180, 150}, 100, 50}; // top left corner, width, height

  win.attach(r);
  win.set_label("Rectangle");
  win.wait_for_button();

  Closed_polyline poly_rect;
  poly_rect.add(Point{100, 50});
  poly_rect.add(Point{200, 50});
  poly_rect.add(Point{250, 75});
  poly_rect.add(Point{200, 100});
  poly_rect.add(Point{100, 100});

  win.set_label("Polyline");
  win.attach(poly_rect);
  win.wait_for_button();

  poly_rect.add(Point{50, 75});
  win.set_label("Polyline 2");
  win.wait_for_button();

  r.set_fill_color(Color::magenta); // color the inside of the rectangle
  poly.set_style(Line_style(Line_style::dash, 8));
  poly_rect.set_style(Line_style(Line_style::dashdotdot, 4));
  poly_rect.set_fill_color(Color::yellow);
  win.set_label("Fill");
  win.wait_for_button();

  Text t{Point{275, 63}, "Hello, graphical world!"};
  win.attach(t);
  win.set_label("Text");
  win.wait_for_button();

  t.set_font(Font::times_bold_italic);
  t.set_font_size(18);
  win.set_label("Bold italic text");
  win.wait_for_button();

  Image gentoo {Point{100,50},"gentoo.png"};
  win.attach(gentoo);
  win.set_label("Gentoo");
  win.wait_for_button();

  gentoo.move(250,200);
  win.set_label("Move");
  win.wait_for_button();

  Circle c{Point{100, 250}, 50};

  Ellipse e{Point{100, 250}, 75, 25};
  e.set_color(Color::dark_blue);

  Mark m{Point{100, 250}, 'o'};
  m.set_color(Color::blue);
  ostringstream oss;
  oss << "screen size: " << x_max() << "*" << y_max()
      << "; window size: " << win.x_max() << "*" << win.y_max();
  Text sizes{Point{20, 10}, oss.str()};

  Image scan{Point{275, 225}, "llq.png"};
  // scan.scale(150, 200);

  win.attach(c);
  win.attach(m);
  win.attach(e);

  win.attach(sizes);
  win.attach(scan);
  win.set_label("Final!");
  win.wait_for_button();
}

double dsin(double d) { return sin(d); } // chose the right sin()
