#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

int main() {
  using namespace Graph_lib;

  Application app;

  Simple_window win{Point{100, 100}, 900, 500, "Canvas"};

  auto setup_box = [](Rectangle& r) {
    r.set_fill_color(Color::yellow);
    r.set_color(Color::black);
  };

  auto setup_text = [](Text& t) {
    t.set_color(Color::blue);
    t.set_font(Font::helvetica);
  };

  // Point.h
  Rectangle box_point{Point{20, 40}, 210, 30};
  Text text_point_h{Point{20, 25}, "Point.h:"};
  Text text_point_struct{Point{25, 45}, "struct Point{ ... };"};

  setup_box(box_point);
  setup_text(text_point_h);
  setup_text(text_point_struct);

  // Graph.h 
  Rectangle box_graph{Point{20, 130}, 210, 90};
  Text text_graph_h{Point{20, 110}, "Graph.h:"};
  Text text_graph_cmt{Point{25, 135}, "// Graphing interface"};
  Text text_shape_struct{Point{25, 160}, "struct Shape { ... };"};
  Text text_graph_dot{Point{25, 200}, "..."};

  setup_box(box_graph);
  setup_text(text_graph_h);
  text_graph_cmt.set_font(Font::helvetica);
  setup_text(text_shape_struct);
  text_graph_dot.set_font(Font::helvetica);

  // Window.h
  Rectangle box_window{Point{300, 110}, 210, 90};
  Text text_window_h{Point{300, 95}, "Window.h:"};
  Text text_window_cmt{Point{305, 115}, "// Window interface"};
  Text text_window_struct{Point{305, 140}, "struct Window { ... };"};
  Text text_window_dot{Point{305, 180}, "..."};

  setup_box(box_window);
  setup_text(text_window_h);
  text_window_cmt.set_font(Font::helvetica);
  setup_text(text_window_struct);
  text_window_dot.set_font(Font::helvetica);

  // GUI.h
  Rectangle box_gui{Point{580, 130}, 210, 90};
  Text text_gui_h{Point{580, 115}, "GUI.h:"};
  Text text_gui_cmt{Point{585, 135}, "// GUI interface"};
  Text text_button_struct{Point{585, 160}, "struct Button { ... };"};
  Text text_gui_dot{Point{585, 200}, "..."};

  setup_box(box_gui);
  setup_text(text_gui_h);
  text_gui_cmt.set_font(Font::helvetica);
  setup_text(text_button_struct);
  text_gui_dot.set_font(Font::helvetica);

  // Simple_window.h
  Rectangle box_sw{Point{280, 260}, 250, 90};
  Text text_sw_h{Point{280, 240}, "Simple_window.h:"};
  Text text_sw_cmt{Point{285, 265}, "// Simple window interface"};
  Text text_sw_struct{Point{285, 290}, "struct Simple_window { ... };"};
  Text text_sw_dot{Point{285, 330}, "..."};

  setup_box(box_sw);
  setup_text(text_sw_h);
  text_sw_cmt.set_font(Font::helvetica);
  setup_text(text_sw_struct);
  text_sw_dot.set_font(Font::helvetica);

  // Ch10.cpp
  Rectangle box_main{Point{125, 430}, 210, 30};
  Text text_main_cpp{Point{125, 410}, "Ch10.cpp:"};
  Text text_main_fn{Point{130, 435}, "int main() { ... }"};

  setup_box(box_main);
  setup_text(text_main_cpp);
  setup_text(text_main_fn);

  // Graph.h -> Point.h
  Line arrow1{Point{125, 130}, Point{125, 70}};
  // Window.h -> Point.h
  Line arrow2{Point{300, 155}, Point{125, 70}};
  // GUI.h -> Window.h
  Line arrow3{Point{580, 175}, Point{510, 155}};
  // Simple_window.h -> GUI.h
  Line arrow4{Point{530, 305}, Point{685, 220}};
  // Ch10.cpp -> Graph.h
  Line arrow5{Point{230, 430}, Point{125, 220}};
  // Ch10.cpp -> Simple_window.h
  Line arrow6{Point{230, 430}, Point{405, 350}};

  win.attach(box_point);
  win.attach(text_point_h);
  win.attach(text_point_struct);

  win.attach(box_graph);
  win.attach(text_graph_h);
  win.attach(text_graph_cmt);
  win.attach(text_shape_struct);
  win.attach(text_graph_dot);
  
  win.attach(box_window);
  win.attach(text_window_h);
  win.attach(text_window_cmt);
  win.attach(text_window_struct);
  win.attach(text_window_dot);
  
  win.attach(box_gui);
  win.attach(text_gui_h);
  win.attach(text_gui_cmt);
  win.attach(text_button_struct);
  win.attach(text_gui_dot);
  
  win.attach(box_sw);
  win.attach(text_sw_h);
  win.attach(text_sw_cmt);
  win.attach(text_sw_struct);
  win.attach(text_sw_dot);
  
  win.attach(box_main);
  win.attach(text_main_cpp);
  win.attach(text_main_fn);

  win.attach(arrow1);
  win.attach(arrow2);
  win.attach(arrow3);
  win.attach(arrow4);
  win.attach(arrow5);
  win.attach(arrow6);

  win.wait_for_button();
}
