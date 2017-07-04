#include "Simple_window.h"
#include "Graph.h"
#include "../Headers/Chapter_13-15.h"

int main()
{
    Simple_window window{Point{100, 100}, 1280, 720, "My window"};

    Binary_tree bt{Graph_lib::Point{100, 100}, 3};
    // bt.add_text("lrr", "a");
    Controller c{false, 2};
    c.show();
    // Derived1 d1 {true, 2}; // can't call a function here
    // d1.show();
    window.attach(bt);
    window.wait_for_button();
    /*
        You can try out other classes pertaining to this chapter like so:
        <construct the object>
        window.attach(<object name>);
        window.wait_for_button();
    */
    return 0;
}
