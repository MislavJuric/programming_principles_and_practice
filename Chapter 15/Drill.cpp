#include "Graph.h"
#include "Window.h"

double one(double x)
{
    return 1;
}

double slope(double x) { return x/2; }

double square(double x) { return x*x; }

double sloping_cos(double x) {return (cos(x) * slope(x));}

int main ()
{
    // better const than #define because of type checking
    constexpr int xmax = 600;
    constexpr int ymax = 600;
    // 1. Make an empty 600-by-600 Window labeled “Function graphs.”
    Graph_lib::Window win {Graph_lib::Point{100,100}, xmax, ymax, "Function graphs."};
    // 4. Add an x axis and a y axis each of length 400, labeled “1 = = 20 pixels” and with a notch every 20 pixels.
    // The axes should cross at (300,300).
    Graph_lib::Axis x{Graph_lib::Axis::Orientation::x, Graph_lib::Point{300,300}, 400, (400 / 20), "1 = = 20 pixels"};
    Graph_lib::Axis y{Graph_lib::Axis::Orientation::y, Graph_lib::Point{300,300}, 400, (400 / 20), "1 = = 20 pixels"};
    //5. Make both axes red.
    x.set_color(Graph_lib::Color::red);
    y.set_color(Graph_lib::Color::red);
    win.attach(x);
    win.attach(y);
    //1. Graph the function double one(double x) { return 1; } in the range [–10,11] with (0,0) at (300,300)
    // using 400 points and no scaling (in the window).
    // 2. Change it to use x scale 20 and y scale 20.
    Graph_lib::Function funcOne {one, -10, 11, Graph_lib::Point{300, 300}, 400, 20, 20};
    win.attach(funcOne);
    // 3. From now on use that range, scale, etc. for all graphs.
    // 4. Add double slope(double x) { return x/2; } to the window.
    Graph_lib::Function funcTwo {slope, -10, 11, Graph_lib::Point{300, 300}, 400, 20, 20};
    win.attach(funcTwo);
    // 5. Label the slope with a Text 'x/2' at a point just above its bottom left end point.
    Graph_lib::Text funcTwoLabel{Graph_lib::Point{100, 380}, "x/2"};
    win.attach(funcTwoLabel);
    //6. Add double square(double x) { return x*x; } to the window.
    Graph_lib::Function funcThree {square, -10, 11, Graph_lib::Point{300, 300}, 400, 20, 20};
    win.attach(funcThree);
    // 7. Add a cosine to the window (don’t write a new function).
    Graph_lib::Function funcFour {cos, -10, 11, Graph_lib::Point{300, 300}, 400, 20, 20};
    win.attach(funcFour);
    // 8. Make the cosine blue.
    funcFour.set_color(Graph_lib::Color::blue);
    // 9. Write a function sloping_cos() that adds a cosine to slope() (as defined above) and add it to the window.
    Graph_lib::Function funcFive {sloping_cos, -10, 11, Graph_lib::Point{300, 300}, 400, 20, 20};
    win.attach(funcFive);
    Graph_lib::gui_main();
    return 0;
}
