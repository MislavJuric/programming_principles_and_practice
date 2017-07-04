#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;
    Point t1{100, 100};
    Simple_window window{t1, 600, 400, "My window"};

    // 2. Draw a 100-by-30 Rectangle and place the text “Howdy!” inside it.
    Graph_lib::Rectangle rect{Point{100, 100}, 100, 30};
    Text text{Point{130, 120}, "Howdy!"};
    window.attach(text);
    window.attach(rect);
    window.wait_for_button();

    // 1. Draw a rectangle as a Rectangle and as a Polygon.
    // Make the lines of the Polygon red and the lines of the Rectangle blue.

    Graph_lib::Rectangle rect{Point{100, 100}, 100, 100};
    rect.set_color(Graph_lib::Color::red);
    window.attach(rect);
    Graph_lib::Polygon poly;
    poly.add(Point{300, 300});
    poly.add(Point{399, 300});
    poly.add(Point{399, 399});
    poly.add(Point{300, 399});
    poly.set_color(Graph_lib::Color::blue);
    window.attach(poly);

    window.wait_for_button();
}


