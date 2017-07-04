#ifndef CHAPTER_12-15_H_INCLUDED
#define CHAPTER_12-15_H_INCLUDED

#include "Graph.h"

// -----------------------------------------------------------------------------------------------------------------------
// Chapter 13
// -----------------------------------------------------------------------------------------------------------------------

// 1. Define a class Arc, which draws a part of an ellipse. Hint: fl_arc().

// I named the class MyArc

class MyArc : Graph_lib::Shape
{
    Graph_lib::Point center; // ne treba mi, Shape ima vektor pointova
    int radius;
    int start;
    int end;

    public:
    MyArc(Graph_lib::Point center, int radius, int start, int end) : center(center), radius(radius), start(start), end(end)
    {
        add(center);
    }

    void draw_lines() const;
};

void MyArc::draw_lines() const
{
    int w = radius + radius;
    int h = w;
    if (color().visibility())
    {
        fl_arc(point(0).x, point(0).y, w, h, start, end);
    }
}

//2. Draw a box with rounded corners. Define a class Box, consisting of four lines and four arcs.

class Box : Graph_lib::Shape
{
    Graph_lib::Point topLeft;
    int width;
    int height;

    public:
    Box (Graph_lib::Point topLeft, int width, int height) : topLeft(topLeft), width(width), height(height)
    {
        add(topLeft);
    }
    void draw_lines() const;
};

#define ARC_SIZE 30 // I should have used constexpr (I use it later in the code) because it provides type checking

void Box::draw_lines() const
{
    if (color().visibility())
    {
        fl_line(point(0).x + ARC_SIZE, point(0).y, (point(0).x+width) - ARC_SIZE, point(0).y);
        fl_arc(point(0).x, point(0).y, ARC_SIZE*2, ARC_SIZE*2, 90, 180);
        fl_line(point(0).x, point(0).y + ARC_SIZE, point(0).x, (point(0).y+height) - ARC_SIZE);
        fl_arc((point(0).x+width) - ARC_SIZE*2, point(0).y, ARC_SIZE*2, ARC_SIZE*2, 0, 90);
        fl_line((point(0).x+width), point(0).y + ARC_SIZE, (point(0).x+width), (point(0).y+height) - ARC_SIZE);
        fl_arc(point(0).x, (point(0).y+height-2*ARC_SIZE), ARC_SIZE*2, ARC_SIZE*2, 180, 270); // provjeriti jos zasto sam tu stavio 2*ARC_SIZE -- zato što je 2*ARC_SIZE velicina tog kruznog luka
        fl_line(point(0).x + ARC_SIZE, (point(0).y+height), (point(0).x+width) - ARC_SIZE, (point(0).y+height));
        fl_arc(point(0).x + width - ARC_SIZE*2, point(0).y + height - ARC_SIZE*2, ARC_SIZE*2, ARC_SIZE*2, 270, 360);
    }
}

// 3. Define a class Arrow, which draws a line with an arrowhead.

#define ARROW_WIDTH 30
#define ARROW_BODY_LENGTH 70
#define ARROW_TIP_ENDPOINT 100

class Arrow : Graph_lib::Shape // mogao sam inheritati od Closed_Polyline -a?
{
    Graph_lib::Point startPoint;


    public:
    Arrow(Graph_lib::Point startPoint) : startPoint(startPoint)
    {
        add(startPoint);
    }
    void draw_lines() const;
};

void Arrow::draw_lines() const
{
    // pokazuje u desno
    fl_line(point(0).x, (point(0).y - ARROW_WIDTH / 2), point(0).x, (point(0).y + ARROW_WIDTH / 2));
    fl_line(point(0).x, (point(0).y - ARROW_WIDTH / 2), (point(0).x + ARROW_BODY_LENGTH), (point(0).y - ARROW_WIDTH / 2));
    fl_line(point(0).x, (point(0).y + ARROW_WIDTH / 2), (point(0).x + ARROW_BODY_LENGTH), (point(0).y + ARROW_WIDTH / 2));
    fl_line((point(0).x + ARROW_BODY_LENGTH), (point(0).y - ARROW_WIDTH / 2), (point(0).x + ARROW_BODY_LENGTH), (point(0).y - 2*(ARROW_WIDTH / 2)));
    fl_line((point(0).x + ARROW_BODY_LENGTH), (point(0).y + ARROW_WIDTH / 2), (point(0).x + ARROW_BODY_LENGTH), (point(0).y + 2*(ARROW_WIDTH / 2)));
    fl_line((point(0).x + ARROW_BODY_LENGTH), (point(0).y - 2*(ARROW_WIDTH / 2)), (point(0).x+ARROW_TIP_ENDPOINT), (point(0).y));
    fl_line((point(0).x + ARROW_BODY_LENGTH), (point(0).y + 2*(ARROW_WIDTH / 2)), (point(0).x+ARROW_TIP_ENDPOINT), (point(0).y));
}

//4. Define functions n(), s(), e(), w(), center(), ne(), se(), sw(), and nw(). Each takes a Rectangle argument and
// returns a Point. These functions define “connection points” on and in the rectangle. For example, nw(r) is the
// northwest (top left) corner of a Rectangle called r.

Graph_lib::Point n(const Graph_lib::Rectangle& r) // north corner of a rectangle
{
    Graph_lib::Point toReturn{(r.point(0).x + (r.width() / 2)), r.point(0).y};
    return toReturn;
}

Graph_lib::Point s(const Graph_lib::Rectangle& r) // south corner of the rectangle
{
    Graph_lib::Point toReturn{(r.point(0).x + (r.width() / 2)), (r.point(0).y + r.height())};
    return toReturn;
}

Graph_lib::Point e(const Graph_lib::Rectangle& r) // east corner of the rectangle
{
    Graph_lib::Point toReturn{r.point(0).x, (r.point(0).y - (r.height() / 2))};
    return toReturn;
}

Graph_lib::Point w(const Graph_lib::Rectangle& r) // west corner of the rectangle
{
    Graph_lib::Point toReturn{(r.point(0).x + r.width()), (r.point(0).y - (r.height() / 2))};
    return toReturn;
}

Graph_lib::Point nw(const Graph_lib::Rectangle& r) // north-west corner of the rectangle
{
    return r.point(0);
}

Graph_lib::Point ne(const Graph_lib::Rectangle& r) // north-east corner of the rectangle
{
    Graph_lib::Point toReturn{(r.point(0).x + r.width()), r.point(0).y};
    return toReturn;
}

Graph_lib::Point sw(const Graph_lib::Rectangle& r) // south-west corner of the rectangle
{
    Graph_lib::Point toReturn{r.point(0).x, (r.point(0).y + r.height())};
    return toReturn;
}

Graph_lib::Point se(const Graph_lib::Rectangle& r) // south-east corner of the rectangle
{
    Graph_lib::Point toReturn{(r.point(0).x + r.height()), (r.point(0).y + r.height())};
    return toReturn;
}

Graph_lib::Point center(const Graph_lib::Rectangle& r) // center of the rectangle
{
    Graph_lib::Point toReturn{(r.point(0).x + (r.width()/2)), (r.point(0).y + (r.height() / 2))};
    return toReturn;
}

//5. Define the functions from exercise 4 for a Circle and an Ellipse. Place the connection points on or outside
// the shape but not outside the bounding rectangle.

Graph_lib::Point circle_n (const Graph_lib::Circle& c)
{
    Graph_lib::Point toReturn{c.center().x, c.center().y-c.radius()};
    return toReturn;
}

Graph_lib::Point circle_s (const Graph_lib::Circle& c)
{
    Graph_lib::Point toReturn{c.center().x, c.center().y+c.radius()};
    return toReturn;
}

Graph_lib::Point circle_e (const Graph_lib::Circle& c)
{
    Graph_lib::Point toReturn{c.center().x+c.radius(), c.center().y};
    return toReturn;
}

Graph_lib::Point circle_w (const Graph_lib::Circle& c)
{
    Graph_lib::Point toReturn{c.center().x-c.radius(), c.center().y};
    return toReturn;
}

Graph_lib::Point ellipse_n (const Graph_lib::Ellipse& e)
{
    Graph_lib::Point toReturn{e.center().x, e.center().y-e.minor()};
    return toReturn;
}

Graph_lib::Point ellipse_s (const Graph_lib::Ellipse& e)
{
    Graph_lib::Point toReturn{e.center().x, e.center().y+e.minor()};
    return toReturn;
}

Graph_lib::Point ellipse_e (const Graph_lib::Ellipse& e)
{
    Graph_lib::Point toReturn{e.center().x + e.major(), e.center().y};
    return toReturn;
}

Graph_lib::Point ellipse_w (const Graph_lib::Ellipse& e)
{
    Graph_lib::Point toReturn{e.center().x - e.major(), e.center().y};
    return toReturn;
}

//6. Write a program that draws a class diagram like the one in §12.6. It will simplify matters if you start by defining
// a Box class that is a rectangle with a text label.

class ClassDiagramBox : public Graph_lib::Rectangle
{
    private:
        std::string text;
        Point startPoint;
    public:
        ClassDiagramBox(Point xy, int ww, int hh, const std::string& text) : Graph_lib::Rectangle(xy, ww, hh), text(text), startPoint(xy) { }
        void draw_lines() const;
        Point getStartPoint() const;
};

#define TEXT_SPACING 30

void ClassDiagramBox::draw_lines() const
{
    Graph_lib::Rectangle::draw_lines();
    Graph_lib::Point textStartPoint {startPoint.x + TEXT_SPACING, (startPoint.y + Rectangle::height() / 2)}; // add some spacing and center the text
    Graph_lib::Text t{textStartPoint, text};
    t.draw_lines();
}

Point ClassDiagramBox::getStartPoint() const
{
    return startPoint;
}

class Diagram : public Graph_lib::Shape // ne razumijem zasto mi treba public ovdje...
{
    Graph_lib::Vector_ref<ClassDiagramBox> boxes; // what is the problem here?

    public:
    void add(ClassDiagramBox& boxToAdd);
    void draw_lines() const;

};

void Diagram::add(ClassDiagramBox& boxToAdd)
{
    boxes.push_back(boxToAdd);
}

#define ARROW_TIP_WIDTH 5 // in pixels

void Diagram::draw_lines() const
{
    for (int i = 0; i < (boxes.size() - 1); i++)
    {
        boxes[i].draw_lines();
        const ClassDiagramBox* nextBox = &boxes[i];
        nextBox = &boxes[i + 1];
        Point startPoint {(boxes[i].getStartPoint().x + (boxes[i].width() / 2)), (boxes[i].getStartPoint().y + boxes[i].height())};
        Point endPoint {(nextBox->getStartPoint().x + (nextBox->width() / 2)), nextBox->getStartPoint().y};
        // arrow tip drawing code below
        // Point firstArrowTipPoint = endPoint;
        // Point secondArrowTipPoint =
        // --------------------

        // I didn't bother with drawing the arrows
        fl_line(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
        boxes[i+1].draw_lines();
    }
}

// 7. Make an RGB color chart (e.g., search the web for “RGB color chart”).

class RGBColorChart : public Shape // if I don't put public, I get this: 299|error: 'Graph_lib::Shape' is an inaccessible base of 'RGBColorChart'|
{
    public:
        void draw_lines() const;
};

void RGBColorChart::draw_lines() const
{
    //dimenzije su 30 (sirina) i 17 (visina) -- iako moze varirati

    // kako napraviti da se boje povecavaju kako treba?
    Vector_ref<Graph_lib::Rectangle> vr; // 13.10 PPP
    #define SQUARE_SIZE 2
    for (int i = 0; i < 255; i++)
    {
        for (int j = 0; j < 255; j++)
        {
            vr.push_back(new Graph_lib::Rectangle{Point{i * SQUARE_SIZE, j*SQUARE_SIZE}, SQUARE_SIZE, SQUARE_SIZE});
            vr[vr.size() - 1].set_fill_color(Color{i});
        }
    }
}

// 8. Define a class Regular_hexagon (a regular hexagon is a six-sided polygon with all sides of equal length).
// Use the center and the distance from the center to a corner point as constructor arguments.

class RegularHexagon : public Graph_lib::Polygon
{
    private:
    Graph_lib::Point center;
    float distanceFromTheCenter;

    public:
    RegularHexagon(Graph_lib::Point center, float distanceFromTheCenter)
    {
        float A = (sqrt(3)/2) * distanceFromTheCenter;
        float B = 0.5 * distanceFromTheCenter;
        Graph_lib::Point FirstPoint = Graph_lib::Point{center.x, center.y + distanceFromTheCenter}; // top point
        Graph_lib::Point SecondPoint = Graph_lib::Point{center.x + A, center.y + B};
        Graph_lib::Point ThirdPoint = Graph_lib::Point{center.x + A, center.y - B};
        Graph_lib::Point FourthPoint = Graph_lib::Point{center.x, center.y - distanceFromTheCenter};
        Graph_lib::Point FifthPoint = Graph_lib::Point{center.x - A, center.y - B};
        Graph_lib::Point SixthPoint = Graph_lib::Point{center.x - A, center.y + B};
        add(FirstPoint);
        add(SecondPoint);
        add(ThirdPoint);
        add(FourthPoint);
        add(FifthPoint);
        add(SixthPoint);
    }

    public:

    void draw_lines() const;
};

void RegularHexagon::draw_lines() const
{
    Graph_lib::Closed_polyline::draw_lines();
}

// 10. Define a class Regular_polygon. Use the center, the number of sides (>2), and the distance from the center
// to a corner as constructor arguments.

class Regular_polygon : public Shape
{
    public:
    Regular_polygon(Graph_lib::Point center, int numberOfSides, float distanceFromCenter) :
        center(center), numberOfSides(numberOfSides), distanceFromCenter(distanceFromCenter) {}
    void draw_lines() const;

    private:
    Graph_lib::Point center;
    int numberOfSides;
    float distanceFromCenter;
};

const double PI = 3.1415926535897;

void Regular_polygon::draw_lines() const
{
    float t = 360 / numberOfSides;
    for (int i = 1; i <= numberOfSides; i++)
    {

        Graph_lib::Point polygonPoint {center.x + (distanceFromCenter*sin((t*i*PI)/180)), center.y +  (distanceFromCenter*cos((t*i*PI)/180))}; // polar coordinates
        Graph_lib::Point nextPolygonPoint {center.x + (distanceFromCenter*sin((t*(i+1)*PI)/180)), center.y +  (distanceFromCenter*cos((t*(i+1)*PI)/180))};
        fl_line(polygonPoint.x, polygonPoint.y, nextPolygonPoint.x, nextPolygonPoint.y);
    }
}

// 14. Define a right triangle class. Make an octagonal shape out of eight right triangles of different colors.

// This is my Right triangle class, first attempt; Note that I use strings to represent right triangle orientations,
// which could be more easily done by using an enum.

/*

class Right_triangle : public Shape
{
    public:
        Right_triangle(Graph_lib::Point startPoint, float hypothenuse, float smaller_leg, string orientation) :
            startPoint(startPoint), hypothenuse(hypothenuse), smaller_leg(smaller_leg), orientation(orientation)
            {

            }

        void draw_lines() const;

    private:
        // what do I minimally need to define a right triangle?
        // Pitati na r/learnprogramming za dizajn ovakve klase
        float hypothenuse;
        float smaller_leg;
        Graph_lib::Point startPoint; // the point where the right angle is
        string orientation; // possible values: "up", "down", "right", "left"
};

void Right_triangle::draw_lines() const
{
    float larger_leg = sqrt((hypothenuse * hypothenuse) - (smaller_leg * smaller_leg));
    if (orientation == "up")
    {
        Graph_lib::Point leftPoint{startPoint.x - smaller_leg, startPoint.y};
        Graph_lib::Point topPoint{startPoint.x, startPoint.y + larger_leg};
        fl_line(startPoint.x, startPoint.y, leftPoint.x, leftPoint.y);
        fl_line(startPoint.x, startPoint.y, topPoint.x, topPoint.y);
        fl_line(topPoint.x, topPoint.y, leftPoint.x, leftPoint.y);
    }
}
*/

// my 2nd attempt at Right_triangle class:

class Right_triangle : public Shape
{
    public:
    Right_triangle(Graph_lib::Point startPoint, float offset_x, float offset_y) : startPoint(startPoint), offset_x(offset_x), offset_y(offset_y)
    {

    }
    void draw_lines() const;
    private:
    Graph_lib::Point startPoint;
    // I need to store the point I will rotate around
    float offset_x; // this can be negative
    float offset_y; // this can also be negative
};

void Right_triangle::draw_lines() const
{
    Graph_lib::Point secondPoint{startPoint.x + offset_x, startPoint.y};
    Graph_lib::Point thirdPoint{startPoint.x, startPoint.y + offset_y};
    // calculating distances from from all the points, so I can see if we have a right triangle
    float triangleLeg1 = sqrt(pow((secondPoint.x - startPoint.x), 2) + pow((secondPoint.y - startPoint.y), 2));
    float triangleLeg2 = sqrt(pow((thirdPoint.x - startPoint.x), 2) + pow((thirdPoint.y - startPoint.y), 2));
    float hypothenuse = sqrt(pow((thirdPoint.x - secondPoint.x), 2) + pow((thirdPoint.y - secondPoint.y), 2));
    // if our triangle leg lengths and our hypothenuse length don't satisfy the Pythagorean theorem,
    // then our triangle is not a right triangle

    // --- this above doesn't have to hold, since I'm passing just the offset ---

    /*
    if (pow(hypothenuse, 2) != pow(triangleLeg1, 2) * (pow(triangleLeg2, 2)))
    {
        error("The parameters you passed to the right triangle constructor don't form a right triangle.");
    }
    */
    fl_line(startPoint.x, startPoint.y, secondPoint.x, secondPoint.y);
    fl_line(startPoint.x, startPoint.y, thirdPoint.x, thirdPoint.y);
    fl_line(secondPoint.x, secondPoint.y, thirdPoint.x, thirdPoint.y);
}

// 18. Define a class Poly that represents a polygon but checks that its points really do make a polygon in its constructor.
// Hint: You’ll have to supply the points to the constructor.

// I'll get back to this... I have to figure out how to check if lines intersect.

//19. Define a class Star. One parameter should be the number of points. Draw a few stars with differing numbers of points,
// differing line colors, and differing fill colors.

class Star : public Graph_lib::Shape
{
    public:
    Star(int numberOfPoints, Graph_lib::Color lineColor, Graph_lib::Color fillColor) :
        numberOfPoints(numberOfPoints), lineColor(lineColor), fillColor(fillColor) {}

    void draw_lines() const;

    private:
    int numberOfPoints;
    Graph_lib::Color lineColor;
    Graph_lib::Color fillColor;
};

// the length of the star measured from the opposite points
#define STAR_DIAGONAL_LENGTH 200
// the length of the leg of the triangle that makes up the star
#define STAR_TRIANGLE_LEG_LENGTH 30
// the length of the sides of the triangle that make up the star
#define STAR_TRIANGLE_SIDE_LENGTH 50
// the radius of the inner circle that makes the star have the "starry" shape
#define STAR_INNER_CIRCLE_RADIUS 25

void Star::draw_lines() const
{
    // randomly generate a starting position for a star, starting from 300 then varying it for 500 pixels
    Graph_lib::Point center{300 + (rand() % 500), 300 + (rand() % 500)};
    cout << center.x << " " << center.y << endl;
    // stars should look like a regular polygon, however, with triangles within them
    // maybe not within them, but above them? so triangles are above a regular polygon? no... that looks bad (draw it)


    // number of total points in the circle is numberOfPoints (private member) * 2
    // so we'll have a repetitive pattern over the star - the first two points will be the triangle points, the next two
    // will be the connecting line, then again points of the triangle, and so on...
    int totalNumberOfPoints = numberOfPoints * 2;
    cout << "totalNumberOfPoints is " << totalNumberOfPoints << endl;
    int t = 360 / totalNumberOfPoints;
    cout << "t is " << t << endl;
    for (int i = 0; i < (totalNumberOfPoints - 1); i++)
    {
        Graph_lib::Point firstPoint {center.x + (STAR_INNER_CIRCLE_RADIUS*sin((t*i*PI)/180)), center.y +  (STAR_INNER_CIRCLE_RADIUS*cos((t*i*PI)/180))}; // polar coordinates
        cout << "First points x is " << firstPoint.x << endl;
        cout << "First points y is " << firstPoint.y << endl;
        Graph_lib::Point nextPoint {center.x + (STAR_INNER_CIRCLE_RADIUS*sin((t*(i+1)*PI)/180)), center.y +  (STAR_INNER_CIRCLE_RADIUS*cos((t*(i+1)*PI)/180))};
        cout << "Next points x is " << nextPoint.x << endl;
        cout << "Next points y is " << nextPoint.y << endl;
        // if i is an even number, then we won't be making a triangle
        if ((i % 2) == 0)
        {
            cout << "Executed first if - I connected (" << firstPoint.x << "," << firstPoint.y << ") and ("
                 << nextPoint.x << ", " << nextPoint.y << ")." << endl;
            fl_line(firstPoint.x, firstPoint.y, nextPoint.x, nextPoint.y);
        }
        else
        {
            float halfTriangleLegLength = STAR_TRIANGLE_LEG_LENGTH / 2; // this is how much we will move to the right
            float moveUpwardsAmount = sqrt(pow(STAR_TRIANGLE_SIDE_LENGTH, 2) - pow(halfTriangleLegLength, 2));
            Graph_lib::Point triangleUpperPoint{firstPoint.x + halfTriangleLegLength, firstPoint.y + moveUpwardsAmount};
            // fl_line(firstPoint.x, firstPoint.y, nextPoint.x, nextPoint.y);
            fl_line(firstPoint.x, firstPoint.y, triangleUpperPoint.x, triangleUpperPoint.y);
            fl_line(nextPoint.x, nextPoint.y, triangleUpperPoint.x, triangleUpperPoint.y);
        }
    }
}

// -----------------------------------------------------------------------------------------------------------------------
// Chapter 14
// -----------------------------------------------------------------------------------------------------------------------

// 1. Exercise
// Define two classes Smiley and Frowny, which are both derived from class Circle and have two eyes and a mouth.
// Next, derive classes from Smiley and Frowny which add an appropriate hat to each. -- I skipped this part,
// because they'd have the same hat and because a hat would be drawn from a combination of arcs, which
// is tricky to construct

// My notes: Eyes and mouth should be proportionately small to the circle size
// Circle radius probably shouldn't be less than 100 pixels (could put an invariant check in the constructor)

class Smiley : public Graph_lib::Circle // will probably have to do protected inheritance here
{
    private:
        Graph_lib::Point center;
        int radius;
    public:
        Smiley (Graph_lib::Point p, int rr) : Graph_lib::Circle(p, rr)
        {
            center = p;
            radius = rr;
        }
        void draw_lines() const;
};

void Smiley::draw_lines() const
{
    // need to figure out how to move from the center of the Circle to the center of the eyes and draw 2 circles as eyes
    // Circle::draw_lines();
    Graph_lib::Point rightEyeCenter{center.x + (center.x / 4), center.y - (center.y / 8)};
    // this above is an example of magic constants (number 4 and number 8; I left them here to remind myself not to do that
    // and I think that they draw the eyes quite right
    Graph_lib::Circle::draw_lines();
    Graph_lib::Point leftEyeCenter{center.x - (center.x / 4), center.y - (center.y / 8)};
    Graph_lib::Circle rightEye{rightEyeCenter, radius / 4};
    Graph_lib::Circle leftEye{leftEyeCenter, radius / 4};
    rightEye.draw_lines();
    leftEye.draw_lines();
    Graph_lib::Point mouthCenter{center.x, center.y + (center.y / 2)};
    Graph_lib::Point leftMouthCorner{leftEyeCenter.x, center.y + (center.y / 4)};
    Graph_lib::Point rightMouthCorner{rightEyeCenter.x, center.y + (center.y / 4)};
    // below two lines left to improve
    // fl_line(mouthCenter.x, mouthCenter.y, leftMouthCorner.x, leftMouthCorner.y);
    // fl_line(mouthCenter.x, mouthCenter.y, rightMouthCorner.x, rightMouthCorner.y);
    // improved version of the smile below (hint: 3rd and 4h argument represent the width and the height of the bounding box
    fl_arc(leftMouthCorner.x, leftMouthCorner.y, (rightMouthCorner.x - leftMouthCorner.x), (mouthCenter.y - leftMouthCorner.y), 200, 340);
    // debugging purposes
    //cout << leftMouthCorner.x << " " << leftMouthCorner.y << " " << rightMouthCorner.x << " " << mouthCenter.y << endl;
}

class Frowny : public Graph_lib::Circle // will probably have to do protected inheritance here
{
    private:
        Graph_lib::Point center;
        int radius;
    public:
        Frowny (Graph_lib::Point p, int rr) : Graph_lib::Circle(p, rr)
        {
            center = p;
            radius = rr;
        }
        void draw_lines() const;
};

void Frowny::draw_lines() const
{
    Graph_lib::Point rightEyeCenter{center.x + (center.x / 4), center.y - (center.y / 8)};
    Graph_lib::Circle::draw_lines();
    Graph_lib::Point leftEyeCenter{center.x - (center.x / 4), center.y - (center.y / 8)};
    Graph_lib::Circle rightEye{rightEyeCenter, radius / 4};
    Graph_lib::Circle leftEye{leftEyeCenter, radius / 4};
    rightEye.draw_lines();
    leftEye.draw_lines();
    Graph_lib::Point mouthCenter{center.x, center.y + (center.y / 2)};
    Graph_lib::Point leftMouthCorner{leftEyeCenter.x, center.y + (center.y / 4)};
    Graph_lib::Point rightMouthCorner{rightEyeCenter.x, center.y + (center.y / 4)};
    fl_arc(leftMouthCorner.x, leftMouthCorner.y, (rightMouthCorner.x - leftMouthCorner.x), (mouthCenter.y - leftMouthCorner.y), 20, 160);
}

// 4. Define a class Immobile_Circle, which is just like Circle but can’t be moved.

class Immobile_Circle : public Circle
{
    public:
        Immobile_Circle(Graph_lib::Point center, float radius) : Graph_lib::Circle(center, radius) {}
        void move(int dx, int dy) { /* could throw an exception here */ }
        // void move(int dx, int dy) = delete; throws an error, because deleting
        // a base member function breaks inheritance
};

// 5. Define a Striped_rectangle where instead of fill, the rectangle is “filled” by drawing one-pixel-wide
// horizontal lines across the inside of the rectangle (say, draw every second line like that).
// You may have to play with the width of lines and the line spacing to get a pattern you like.

class Stripped_Rectangle : public Rectangle
{
    private:
        Graph_lib::Point topLeft;
        int width;
        int height;
    public:
        Stripped_Rectangle(Graph_lib::Point topLeft, int width, int height) : Graph_lib::Rectangle(topLeft, width, height), topLeft(topLeft), height(height), width(width) {}
        // it's as if my Graph_lib::Rectangle(topLeft, width, height) doesn't get called at all... strange...
        void draw_lines() const;
};

void Stripped_Rectangle::draw_lines() const
{
    /*
    for (int i = 0; i < height; i++)
    {
        if ((i % 2) == 1)
        {
            fl_line(topLeft.x, topLeft.y + i, topLeft.x + width, topLeft.y + i);
        }
    }
    */
    // this code below does the same thing as the code above, minus the if
    for (int i = 1; i <= height; i += 2)
    {
        fl_line(topLeft.x, topLeft.y + i, topLeft.x + width, topLeft.y + i);
    }
}

// 6. Define a Striped_circle using the technique from Striped_rectangle.

// hmm... I'd have to connect the points on the circle...

// 7. Define a Striped_closed_polyline using the technique from Striped_rectangle (this requires some algorithmic inventiveness).

// If I could figure out how to make a Striped_circle using the circle equation to figure out the x and the y of
// the points, I could do the same with a Striped_closed_polyline (every polyline has an equation...)

// maybe the above is not such a good idea... I'll get back to this

// 8. Define a class Octagon to be a regular octagon.
// Write a test that exercises all of its functions (as defined by you or inherited from Shape).

class Octagon : public Shape
{
    private:
        Graph_lib::Point center;
        float radius;
    public:
        Octagon(Graph_lib::Point center, float radius) : center(center), radius(radius) {}
        void draw_lines() const;
};

#define NUMBER_OF_SIDES_OCTAGON 8

void Octagon::draw_lines() const
{
    float t = 360 / NUMBER_OF_SIDES_OCTAGON;
    for (int i = 1; i <= NUMBER_OF_SIDES_OCTAGON; i++)
    {

        Graph_lib::Point polygonPoint {center.x + (radius*sin((t*i*PI)/180)), center.y +  (radius*cos((t*i*PI)/180))}; // polar coordinates
        Graph_lib::Point nextPolygonPoint {center.x + (radius*sin((t*(i+1)*PI)/180)), center.y +  (radius*cos((t*(i+1)*PI)/180))};
        fl_line(polygonPoint.x, polygonPoint.y, nextPolygonPoint.x, nextPolygonPoint.y);
    }
}

// 9. Define a Group to be a container of Shapes with suitable operations applied to the various members of the Group.
// Hint: Vector_ref. Use a Group to define a checkers (draughts) board where pieces can be moved under program control.

// I'll have to get back to Exercise 9 above.

// 10. Define a class Pseudo_window that looks as much like a Window as you can make it without heroic efforts.
// It should have rounded corners, a label, and control icons. Maybe you could add some fake “contents,” such as an image.
// It need not actually do anything. It is acceptable (and indeed recommended) to have it appear within a Simple_window.

#define PSEUDO_BUTTON_WIDTH_AND_HEIGHT 20
#define BUTTON_PADDING 50
#define TEXT_PADDING 30

class Pseudo_window : public Shape
{
    private:
        Graph_lib::Point topLeft;
        float width;
        float height;
        Box b;
        Graph_lib::Text t;
        Graph_lib::Rectangle firstButton;
        Graph_lib::Rectangle secondButton;
        Graph_lib::Rectangle thirdButton;
    public:
        Pseudo_window(Graph_lib::Point topLeft, float width, float height) : topLeft(topLeft), width(width), height(height),
        b{topLeft, width, height},
        t{Graph_lib::Point{topLeft.x + TEXT_PADDING, topLeft.y + TEXT_PADDING}, "Pseudo window"}, // could pass the pseudo window title as a string constructor argument
        firstButton{Graph_lib::Point{((topLeft.x + width) - 2 * PSEUDO_BUTTON_WIDTH_AND_HEIGHT) - BUTTON_PADDING, topLeft.y + BUTTON_PADDING/8}, PSEUDO_BUTTON_WIDTH_AND_HEIGHT, PSEUDO_BUTTON_WIDTH_AND_HEIGHT},
        secondButton{Graph_lib::Point{((topLeft.x + width) - PSEUDO_BUTTON_WIDTH_AND_HEIGHT) - BUTTON_PADDING, topLeft.y + BUTTON_PADDING/8}, PSEUDO_BUTTON_WIDTH_AND_HEIGHT, PSEUDO_BUTTON_WIDTH_AND_HEIGHT},
        thirdButton{Graph_lib::Point{topLeft.x + width - BUTTON_PADDING, topLeft.y + BUTTON_PADDING/8}, PSEUDO_BUTTON_WIDTH_AND_HEIGHT, PSEUDO_BUTTON_WIDTH_AND_HEIGHT}
        { }
        void draw_lines() const;
};

// this function below not drawing anything... shapes aren't attached to a Simple_window, that's why
void Pseudo_window::draw_lines() const
{
    // the commented out code is the code I experimented with and didn't work
    // Box b {topLeft, width, height};
    // b::draw_lines();
    /*
    Box b {topLeft, width, height};
    Graph_lib::Text t {topLeft, "Pseudo window"};
    Graph_lib::Rectangle firstButton{Graph_lib::Point{(topLeft.x + width) - 2 * PSEUDO_BUTTON_WIDTH_AND_HEIGHT, topLeft.y}, PSEUDO_BUTTON_WIDTH_AND_HEIGHT, PSEUDO_BUTTON_WIDTH_AND_HEIGHT};
    Graph_lib::Rectangle secondButton{Graph_lib::Point{(topLeft.x + width) - PSEUDO_BUTTON_WIDTH_AND_HEIGHT, topLeft.y}, PSEUDO_BUTTON_WIDTH_AND_HEIGHT, PSEUDO_BUTTON_WIDTH_AND_HEIGHT};
    Graph_lib::Rectangle thirdButton{Graph_lib::Point{topLeft.x + width, topLeft.y}, PSEUDO_BUTTON_WIDTH_AND_HEIGHT, PSEUDO_BUTTON_WIDTH_AND_HEIGHT};
    */

    // the trick is to call the methods below in my draw_lines() method
    b.draw_lines();
    t.draw_lines();
    firstButton.draw_lines();
    secondButton.draw_lines();
    thirdButton.draw_lines();
    fl_line(topLeft.x, topLeft.y + (ARC_SIZE * 1.5), topLeft.x + width, topLeft.y + (ARC_SIZE * 1.5));
    // ARC_SIZE is Boxss arc size and 1.5 is the dilatation factor I chose (it could be a const)
}

// 11. Define a Binary_tree class derived from Shape. Give the number of levels as a parameter
// (levels==0 means no nodes, levels==1 means one node, levels==2 means one top node with two sub-nodes,
// levels==3 means one top node with two sub-nodes each with two sub-nodes, etc.).
// Let a node be represented by a small circle. Connect the nodes by lines (as is conventional).
// P.S. In computer science, trees grow downward from a top node (amusingly, but logically, often called the root).

// this is commented out because I modify that same class in Exercise 12

/*
class Binary_tree : public Shape
{
    private:
        Graph_lib::Point centerPoint;
        int level;
    public:
        Binary_tree(Graph_lib::Point centerPoint, int level) : centerPoint(centerPoint), level(level) { }
        void draw_lines() const;
};

#define BINARY_TREE_NODE_SIZE 15
#define BINARY_TREE_CONNECTION_ANGLE 45
#define BINARY_TREE_CONNECTION_LINE_LENGTH 20

// #define or const? ...

// the two connections between the nodes must be slightly angled... I could define both the angle and the connection
// line length (if you draw it, there should be a right triangle whose hypothenuse is eqal to BINARY_TREE_CONNETION_LINE_LENGTH



// to-fix: the right child of the left node and the left child of the right node are the same
void Binary_tree::draw_lines() const
{
    // Graph_lib::Vector_ref<Graph_lib::Circle> nodes;
    Graph_lib::Vector_ref<Graph_lib::Point> circleCenters;
    circleCenters.push_back(new Point{centerPoint.x, centerPoint.y});
    // tesirati size() circleCentersa
    cout << "Before the for loop circleCenters.size() is " << circleCenters.size() << "." << endl;
    int circleCentersIndex = 0;
    // code doesn't work as it should...
    for (int i = 0; i < level; i++)
    {
        int numberOfNodes = pow(2, i);
        for (int k = circleCentersIndex; k < circleCenters.size(); k++)
        {
            cout << "Made a circle with index " << k << endl;
            Circle c{circleCenters[k], BINARY_TREE_NODE_SIZE};
            //  nodes.push_back(c); // dangling reference here
            c.draw_lines();
        }
        if ((i + 1) != level)
        {
            cout << "If statement executed" << endl;
            for (int k = circleCentersIndex; k < (numberOfNodes + circleCentersIndex); k++)
            {
                // cout << "In the nested for loop circleCenters.size() is " << circleCenters.size() << "." << endl;
                cout << "Executed" << endl; // ovo mi se ne zavrti dovoljno puta
                float circleYMovement = cos((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * BINARY_TREE_NODE_SIZE;
                float circleXMovement = sin((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * BINARY_TREE_NODE_SIZE;
                Graph_lib::Point rightPointOnTheCircle{circleCenters[k].x + circleXMovement, circleCenters[k].y + circleYMovement};
                Graph_lib::Point leftPointOnTheCircle {circleCenters[k].x - circleXMovement, circleCenters[k].y + circleYMovement};
                float connectionMovementX = sin((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * (BINARY_TREE_NODE_SIZE + BINARY_TREE_CONNECTION_LINE_LENGTH);
                float connectionMovementY = cos((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * (BINARY_TREE_NODE_SIZE + BINARY_TREE_CONNECTION_LINE_LENGTH);
                Graph_lib::Point rightPointConnection{circleCenters[k].x + connectionMovementX, circleCenters[k].y + connectionMovementY};
                Graph_lib::Point leftPointConnection{circleCenters[k].x - connectionMovementX, circleCenters[k].y + connectionMovementY};
                fl_line(rightPointOnTheCircle.x, rightPointOnTheCircle.y, rightPointConnection.x, rightPointConnection.y);
                fl_line(leftPointOnTheCircle.x, leftPointOnTheCircle.y, leftPointConnection.x, leftPointConnection.y);
                float nodeCenterMovementX = sin((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * (2 * BINARY_TREE_NODE_SIZE + BINARY_TREE_CONNECTION_LINE_LENGTH);
                float nodeCenterMovementY = cos((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * (2 * BINARY_TREE_NODE_SIZE + BINARY_TREE_CONNECTION_LINE_LENGTH);
                Graph_lib::Point rightNodeCenter{circleCenters[k].x + nodeCenterMovementX, circleCenters[k].y + nodeCenterMovementY};
                Graph_lib::Point leftNodeCenter{circleCenters[k].x - nodeCenterMovementX, circleCenters[k].y + nodeCenterMovementY};
                // the right child of the left node and the left child of the right node are the same...


                // Graph_lib::Circle rightNode{rightNodeCenter, BINARY_TREE_NODE_SIZE};
                // Graph_lib::Circle leftNode{leftNodeCenter, BINARY_TREE_NODE_SIZE};
                circleCenters.push_back(new Point{rightNodeCenter.x, rightNodeCenter.y});
                // cout << rightNodeCenter.x << " " << rightNodeCenter.y << endl;
                circleCenters.push_back(new Point{leftNodeCenter.x, leftNodeCenter.y});
                // cout << leftNodeCenter.x << " " << leftNodeCenter.y << endl;
                // rightNode.draw_lines();
                // leftNode.draw_lines();
            }
            circleCentersIndex = circleCentersIndex + numberOfNodes;
            cout << "circleCentersIndex changed." << endl;
        }
    }
}

*/

// 12. Modify Binary_tree to draw its nodes using a virtual function.
// Then, derive a new class from Binary_tree that overrides that virtual function to use a different representation
// for a node (e.g., a triangle).

// for task 12, my derived class could override the virtual function in the base class, but it would need
// to have the same arguments (or at least I should be able to make the arguments from the place where I call the function)

/*

class Binary_tree : public Shape
{
    private:
        Graph_lib::Point centerPoint;
        int level;
    public:
        Binary_tree(Graph_lib::Point centerPoint, int level) : centerPoint(centerPoint), level(level) { }
        void draw_lines() const;
        virtual void draw_node(Graph_lib::Point center, int radius) const
        {
            Graph_lib::Circle c{center, radius};
            c.draw_lines();
        }
};

#define BINARY_TREE_NODE_SIZE 15
#define BINARY_TREE_CONNECTION_ANGLE 45
#define BINARY_TREE_CONNECTION_LINE_LENGTH 20

// #define or const? ...

// to-fix: the right child of the left node and the left child of the right node are the same

void Binary_tree::draw_lines() const
{
    Graph_lib::Vector_ref<Graph_lib::Point> circleCenters;
    circleCenters.push_back(new Point{centerPoint.x, centerPoint.y});
    int circleCentersIndex = 0;
    for (int i = 0; i < level; i++)
    {
        int numberOfNodes = pow(2, i);
        for (int k = circleCentersIndex; k < circleCenters.size(); k++)
        {
            draw_node(circleCenters[k], BINARY_TREE_NODE_SIZE);
        }
        if ((i + 1) != level)
        {
            for (int k = circleCentersIndex; k < (numberOfNodes + circleCentersIndex); k++)
            {
                float circleYMovement = cos((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * BINARY_TREE_NODE_SIZE;
                float circleXMovement = sin((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * BINARY_TREE_NODE_SIZE;
                Graph_lib::Point rightPointOnTheCircle{circleCenters[k].x + circleXMovement, circleCenters[k].y + circleYMovement};
                Graph_lib::Point leftPointOnTheCircle {circleCenters[k].x - circleXMovement, circleCenters[k].y + circleYMovement};
                float connectionMovementX = sin((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * (BINARY_TREE_NODE_SIZE + BINARY_TREE_CONNECTION_LINE_LENGTH);
                float connectionMovementY = cos((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * (BINARY_TREE_NODE_SIZE + BINARY_TREE_CONNECTION_LINE_LENGTH);
                Graph_lib::Point rightPointConnection{circleCenters[k].x + connectionMovementX, circleCenters[k].y + connectionMovementY};
                Graph_lib::Point leftPointConnection{circleCenters[k].x - connectionMovementX, circleCenters[k].y + connectionMovementY};
                fl_line(rightPointOnTheCircle.x, rightPointOnTheCircle.y, rightPointConnection.x, rightPointConnection.y);
                fl_line(leftPointOnTheCircle.x, leftPointOnTheCircle.y, leftPointConnection.x, leftPointConnection.y);
                float nodeCenterMovementX = sin((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * (2 * BINARY_TREE_NODE_SIZE + BINARY_TREE_CONNECTION_LINE_LENGTH);
                float nodeCenterMovementY = cos((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * (2 * BINARY_TREE_NODE_SIZE + BINARY_TREE_CONNECTION_LINE_LENGTH);
                Graph_lib::Point rightNodeCenter{circleCenters[k].x + nodeCenterMovementX, circleCenters[k].y + nodeCenterMovementY};
                Graph_lib::Point leftNodeCenter{circleCenters[k].x - nodeCenterMovementX, circleCenters[k].y + nodeCenterMovementY};
                // the right child of the left node and the left child of the right node are the same...


                // Graph_lib::Circle rightNode{rightNodeCenter, BINARY_TREE_NODE_SIZE};
                // Graph_lib::Circle leftNode{leftNodeCenter, BINARY_TREE_NODE_SIZE};
                circleCenters.push_back(new Point{rightNodeCenter.x, rightNodeCenter.y});
                // cout << rightNodeCenter.x << " " << rightNodeCenter.y << endl;
                circleCenters.push_back(new Point{leftNodeCenter.x, leftNodeCenter.y});
                // cout << leftNodeCenter.x << " " << leftNodeCenter.y << endl;
                // rightNode.draw_lines();
                // leftNode.draw_lines();
            }
            circleCentersIndex = circleCentersIndex + numberOfNodes;
        }
    }
}

#define RECTANGLE_WIDTH 25
#define RECTANGLE_HEIGHT 25

class Binary_tree_with_different_node : public Binary_tree
{
    private:
        Graph_lib::Point centerPoint;
        int level;
    public:
        Binary_tree_with_different_node(Graph_lib::Point centerPoint, int level) :
            centerPoint(centerPoint), level(level), Binary_tree(centerPoint, level)
        {  }
        void draw_node(Graph_lib::Point topLeft, int radius) const override // if I'm overriding a function, it needs to
                                                                            // have the same signature as its virtual one
        {
            Graph_lib::Rectangle r {topLeft, RECTANGLE_WIDTH, RECTANGLE_HEIGHT};
            r.draw_lines();
        }
};

*/

// 13. Modify Binary_tree to take a parameter (or parameters) to indicate what kind of line to use to connect the nodes
// (e.g., an arrow pointing down or a red arrow pointing up).
// Note how this exercise and the last use two alternative ways of making a class hierarchy more flexible and useful.

// I'd have to define an arrow pointing line which could have a changeable line-style... I'll look into this

class Arrow_line : public Shape
{
    private:
        Graph_lib::Point startPoint;
        Graph_lib::Point endPoint;
    public:
        Arrow_line(Graph_lib::Point startPoint, Graph_lib::Point endPoint) : startPoint(startPoint), endPoint(endPoint) { }
        void draw_lines() const;
};

#define ARROW_LINE_ARROWHEAD_ANGLE 45
#define ARROW_LINE_ARROW_SEGMENT_LENGTH 20


void Arrow_line::draw_lines() const
{
    fl_line(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
    float xMovement = sin((ARROW_LINE_ARROWHEAD_ANGLE*PI)/180) * ARROW_LINE_ARROW_SEGMENT_LENGTH;
    float yMovement = cos((ARROW_LINE_ARROWHEAD_ANGLE*PI)/180) * ARROW_LINE_ARROW_SEGMENT_LENGTH;
    // this movement below isn't right... I don't draw the arrowtip right...
    Graph_lib::Point leftArrowheadPoint {endPoint.x - xMovement, endPoint.y - yMovement};
    Graph_lib::Point rightArrowheadPoint {endPoint.x + xMovement, endPoint.y - yMovement};
    fl_line(endPoint.x, endPoint.y, leftArrowheadPoint.x, leftArrowheadPoint.y);
    fl_line(endPoint.x, endPoint.y, rightArrowheadPoint.x, rightArrowheadPoint.y);
}

/*

class Binary_tree : public Shape
{
    private:
        Graph_lib::Point centerPoint;
        int level;
        Graph_lib::Line_style line_style;
        Graph_lib::Color color;
        bool arrow;
    public:
        Binary_tree(Graph_lib::Point centerPoint, int level, Graph_lib::Line_style line_style, Graph_lib::Color color, bool arrow) :
            centerPoint(centerPoint), level(level), line_style(line_style), color(color), arrow(arrow)
            {
                // bool arrow will be used for specifying if I'll use Arrow_line as a connector between the nodes
                // this sets style and color for the entire binary tree, including the nodes
                Graph_lib::Shape::set_style(line_style);
                Graph_lib::Shape::set_color(color);
            }
        void draw_lines() const;
};

#define BINARY_TREE_NODE_SIZE 15
#define BINARY_TREE_CONNECTION_ANGLE 45
#define BINARY_TREE_CONNECTION_LINE_LENGTH 20

// #define or const? ...

// to-fix: the right child of the left node and the left child of the right node are the same
void Binary_tree::draw_lines() const
{
    Graph_lib::Vector_ref<Graph_lib::Point> circleCenters;
    circleCenters.push_back(new Point{centerPoint.x, centerPoint.y});
    int circleCentersIndex = 0;
    for (int i = 0; i < level; i++)
    {
        int numberOfNodes = pow(2, i);
        for (int k = circleCentersIndex; k < circleCenters.size(); k++)
        {
            Circle c{circleCenters[k], BINARY_TREE_NODE_SIZE};
            c.draw_lines();
        }
        if ((i + 1) != level)
        {
            for (int k = circleCentersIndex; k < (numberOfNodes + circleCentersIndex); k++)
            {
                float circleYMovement = cos((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * BINARY_TREE_NODE_SIZE;
                float circleXMovement = sin((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * BINARY_TREE_NODE_SIZE;
                Graph_lib::Point rightPointOnTheCircle{circleCenters[k].x + circleXMovement, circleCenters[k].y + circleYMovement};
                Graph_lib::Point leftPointOnTheCircle {circleCenters[k].x - circleXMovement, circleCenters[k].y + circleYMovement};
                float connectionMovementX = sin((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * (BINARY_TREE_NODE_SIZE + BINARY_TREE_CONNECTION_LINE_LENGTH);
                float connectionMovementY = cos((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * (BINARY_TREE_NODE_SIZE + BINARY_TREE_CONNECTION_LINE_LENGTH);
                Graph_lib::Point rightPointConnection{circleCenters[k].x + connectionMovementX, circleCenters[k].y + connectionMovementY};
                Graph_lib::Point leftPointConnection{circleCenters[k].x - connectionMovementX, circleCenters[k].y + connectionMovementY};
                fl_line(rightPointOnTheCircle.x, rightPointOnTheCircle.y, rightPointConnection.x, rightPointConnection.y);
                fl_line(leftPointOnTheCircle.x, leftPointOnTheCircle.y, leftPointConnection.x, leftPointConnection.y);
                float nodeCenterMovementX = sin((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * (2 * BINARY_TREE_NODE_SIZE + BINARY_TREE_CONNECTION_LINE_LENGTH);
                float nodeCenterMovementY = cos((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * (2 * BINARY_TREE_NODE_SIZE + BINARY_TREE_CONNECTION_LINE_LENGTH);
                Graph_lib::Point rightNodeCenter{circleCenters[k].x + nodeCenterMovementX, circleCenters[k].y + nodeCenterMovementY};
                Graph_lib::Point leftNodeCenter{circleCenters[k].x - nodeCenterMovementX, circleCenters[k].y + nodeCenterMovementY};
                circleCenters.push_back(new Point{rightNodeCenter.x, rightNodeCenter.y});
                circleCenters.push_back(new Point{leftNodeCenter.x, leftNodeCenter.y});
            }
            circleCentersIndex = circleCentersIndex + numberOfNodes;
        }
    }
}

*/

// 14. Add an operation to Binary_tree that adds text to a node. You may have to modify the design of Binary_tree
// to implement this elegantly. Choose a way to identify a node; for example, you might give a string 'lrrlr'
// for navigating left, right, right, left, and right down a binary tree
// (the root node would match both an initial l and an initial r).

// hmmmm... Let me try this...

class Binary_tree : public Shape
{
    private:
        Graph_lib::Point centerPoint;
        int level;
        Graph_lib::Line_style line_style {Graph_lib::Line_style::solid};
        Graph_lib::Color color {Graph_lib::Color::black};
        bool arrow;
    public:
        Binary_tree(Graph_lib::Point centerPoint, int level, Graph_lib::Line_style line_style, Graph_lib::Color color, bool arrow) :
            centerPoint(centerPoint), level(level), line_style(line_style), color(color), arrow(arrow)
            {
                // bool arrow will be used for specifying if I'll use Arrow_line as a connector between the nodes
                // this sets style and color for the entire binary tree, including the nodes
                Graph_lib::Shape::set_style(line_style);
                Graph_lib::Shape::set_color(color);
            }
        Binary_tree(Graph_lib::Point centerPoint, int level) : centerPoint(centerPoint), level(level) { }
        void draw_lines() const;
        void add_text(string movement, string textToAdd);
};

#define BINARY_TREE_NODE_SIZE 15
#define BINARY_TREE_CONNECTION_ANGLE 45
#define BINARY_TREE_CONNECTION_LINE_LENGTH 20

// #define or const? it's better to use const, which I'll use from the next chapter (because of type checking)

// to-fix: the right child of the left node and the left child of the right node are the same
void Binary_tree::draw_lines() const
{
    Graph_lib::Vector_ref<Graph_lib::Point> circleCenters;
    circleCenters.push_back(new Point{centerPoint.x, centerPoint.y});
    int circleCentersIndex = 0;
    for (int i = 0; i < level; i++)
    {
        int numberOfNodes = pow(2, i);
        for (int k = circleCentersIndex; k < circleCenters.size(); k++)
        {
            Circle c{circleCenters[k], BINARY_TREE_NODE_SIZE};
            c.draw_lines();
        }
        if ((i + 1) != level)
        {
            for (int k = circleCentersIndex; k < (numberOfNodes + circleCentersIndex); k++)
            {
                float circleYMovement = cos((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * BINARY_TREE_NODE_SIZE;
                float circleXMovement = sin((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * BINARY_TREE_NODE_SIZE;
                Graph_lib::Point rightPointOnTheCircle{circleCenters[k].x + circleXMovement, circleCenters[k].y + circleYMovement};
                Graph_lib::Point leftPointOnTheCircle {circleCenters[k].x - circleXMovement, circleCenters[k].y + circleYMovement};
                float connectionMovementX = sin((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * (BINARY_TREE_NODE_SIZE + BINARY_TREE_CONNECTION_LINE_LENGTH);
                float connectionMovementY = cos((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * (BINARY_TREE_NODE_SIZE + BINARY_TREE_CONNECTION_LINE_LENGTH);
                Graph_lib::Point rightPointConnection{circleCenters[k].x + connectionMovementX, circleCenters[k].y + connectionMovementY};
                Graph_lib::Point leftPointConnection{circleCenters[k].x - connectionMovementX, circleCenters[k].y + connectionMovementY};
                fl_line(rightPointOnTheCircle.x, rightPointOnTheCircle.y, rightPointConnection.x, rightPointConnection.y);
                fl_line(leftPointOnTheCircle.x, leftPointOnTheCircle.y, leftPointConnection.x, leftPointConnection.y);
                float nodeCenterMovementX = sin((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * (2 * BINARY_TREE_NODE_SIZE + BINARY_TREE_CONNECTION_LINE_LENGTH);
                float nodeCenterMovementY = cos((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * (2 * BINARY_TREE_NODE_SIZE + BINARY_TREE_CONNECTION_LINE_LENGTH);
                Graph_lib::Point rightNodeCenter{circleCenters[k].x + nodeCenterMovementX, circleCenters[k].y + nodeCenterMovementY};
                Graph_lib::Point leftNodeCenter{circleCenters[k].x - nodeCenterMovementX, circleCenters[k].y + nodeCenterMovementY};
                circleCenters.push_back(new Point{rightNodeCenter.x, rightNodeCenter.y});
                circleCenters.push_back(new Point{leftNodeCenter.x, leftNodeCenter.y});
            }
            circleCentersIndex = circleCentersIndex + numberOfNodes;
        }
    }
}

void Binary_tree::add_text(string movement, string textToAdd)
{
    // r represents moving to the right, while l represents moving to the right
    // first l or r represents the root node
    Graph_lib::Point currentNode = centerPoint;
    for (int i = 1; i < movement.size(); i++)
    {
        char c = movement[i];
        float nodeCenterMovementX = sin((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * (2 * BINARY_TREE_NODE_SIZE + BINARY_TREE_CONNECTION_LINE_LENGTH);
        float nodeCenterMovementY = cos((BINARY_TREE_CONNECTION_ANGLE*PI) / 180) * (2 * BINARY_TREE_NODE_SIZE + BINARY_TREE_CONNECTION_LINE_LENGTH);
        if (c == 'l')
        {
            // Graph_lib::Point leftNodeCenter{currentNode.x - nodeCenterMovementX, currentNode.y + nodeCenterMovementY};
            // currentNode = Graph_lib::Point{currentNode.x - nodeCenterMovementX, currentNode.y + nodeCenterMovementY};
            currentNode.x = currentNode.x - nodeCenterMovementX;
            currentNode.y = currentNode.y + nodeCenterMovementY;
        }
        else if (c == 'r')
        {
            // Graph_lib::Point rightNodeCenter{currentNode.x + nodeCenterMovementX, currentNode.y + nodeCenterMovementY};
            // currentNode = Graph_lib::Point{currentNode.x + nodeCenterMovementX, currentNode.y + nodeCenterMovementY};
            currentNode.x = currentNode.x + nodeCenterMovementX;
            currentNode.y = currentNode.y + nodeCenterMovementY;
        }
    }
    Graph_lib::Text t {currentNode, textToAdd};
    t.draw_lines(); // I get SEGFAULT here... Hmmmm...
}

// 15. Most class hierarchies have nothing to do with graphics. Define a class Iterator with a pure virtual function next()
// that returns a double* (see Chapter 17). Now derive Vector_iterator and List_iterator from Iterator so that next()
// for a Vector_iterator yields a pointer to the next element of a vector<double> and List_iterator does the same for a
// list<double>. You initialize a Vector_iterator with a vector<double> and the first call of next() yields a pointer to
// its first element, if any. If there is no next element, return 0. Test this by using a function void print(Iterator&) to
// print the elements of a vector<double> and a list<double>.

// I'll get back to this once I read Chapter 17

// 16. Define a class Controller with four virtual functions on(), off(), set_level(int), and show().
// Derive at least two classes from Controller. One should be a simple test class where show() prints out whether the class
// is set to on or off and what is the current level. The second derived class should somehow control the line color of a Shape;
// the exact meaning of “level” is up to you. Try to find a third “thing” to control with such a Controller class.

class Controller : protected Shape
{
    protected:
        bool isOn {false};
        int level;
        Graph_lib::Color color {Graph_lib::Color::black};
    public:
        Controller(bool isOn, int level) : isOn(isOn), level(level) { }
        Controller() { } // constructor is inherited in C++11
        virtual void on()
        {
            isOn = true;
        }
        virtual void off()
        {
            isOn = false;
        }
        virtual void set_level(int level)
        {
            level = level;
        }
        virtual void show()
        {
            cout << "Base show()" << endl;
        }
};

class Derived1 : public Controller
{
    public:
        void show() override
        {
            if (isOn == true)
            {
                cout << "Class is on." << endl;
            }
            else
            {
                cout << "Class is off." << endl;
            }
            cout <<"Current level is: " << level << endl;
        }
};

class Derived2 : public Controller
{
    void changeColor(Graph_lib::Color colorToChangeTo)
    {
        color = colorToChangeTo;
    }
};

// 17. The exceptions defined in the C++ standard library, such as exception, runtime_error, and out_of_range (§5.6.3),
// are organized into a class hierarchy (with a useful virtual function what() returning a string supposedly explaining
// what went wrong). Search your information sources for the C++ standard exception class hierarchy and draw a class
// hierarchy diagram of it.

// -----------------------------------------------------------------------------------------------------------------------
// Chapter 15
// -----------------------------------------------------------------------------------------------------------------------

// Exercise 1 is about implementing factorial function as a iterative and as a recursive function.
// I have to admit, I wouldn't say I am at home ground with recursive functions,
// but sometimes a recursive soultion comes more easily and naturally than an iterative one

// 2. Define a class Fct that is just like Function except that it stores its constructor arguments.
// Provide Fct with “reset” operations, so that you can use it repeatedly for different ranges,
// different functions, etc.

/*
class Fct : public Shape
{
    private:
            Graph_lib::Fct f;
            double r1;
            double r2;
            Graph_lib::Point orig;
            int count;
            double xscale;
            double yscale;
    public:
        Fct(Graph_lib::Fct f, double r1, double r2, Graph_lib::Point orig, int count, double xscale, double yscale);
        void setFct (Graph_lib::Fct fToChangeTo) { f = fToChangeTo; } // fct is a function pointer... error here
        void setr1 (double r1ToChangeTo) { r1 = r1ToChangeTo; }
        void setr2 (double r2ToChangeTo) { r2 = r2ToChangeTo; }
        void setOrig(Graph_lib::Point origToChangeTo) {orig = origToChangeTo; }
        void setCount(int countToChangeTo) { count = countToChangeTo; }
        void setXScale (double xscaleToChangeTo) {xscale = xscaleToChangeTo; }
        void setYScale (double yscaleToChangeTo) {yscale = yscaleToChangeTo; }
};

::Fct::Fct(Graph_lib::Fct f, double r1, double r2, Graph_lib::Point orig, int count = 100, double xscale = 25, double yscale = 25) :
    f(f), r1(r1), r2(r2), orig(orig), count(count), xscale(xscale), yscale(yscale)
// graph f(x) for x in [r1:r2) using count line segments with (0,0) displayed at xy
// x coordinates are scaled by xscale and y coordinates scaled by yscale
{
	if (r2-r1<=0) error("bad graphing range");
	if (count<=0) error("non-positive graphing count");
	double dist = (r2-r1)/count;
	double r = r1;
	for (int i = 0; i<count; ++i) {
		add(Point(orig.x+int(r*xscale),orig.y-int(f(r)*yscale)));
		r += dist;
	}
}

*/

// 3. Modify Fct from the previous exercise to take an extra argument to control precision or whatever.
// Make the type of that argument a template parameter for extra flexibility.

// I'll tackle this when I go through the template chapter

//5. “Animate” (as in §15.5) the series 1–1/3+1/5–1/7+1/9–1/11+ . . . . It is known as Leibniz’s series and converges to pi/4.
// I'll tackle this later... It is just a matter of writing an appropriate function

// 6. Design and implement a bar graph class. Its basic data is a vector<double> holding N values,
// and each value should be represented by a “bar” that is a rectangle where the height represents the value.

/*

class Bar_graph : public Shape
{
    private:
        vector<double> heights;
        int lowRange;
        int highRange;

    public:
        Bar_graph(vector<double> heightsArgument, int lowRange, int highRange) : lowRange(lowRange), highRange(highRange)
        // I could pass Graph_lib::Axis here as an argument...
        {
            for (int i = 0; i < heightsArgument.size(); i++)
            {
                heights.push_back(heightsArgument[i]);
            }
        }
        void draw_lines() const;
};

void Bar_graph::draw_lines() const
{
    constexpr int axisLength = 400;
    int numberOfNotches = (highRange / 10) * 10 + 10;
    int rectangleWidth = axisLength / heights.size(); // this isn't really set up to the number of notches
    Graph_lib::Axis x {Graph_lib::Axis::Orientation::x, Graph_lib::Point{10, 550}, axisLength, numberOfNotches, "X axis"};
    x.draw_lines();
    Graph_lib::Axis y {Graph_lib::Axis::Orientation::y, Graph_lib::Point{10, 550}, axisLength, numberOfNotches, "Y axis"};
    y.draw_lines();
    int notchHeight = axisLength / numberOfNotches;
    for (int i = 0; i < heights.size(); i++)
    {
        Graph_lib::Point startPoint {10 + (i * rectangleWidth), 550 - (heights[i] * notchHeight)};
        Graph_lib::Rectangle r{startPoint, rectangleWidth, (heights[i] * notchHeight)};
        // here I could write a custom method for flipping one side of the Rectangle...
        // or I could calculate the height of the startPoint and change my arguments to the Rectangle constructor
        r.draw_lines();
    }
}

*/

//7. Elaborate the bar graph class to allow labeling of the graph itself and its individual bars. Allow the use of color.

// the problem here is - how do I set the label of each bar and how to label the graph itself...

constexpr int axisLength = 400;
constexpr int xAxisStartCoordinate = 10;
constexpr int yAxisStartCoordinate = 550;

class Bar_graph : public Shape
{
    private:
        vector<double> heights;
        int lowRange;
        int highRange;
        int rectangleWidthMember; // I added this so I can add labels to each individual bar (maybe there's a better way?)
        Graph_lib::Point startPointMember;

    public:
        Bar_graph(vector<double> heightsArgument, int lowRange, int highRange) : lowRange(lowRange), highRange(highRange),
        startPointMember{xAxisStartCoordinate, yAxisStartCoordinate}
        // I could pass Graph_lib::Axis here as an argument...
        {
            for (int i = 0; i < heightsArgument.size(); i++)
            {
                heights.push_back(heightsArgument[i]);
            }
            int rectangleWidth = axisLength / heights.size(); // this isn't really set up to the number of notches
            rectangleWidthMember = rectangleWidth;

        }
        void draw_lines() const;
        void set_graph_label(string graphLabel);
        void set_bar_label(int barNumber, string graphLabel);
        void set_bar_color(int barNumber, Graph_lib::Color c); // ovo moram implementirati
};

void Bar_graph::draw_lines() const
{
    int numberOfNotches = (highRange / 10) * 10 + 10;
    int rectangleWidth = rectangleWidthMember;
    // somehow I need to get rectangleWidth from here to set_graph_label() function, but since draw_lines() is const
    // I can't assign a member inside the draw_lines() function...

    Graph_lib::Axis x {Graph_lib::Axis::Orientation::x, Graph_lib::Point{xAxisStartCoordinate, yAxisStartCoordinate}, axisLength, numberOfNotches, "X axis"};
    x.draw_lines();
    Graph_lib::Axis y {Graph_lib::Axis::Orientation::y, Graph_lib::Point{xAxisStartCoordinate, yAxisStartCoordinate}, axisLength, numberOfNotches, "Y axis"};
    y.draw_lines();
    int notchHeight = axisLength / numberOfNotches;
    for (int i = 0; i < heights.size(); i++)
    {
        Graph_lib::Point startPoint {10 + (i * rectangleWidth), 550 - (heights[i] * notchHeight)};
        Graph_lib::Rectangle r{startPoint, rectangleWidth, (heights[i] * notchHeight)};
        // here I could write a custom method for flipping one side of the Rectangle...
        // or I could calculate the height of the startPoint and change my arguments to the Rectangle constructor
        r.draw_lines();
    }
}

constexpr int xmax = 600;
constexpr int ymax = 600;

void Bar_graph::set_graph_label(string graphLabel)
{
    // put the coordinates near the end of the window (at the cost of making those variables global, but
    // they are consts anyway)
    constexpr int offset = 10;
    constexpr int xCoordinate = xmax - offset;
    constexpr int yCoordinate = ymax - offset;
    Graph_lib::Text t {Graph_lib::Point{xCoordinate, yCoordinate}, graphLabel};
    t.draw_lines();
}

void Bar_graph::set_bar_label(int barNumber, string graphLabel)
{
    Graph_lib::Point startPoint = startPointMember;
    for (int i = 0; i < barNumber; i++)
    {
        startPoint.x += rectangleWidthMember;
    }
    startPoint.y -= 5; // lower the y down a bit
    startPoint.x += (rectangleWidthMember / 4); // "center" the text a bit
    Graph_lib::Text t{startPoint, graphLabel};
    t.draw_lines(); // segfault here again... hmmm
}

// 8. Here is a collection of heights in centimeters together with the number of people in a group of that height
// (rounded to the nearest 5cm): (170,7), (175,9), (180,23), (185,17), (190,6), (195,1). How would you graph that data?
// If you can’t think of anything better, do a bar graph. Remember to provide axes and labels.
// Place the data in a file and read it from that file.

// For this task, I'll have to modify my Bar_graph (I'll call it Bar_graph_modified) so that it
// can calculate notches based on the first number in the ordered pair (height, number of people)

struct Reading // reading as it pertains to Exercise 8 above
{
    int height;
    int numberOfPeopleWithThatHeight;
};

istream& operator>> (istream& is, Reading& r)
{
    char ch1, ch2, ch3, ch4;
    int height, numberOfPeopleWithThatHeight;
    is >> ch1 >> height >> ch2 >> numberOfPeopleWithThatHeight >> ch3 >> ch4;
    if ((ch1 != '(') || (ch2 != ',') || (ch3 != ')') || (ch4 != ','))
    {
        error("Format not valid.");
    }
    r.height = height;
    r.numberOfPeopleWithThatHeight = numberOfPeopleWithThatHeight;
    return is;
}

// I'll have to read the data from a file

class Bar_graph_modified : public Shape
{
    private:
        vector<Reading> readings;
    public:
        Bar_graph_modified(vector<Reading> data)
        {
            for (int i = 0; i < data.size(); i++)
            {
                readings.push_back(data[i]);
            }
        }
        void draw_lines() const;
};

void Bar_graph_modified::draw_lines() const
{
    constexpr int axisLength = 400;
    int max = 0;
    for (int i = 0; i < readings.size(); i++)
    {
        if (readings[i].numberOfPeopleWithThatHeight > max)
        {
            max = readings[i].numberOfPeopleWithThatHeight;
        }
    }
    int numberOfNotches = max;
    int rectangleWidth = axisLength / readings.size(); // this isn't really set up to the number of notches
    Graph_lib::Axis x {Graph_lib::Axis::Orientation::x, Graph_lib::Point{10, 550}, axisLength, numberOfNotches, "X axis"};
    x.draw_lines();
    Graph_lib::Axis y {Graph_lib::Axis::Orientation::y, Graph_lib::Point{10, 550}, axisLength, numberOfNotches, "Y axis"};
    y.draw_lines();
    int notchHeight = axisLength / numberOfNotches;
    for (int i = 0; i < readings.size(); i++)
    {
        cout << "Drawing the bar for " << readings[i].height << endl;
        Graph_lib::Point startPoint {10 + (i * rectangleWidth), 550 - (readings[i].numberOfPeopleWithThatHeight * notchHeight)};
        Graph_lib::Rectangle r{startPoint, rectangleWidth, (readings[i].numberOfPeopleWithThatHeight * notchHeight)};
        // here I could write a custom method for flipping one side of the Rectangle...
        // or I could calculate the height of the startPoint and change my arguments to the Rectangle constructor
        r.draw_lines();
        stringstream ss;
        ss << readings[i].height;
        Text t {Graph_lib::Point{startPoint.x + (rectangleWidth / 4), startPoint.y + 15}, ss.str()};
        // 15 in startPoint.y + 15 is a magic constant, but it serves to shift the heights a little bit downward
        t.draw_lines();
    }
}

// 9. Find another data set of heights (an inch is 2.54cm) and graph them with your program from the previous exercise.
// For example, search the web for “height distribution” or “height of people in the United States” and ignore a lot of
// rubbish or ask your friends for their heights. Ideally, you don’t have to change anything for the new data set.
// Calculating the scaling from the data is a key idea. Reading in labels from input also helps minimize changes when you
// want to reuse code.

// I already made reading labels automatic (labels are heights), but I could change my struct Reading
// and include the labels specifically as a string

// 10. What kind of data is unsuitable for a line graph or a bar graph?
// Find an example and find a way of displaying it (e.g., as a collection of labeled points).

// I think even a collection of labeled points can be connected via a line graph
// Only if there are a lot of those points and the neighbouring ones are really far away from each other on the y axis,
// then I'd consider just plotting the dots

// 11. Find the average maximum temperatures for each month of the year for two or more locations (e.g., Cambridge, England,
// and Cambridge, Massachusetts; there are lots of towns called “Cambridge”) and graph them together.
// As ever, be careful with axes, labels, use of color, etc.

// Use a Graph_lib::Point to graph the average maximum temperature as a point? That's my idea.

#endif // CHAPTER_12-15_H_INCLUDED
