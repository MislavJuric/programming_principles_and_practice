#include "Simple_window.h"
#include "Chapter_13-15.h"

int main()
{
    Simple_window window{Point{100, 100}, xmax, ymax, "My window"};
    // 4. Chapter 15 Graph a sine (sin()), a cosine (cos()), the sum of those (sin(x)+cos(x)),
    // and the sum of the squares of those (sin(x)*sin(x)+cos(x)*cos(x)) on a single graph.
    // Do provide axes and labels.
    constexpr int axisLength = 500;
    constexpr int numberOfNotches = 20;
    Graph_lib::Axis x {Graph_lib::Axis::Orientation::x, Graph_lib::Point{10, 550}, axisLength, numberOfNotches, "X axis"};
    Graph_lib::Axis y {Graph_lib::Axis::Orientation::y, Graph_lib::Point{10, 550}, axisLength, numberOfNotches, "Y axis"};
    x.label.move(380, -20);
    Graph_lib::Function sine{sin, 0, 20, Graph_lib::Point{10, 550}, 100, (axisLength/numberOfNotches), (axisLength/numberOfNotches)};
    window.attach(sine);
    window.attach(x);
    window.attach(y);
    Graph_lib::Function cosine{cos, 0, 20, Graph_lib::Point{10, 550}, 100, (axisLength/numberOfNotches), (axisLength/numberOfNotches)};
    cosine.set_color(Graph_lib::Color::blue);
    window.attach(cosine);
    Graph_lib::Function sineAndCosineSum{[](double x){ return sin(x) + cos(x); }, 0, 20, Graph_lib::Point{10, 550}, 100, (axisLength/numberOfNotches), (axisLength/numberOfNotches)};
    sineAndCosineSum.set_color(Graph_lib::Color::cyan);
    window.attach(sineAndCosineSum);
    Graph_lib::Function sineAndCosineSquareSum{[](double x){ return sin(x)*sin(x) + cos(x)*cos(x); }, 0, 20, Graph_lib::Point{10, 550}, 100, (axisLength/numberOfNotches), (axisLength/numberOfNotches)};
    sineAndCosineSquareSum.set_color(Graph_lib::Color::green);
    window.attach(sineAndCosineSquareSum);
    // those are really close to provide labels (Graph_lib::Text objects), so the color serves its purpose
    window.wait_for_button();
    vector<double> heights {5, 10, 15, 13, 12, 17, 19, 12, 7, 9};
    Bar_graph bg {heights, 5, 20};
    // bg.set_bar_label(3, "third"); // segfault here somewhere...
    window.attach(bg);
    window.wait_for_button();
    ifstream is{"Exercise8-Chapter15.txt"};
    Reading temp;
    vector<Reading> readings;
    while (is >> temp)
    {
        readings.push_back(temp);
    }
    // vector<Reading> readings {{170,7}, {175, 9}, {180, 23}, {185,17}, {190, 6},{195, 1}};
    for (int i = 0; i < readings.size(); i++)
    {
        cout << readings[i].height << " " << readings[i].numberOfPeopleWithThatHeight << endl;
    }
    Bar_graph_modified bgm {readings};
    window.attach(bgm);
    window.wait_for_button();
    /*
        You can try out other classes pertaining to this chapter like so:
        <construct the object>
        window.attach(<object name>);
        window.wait_for_button();
    */
    return 0;
}
