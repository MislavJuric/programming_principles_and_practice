#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"

using namespace Graph_lib;

// 4. Modify the program to have a second menu for choosing line styles and get it to run.

struct Lines_window : Graph_lib::Window
{
        Lines_window(Point xy, int w, int h, const string& title);
    private:
         // data:
          Open_polyline lines;

          // widgets:
          Button next_button;   // add (next_x,next_y) to lines
          Button quit_button;   // end program
          In_box next_x;
          In_box next_y;
          Out_box xy_out;
          Menu color_menu;
          Menu lineStyle_menu;
          Button menu_button;
          Button lineStyle_menu_button;

          void change(Color c) { lines.set_color(c); }

          void change_line_style(Line_style s) { lines.set_style(s); }

          void hide_lineStyle_menu() { lineStyle_menu.hide(); lineStyle_menu_button.show(); }

          void hide_menu() { color_menu.hide(); menu_button.show(); }

          // actions invoked by callbacks:
          void red_pressed() { change(Color::red); hide_menu(); }
          void blue_pressed() { change(Color::blue); hide_menu(); }
          void black_pressed() { change(Color::black); hide_menu(); }
          void menu_pressed() { menu_button.hide(); color_menu.show(); }
          void solid_pressed() { change_line_style(Line_style::solid); hide_lineStyle_menu(); }
          void dash_pressed() { change_line_style(Line_style::dash); hide_lineStyle_menu(); }
          void dot_pressed() { change_line_style(Line_style::dot); hide_lineStyle_menu(); }
          void dashdot_pressed() { change_line_style(Line_style::dashdot); hide_lineStyle_menu(); }
          void dashdotdot_pressed() { change_line_style(Line_style::dashdotdot); hide_lineStyle_menu(); }
          void lineStyle_menu_pressed() { lineStyle_menu_button.hide(); lineStyle_menu.show(); }
          void next();
          void quit();

          // callback functions:
          static void cb_red(Address, Address);
          static void cb_blue(Address, Address);
          static void cb_black(Address, Address);
          static void cb_menu(Address, Address);
          static void cb_solid(Address, Address);
          static void cb_dash(Address, Address);
          static void cb_dot(Address, Address);
          static void cb_dashdot(Address, Address);
          static void cb_dashdotdot(Address, Address);
          static void cb_lineStyle_menu(Address, Address);
          static void cb_next(Address, Address);
          static void cb_quit(Address, Address);
};

void Lines_window::cb_red(Address, Address pw)
{
    reference_to<Lines_window>(pw).red_pressed();
}

void Lines_window::cb_blue(Address, Address pw)
{
    reference_to<Lines_window>(pw).blue_pressed();
}

void Lines_window::cb_black(Address, Address pw)
{
    reference_to<Lines_window>(pw).black_pressed();
}

void Lines_window::cb_menu(Address, Address pw)
{
    reference_to<Lines_window>(pw).menu_pressed();
}

void Lines_window::cb_solid(Address, Address pw)
{
    reference_to<Lines_window>(pw).solid_pressed();
}

void Lines_window::cb_dash(Address, Address pw)
{
    reference_to<Lines_window>(pw).dash_pressed();
}

void Lines_window::cb_dot(Address, Address pw)
{
    reference_to<Lines_window>(pw).dot_pressed();
}

void Lines_window::cb_dashdot(Address, Address pw)
{
    reference_to<Lines_window>(pw).dashdot_pressed();
}

void Lines_window::cb_dashdotdot(Address, Address pw)
{
    reference_to<Lines_window>(pw).dashdotdot_pressed();
}

void Lines_window::cb_lineStyle_menu(Address, Address pw)
{
    reference_to<Lines_window>(pw).lineStyle_menu_pressed();
}

void Lines_window::cb_quit(Address, Address pw)
{
    reference_to<Lines_window>(pw).quit();
}

void Lines_window::cb_next(Address, Address pw)
{
    reference_to<Lines_window>(pw).next();
}

void Lines_window::quit()
{
          hide();          // curious FLTK idiom to delete window
}

void Lines_window::next()
{
          int x = next_x.get_int();
          int y = next_y.get_int();
          lines.add(Point{x,y});

          // update current position readout:
          ostringstream ss;
          ss << '(' << x << ',' << y << ')';
          xy_out.put(ss.str());

          redraw();
}

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
          :Window{xy,w,h,title},
          next_button{Point{x_max()-150,0}, 70, 20, "Next point", cb_next},
          quit_button{Point{x_max()-70,0}, 70, 20, "Quit", cb_quit},
          next_x{Point{x_max()-310,0}, 50, 20, "next x:"},
          next_y{Point{x_max()-210,0}, 50, 20, "next y:"},
          xy_out{Point{100,0}, 100, 20, "current (x,y):"},
          color_menu{Point{x_max()-70,30},70,20,Menu::vertical,"color"},
          menu_button{Point{x_max()-80,30}, 80, 20, "color menu", cb_menu},
          lineStyle_menu{Point{10,30}, 70, 20, Menu::vertical, "line style"},
          lineStyle_menu_button{Point{10,30}, 100, 20, "line style menu", cb_lineStyle_menu}
{
          attach(next_button);
          attach(quit_button);
          attach(next_x);
          attach(next_y);
          attach(xy_out);
          xy_out.put("no point");
          color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
          color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
          color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
          attach(color_menu);
          color_menu.hide();
          lineStyle_menu.attach(new Button{Point{0,0},0,0,"solid",cb_solid});
          lineStyle_menu.attach(new Button{Point{0,0},0,0,"dash",cb_dash});
          lineStyle_menu.attach(new Button{Point{0,0},0,0,"dot",cb_dot});
          lineStyle_menu.attach(new Button{Point{0,0},0,0,"dashdot",cb_dashdot});
          lineStyle_menu.attach(new Button{Point{0,0},0,0,"dashdotdot",cb_dashdotdot});
          attach(lineStyle_menu);
          lineStyle_menu.hide();
          attach(menu_button);
          attach(lineStyle_menu_button);
          attach(lines);
}

int main()
{
    try
    {
              Lines_window win {Point{100,100},600,400,"lines"};
              return gui_main();
    }
    catch(exception& e)
    {
              cerr << "exception: " << e.what() << "\n";
              return 1;
    }
    catch (...)
    {
              cerr << "Some exception\n";
              return 2;
    }
    return 0;
}
