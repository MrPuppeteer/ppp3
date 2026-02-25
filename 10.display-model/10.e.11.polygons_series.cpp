#include "PPP/Graph.h"
#include "PPP/Simple_window.h"
#include <cmath>
#include <numbers>

using namespace Graph_lib;

Point interpolate(Point p1, Point p2, double t);

int main() {
  Application app;
  Simple_window win{Point{100, 100}, 800, 800, "Canvas"};

  const double PI = numbers::pi;
  Point center{400, 400};
  double radius = 350;
  int outer_n = 10;
  int inner_n = 3;

  Vector_ref<Closed_polyline> polys;

  // base polygon
  Closed_polyline *curr = new Closed_polyline;
  for (int i = 0; i < outer_n; ++i) {
    double angle = (2 * PI * i / outer_n) - (PI / 2);
    curr->add(Point{
        static_cast<int>(round(center.x + radius * cos(angle))),
        static_cast<int>(round(center.y + radius * sin(angle)))
    });
  }

  win.attach(*curr);
  polys.push_back(*curr);

  for (int n = outer_n - 1; n >= inner_n; --n) {
    Closed_polyline *next = new Closed_polyline;

    int n_sides_outer = curr->number_of_points();

    for (int i = 0; i < n; ++i) {
      double t_total = static_cast<double>(i) / n;
      double segment_idx_dbl;
      double t_segment = modf(t_total * n_sides_outer, &segment_idx_dbl);

      int idx1 = static_cast<int>(segment_idx_dbl);
      int idx2 = (idx1 + 1) % n_sides_outer;

      next->add(interpolate(curr->point(idx1), curr->point(idx2), t_segment));
    }

    win.attach(*next);
    polys.push_back(*next);

    curr = next;
  }

  win.wait_for_button();

  for (int n = 0; n < polys.size(); ++n) {
    polys[n].set_color(Color(n));
    polys[n].set_style(Line_style(Line_style::solid, 4));
  }

  win.wait_for_button();
}

Point interpolate(Point p1, Point p2, double t) {
  int x = static_cast<int>(round(p1.x + (p2.x - p1.x) * t));
  int y = static_cast<int>(round(p1.y + (p2.y - p1.y) * t));
  return Point{x, y};
}
