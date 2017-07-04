#include "Simple_window.h"
#include "Graph.h"
#include "../Headers/Chapter_13-15.h"

int main()
{
    Simple_window window{Point{100, 100}, 1280, 720, "My window"};
    RGBColorChart chart;
    Diagram diagram;
    ClassDiagramBox CD1{Point{100, 100}, 100, 80, "My label"};
    ClassDiagramBox CD2{Point{250, 200}, 100, 80, "My label 2"};
    ClassDiagramBox CD3{Point{500, 300}, 100, 80, "My label 3"};
    diagram.add(CD1);
    diagram.add(CD2);
    diagram.add(CD3);
    window.attach(diagram);
    window.wait_for_button();
    window.attach(chart);
    Vector_ref<Graph_lib::Rectangle> vr;
    window.wait_for_button();

    #define SQUARE_SIZE 2
    for (int i = 0; i < 255; i++)
    {
        for (int j = 0; j < 255; j++)
        {
            vr.push_back(new Graph_lib::Rectangle{Point{i * SQUARE_SIZE, j*SQUARE_SIZE}, SQUARE_SIZE, SQUARE_SIZE});
            vr[vr.size() - 1].set_fill_color(Color{i});
            window.attach(vr[vr.size() - 1]);
        }
    }

    window.wait_for_button();

    RegularHexagon rx{Graph_lib::Point{100, 100}, 25};
    window.attach(rx);

    window.wait_for_button();
    // 11. Draw a 300-by-200-pixel ellipse. Draw a 400-pixel-long x axis and a 300-pixel-long y axis through 
    // the center of the ellipse. Mark the foci. Mark a point on the ellipse that is not on one of the axes. 
    // Draw the two lines from the foci to the point.

    Graph_lib::Ellipse e{Point{400, 400}, 300, 200};
    Graph_lib::Axis x{Graph_lib::Axis::Orientation::x, Point{400, 400}, 400, 0, "x"};
    Graph_lib::Axis y{Graph_lib::Axis::Orientation::y, Point{400, 400}, 300, 0, "y"};
    Graph_lib::Mark m1{Point{700, 400}, 'x'};
    Graph_lib::Mark m2{Point{400, 200}, 'y'};
    Graph_lib::Mark notOnAxes{Point{250, 250}, 'T'};
    Graph_lib::Line l1 {Point{700, 400}, Point{250, 250}};
    Graph_lib::Line l2 {Point{400, 200}, Point{250, 250}};
    window.attach(e);
    window.attach(x);
    window.attach(y);
    window.attach(m1);
    window.attach(m2);
    window.attach(notOnAxes);
    window.attach(l1); window.attach(l2);

    window.wait_for_button();
    // 13. Draw the color matrix from §13.10, but without lines around each color.

    for (int i = 0; i<16; ++i)
              for (int j = 0; j<16; ++j)
              {
                        vr.push_back(new Graph_lib::Rectangle{Graph_lib::Point{i*20,j*20},20,20});
                        vr[vr.size() - 1].set_fill_color(Graph_lib::Color{i*16+j});
                        vr[vr.size() - 1].set_color(Graph_lib::Color::invisible);
                        window.attach(vr[vr.size() - 1]);
              }

    window.wait_for_button();
    // Exercise 10
    Regular_polygon rp {Graph_lib::Point{100, 100}, 12, 50};
    window.attach(rp);
    window.wait_for_button();
    // 12. Draw a circle. Move a mark around on the circle (let it move a bit each time you hit the “Next” button).

    Graph_lib::Circle c{Point{100,100}, 50};
    window.attach(c);
    for (int t = 0; t <= 360; t += 10)
    {
        Graph_lib::Mark temp{Point{c.center().x + (c.radius()*sin((t*PI)/180)), c.center().y - (c.radius()*cos((t*PI)/180))}, 'X'};
        cout << "x = " << c.radius()*sin((t*PI)/180) << endl;
        cout << "y = " <<c.radius()*cos((t*PI)/180) << endl;
        window.attach(temp);
        window.wait_for_button();
    }
    window.wait_for_button();
    // Exercise 14, Chapter 13 asks me to make an octagon out of right triangles, so here it is:
    for (int i = 0; i < 8; i++)
    {
        // hmmm... a roration for an angle of 360/8 would be convinient here... I should define my own function for it
    }
    Right_triangle r {Graph_lib::Point{100, 100}, 50, -75};
    window.attach(r);
    window.wait_for_button();
    Star star{5, Graph_lib::Color{Graph_lib::Color::Color_type::black}, Graph_lib::Color{Graph_lib::Color::Color_type::black}};
    window.attach(star);
    window.wait_for_button();
    return 0;
}
