#include "PPP/Graph.h"
#include "PPP/Simple_window.h"
#include <cmath>
#include <numbers>

using namespace Graph_lib;

double super_pow(double base, double exp);

int main() {
  Application app;
  Point tl{100, 100};
  Simple_window win{tl, 800, 800, "Canvas"};

  double a = 250;
  double b = 250;
  double m = 0.7;
  double n = 0.7;
  int N = 24;
  Point center{400, 400};

  vector<Point> pts;
  for (int i = 0; i < N; ++i) {
    double t = (2.0 * numbers::pi * i) / N;
    double x = a * super_pow(cos(t), 2.0 / m);
    double y = b * super_pow(sin(t), 2.0 / n);
    Point p{center.x + static_cast<int>(round(x)),
            center.y - static_cast<int>(round(y))};
    pts.push_back(p);
  }

  Vector_ref<Line> lines;
  for (size_t i = 0; i < pts.size(); ++i) {
    Line *ln = new Line{pts[i], pts[(i+1) % pts.size()]};
    ln->set_color(i%14);
    ln->set_style(Line_style(Line_style::solid, 4));
    win.attach(*ln);
    lines.push_back(*ln);
  }

  // Closed_polyline superellipse;
  // for (int i = 0; i < N; ++i) superellipse.add(pts[static_cast<size_t>(i)]);
  // superellipse.set_style(Line_style(Line_style::solid, 2));
  // superellipse.set_color(Color::blue);
  // win.attach(superellipse);

  win.wait_for_button();
}

double super_pow(double base, double exp) {
  if (base == 0.0) return 0;
  double sign = (base > 0) ? 1.0 : -1.0;
  return sign * pow(abs(base), exp);
}
