#include "Simple_window.h"
#include "Graph.h"

//1. Make a My_window that’s a bit like Simple_window except that it has two buttons, next and quit.

class My_window : public Graph_lib::Window
{
    private:
        Graph_lib::Point topLeft;
        int width;
        int height;
        string windowTitle;
        Graph_lib::Button nextButton;
        Graph_lib::Button quitButton;
        bool button_pushed {false};
        static void cb_next(Address, Address addr) // callback for next_button
        //	{ reference_to<Simple_window>(addr).next(); }
        {
            static_cast<My_window*>(addr)->next();
        }
        static void cb_quit(Address, Address pw)
        {
            reference_to<My_window>(pw).quit();
        }
        void next() { button_pushed = true; }
        void quit() { hide(); }
    public:
        My_window(Graph_lib::Point topLeft, int width, int height, string windowTitle) :
            topLeft(topLeft), width(width), height(height), windowTitle(windowTitle),
            Graph_lib::Window(topLeft, width, height, windowTitle),
            nextButton{Graph_lib::Point{x_max() - 70, 0}, 70, 20, "Next", cb_next},
            quitButton{Graph_lib::Point{x_max() - 70, 20}, 70, 20, "Quit", cb_quit}
        {
            attach(nextButton);
            attach(quitButton);
        }

    void wait_for_button()
	// modified event loop
	// handle all events (as per default), but quit when button_pushed becomes true
	// this allows graphics without control inversion
	{
		while (!button_pushed) Fl::wait();
		button_pushed = false;
		Fl::redraw();
	}

};

// 2. Make a window (based on My_window) with a 4-by-4 checkerboard of square buttons. When pressed,
// a button performs a simple action, such as printing its coordinates in an output box,
// or turns a slightly different color (until another button is pressed).

class Checkerboard : public My_window
{
    private:
        int width;
        int height;
        Graph_lib::Vector_ref<Graph_lib::Button> buttons;
        static void cb_action(Address, Address pw)
        {
            reference_to<Checkerboard>(pw).action();
        }
        void action()
        {
            // it would be interesting to see how I could get button's coordinates here...
            // this is left as a to-do
            cout << "Action" << endl;
        }
    public:
        Checkerboard(Graph_lib::Point topLeft, int width, int height, string title) :
            width(width), height(height),
            My_window{topLeft, width, height, title}
        {
            constexpr int numberOfButtons = 16; // 4 x 4 grid, as defined in the exercise
            int buttonWidth = width / 4;
            int buttonHeight = height / 4;
            for (int i = 0; i < 4; i++) // you could say that 4 here is a magic constant, but the exercise requires a 4x4 grid
            {
                for (int j = 0; j < 4; j++)
                {
                    stringstream sstream;
                    sstream << "Button " <<  4 * i + j;
                    buttons.push_back(new Graph_lib::Button{Graph_lib::Point{j * buttonWidth, i * buttonHeight}, buttonWidth, buttonHeight, sstream.str(), cb_action});
                }
            }
            for (int i = 0; i < numberOfButtons; i++)
            {
                attach(buttons[i]);
            }
        }
};

// 3. Place an Image on top of a Button; move both when the button is pushed.

// I have to know how much an Image and a Button can move within the window (so they don't go out of the window)
// window size - distance from the top left corner would be the maximum

// This function (rand_int) is for the purpose of this exercise

/*

#include<random>

inline int rand_int(int min, int max)
{
          static default_random_engine ran;
          return uniform_int_distribution<>{min,max}(ran);
}

class Image_Button_Window : public My_window
{
    private:
        Graph_lib::Image image;
        Graph_lib::Button buttonForTheImage;
        Graph_lib::Point topLeftWindowPoint;
        int windowWidth;
        int windowHeight;
        static void cb_action(Address, Address pw)
        {
            reference_to<Image_Button_Window>(pw).action();
        }
        void action()
        {
            int xMoveAmount = rand_int(-(windowWidth / 2), windowWidth / 2); // not such a sophisticated calculation
            int yMoveAmount = rand_int(-(windowWidth / 2), windowWidth / 2);
            buttonForTheImage.move(xMoveAmount, yMoveAmount);
            image.move(xMoveAmount, yMoveAmount);
        }
    public:
        Image_Button_Window(Graph_lib::Point topLeft, int width, int height, string title) :
            My_window{topLeft, width, height, title}, windowWidth(width), windowHeight(height), topLeftWindowPoint(topLeft)
            // error: no matching function for call to 'Graph_lib::Image::Image()' on the line above
            // error: no matching function for call to 'Graph_lib::Button::Button()' on two lines above
        {
            constexpr int imageWidth = 100;
            constexpr int imageHeight = 100;
            int buttonXCoordinate = rand_int(0, width);
            int buttonYCoordinate = rand_int(0, height);
            buttonForTheImage{Graph_lib::Point{buttonXCoordinate, buttonYCoordinate}, imageWidth, imageHeight, " ", cb_action};
            image{Graph_lib::Point{buttonXCoordinate, buttonYCoordinate}, "C:\Users\Jadranka\Dropbox\Projekti i source fileovi\Programming - Principles and Practice exercises\Chapter 16\Chapter 16 project\photo.jpg", Graph_lib::Suffix::jpg};
            attach(buttonForTheImage);
            attach(image);
        }
};

*/

// 4. Make a menu with items that make a circle, a square, an equilateral triangle, and a hexagon, respectively.
// Make an input box (or two) for giving a coordinate pair, and place the shape made by pressing a menu item at that coordinate.
// Sorry, no drag and drop.

/*

class Square : public Shape // I define this for the purpose of this exercise
{
    private:
        int sideLength;
        Graph_lib::Point topLeft;
    public:
        Square(Graph_lib::Point topLeft, int sideLength) : topLeft(topLeft), sideLength(sideLength)
        {
            // first point is topLeft
            Graph_lib::Point secondPoint{topLeft.x + sideLength, topLeft.y};
            Graph_lib::Point thirdPoint{topLeft.x, topLeft.y + sideLength};
            Graph_lib::Point fourthPoint{topLeft.x + sideLength, topLeft.y + sideLength};
            fl_line(topLeft.x, topLeft.y, secondPoint.x, secondPoint.y);
            fl_line(topLeft.x, topLeft.y, thirdPoint.x, thirdPoint.y);
            fl_line(secondPoint.x, secondPoint.y, fourthPoint.x, fourthPoint.y);
            fl_line(thirdPoint.x, thirdPoint.y, fourthPoint.x, fourthPoint.y);
        }
};

// some consts for my Exercise 4
constexpr int buttonWidth = 70;
constexpr int buttonHeight = 20;

class Exercise4_window : public My_window
{
    private:
        Graph_lib::Button circleButton;
        Graph_lib::Button squareButton;
        Graph_lib::Button equiliteralTriangleButton;
        Graph_lib::Button hexagonButton;
        Graph_lib::In_box lengthInput;
        Graph_lib::In_box xCoordinateInput;
        Graph_lib::In_box yCoordinateInput;
        static void cb_circle(Address, Address pw)
        {
            reference_to<Exercise4_window>(pw).circle();
        }
        static void cb_square(Address, Address pw)
        {
            reference_to<Exercise4_window>(pw).square();
        }
        static void cb_triangle(Address, Address pw)
        {
            // reference_to<Exercise4_window>(pw).triangle();
        }
        static void cb_hexagon(Address, Address pw)
        {
            // reference_to<Exercise4_window>(pw).hexagon();
        }
        void circle()
        {
            int xCoordinate = xCoordinateInput.get_int();
            int yCoordinate = yCoordinateInput.get_int();
            int length = lengthInput.get_int();
            Graph_lib::Circle c{Graph_lib::Point{xCoordinate, yCoordinate}, length};
            attach(c);
        }
        void square()
        {
            int xCoordinate = xCoordinateInput.get_int();
            int yCoordinate = yCoordinateInput.get_int();
            int length = lengthInput.get_int();
            Square s{Graph_lib::Point{xCoordinate, yCoordinate}, length};
            attach(s);
        }
        // triangle() and hexagon() to be defined
    public:
        Exercise4_Window(Graph_lib::Point topLeft, int width, int height, string windowTitle) :
            My_window{topLeft, width, height, windowTitle}, // error: only constructors take member initializers
            circleButton{Graph_lib::Point{width - buttonWidth, 0}, buttonWidth, buttonHeight, "Circle", cb_circle},
            squareButton{Graph_lib::Point{width - buttonWidth, buttonHeight}, buttonWidth, buttonHeight, "Square", cb_square},
            equiliteralTriangleButton{Graph_lib::Point{width - buttonWidth, buttonHeight * 2}, buttonWidth, buttonHeight, "Equiliteral triangle", cb_triangle},
            hexagonButton{Graph_lib::Point{width - buttonWidth, buttonHeight * 3}, buttonWidth, buttonHeight, "Hexagon", cb_hexagon},
            lengthInput{Graph_lib::Point{0, 0}, buttonWidth, buttonHeight, "Length: "},
            xCoordinateInput{Graph_lib::Point{0, buttonHeight}, buttonWidth, buttonHeight, "X coordinate: "},
            yCoordinateInput{Graph_lib::Point{0, 2 * buttonHeight}, buttonWidth, buttonHeight, "Y coordinate: "}
        {
            attach(circleButton);
            attach(squareButton);
            attach(equiliteralTriangleButton);
            attach(hexagonButton);
        }
};

*/

//5. Write a program that draws a shape of your choice and moves it to a new point each time you click “Next.”
// The new point should be determined by a coordinate pair read from an input stream.

/*

// this struct is declared outside of the class because I use the struct in the overloaded >> operator
struct Exercise4_Movement
{
    int dx;
    int dy;
};

class Shape_moving_window : public Graph_lib::Window
{
    // for simplicity, I'll make this program move a circle, although I could pass a reference to another shape
    // in the constructor
    private:
        vector<Exercise4_Movement> movements;
        int currentIndex {0}; // this is so that I know where am I currently with my movements vector
        Graph_lib::Point topLeft;
        int width;
        int height;
        string windowTitle;
        string inputStreamTitle;
        ifstream inputFileStream;
        Graph_lib::Circle c;
        Graph_lib::Button nextButton;
        Graph_lib::Button quitButton;
        bool button_pushed {false};
        static void cb_next(Address, Address addr) // callback for next_button
        //	{ reference_to<Simple_window>(addr).next(); }
        {
            static_cast<Shape_moving_window*>(addr)->next();
        }
        static void cb_quit(Address, Address pw)
        {
            reference_to<Shape_moving_window>(pw).quit();
        }
        // readings will be formatted as so (dx, dy), (dx2, dy2), ...
        void next()
        {
            button_pushed = true;
            Exercise4_Movement m = movements[currentIndex];
            int dx = m.dx;
            int dy = m.dy;
            c.move(dx, dy);
            currentIndex++;
        }
        void quit() { hide(); }
    public:
        Shape_moving_window(Graph_lib::Point topLeft, int width, int height, string windowTitle, string inputStreamTitle,
                            Graph_lib::Point center, int radius) :
            topLeft(topLeft), width(width), height(height), windowTitle(windowTitle), inputStreamTitle(inputStreamTitle),
            Graph_lib::Window(topLeft, width, height, windowTitle),
            c{center, radius},
            nextButton{Graph_lib::Point{x_max() - 70, 0}, 70, 20, "Next", cb_next},
            quitButton{Graph_lib::Point{x_max() - 70, 20}, 70, 20, "Quit", cb_quit}
        {
            attach(nextButton);
            attach(quitButton);
            inputFileStream{inputStreamTitle}; // error: expected ';' before '{' token
            Exercise4_Movement temp;
            while (inputFileStream >> temp) // error: cannot bind 'std::basic_istream<char>' lvalue to 'std::basic_istream<char>&&'
                movements.push_back(temp);
            }
        }

    void wait_for_button()
	// modified event loop
	// handle all events (as per default), but quit when button_pushed becomes true
	// this allows graphics without control inversion
	{
		while (!button_pushed) Fl::wait();
		button_pushed = false;
		Fl::redraw();
	}
};

istream& operator >> (istream& is, Exercise4_Movement &m)
        {
            int dx;
            int dy;
            char ch1, ch2, ch3, ch4;
            is >> ch1 >> dx >> ch2 >> dy >> ch3 >> ch4;
            if ((ch1 != '(') || (ch2 != ',') || (ch3 != ')') || (ch4 != ','))
            {
                error("Bad formatting - class Exercise4_window");
            }
            m.dx = dx;
            m.dy = dy;
        }

*/

// 6. Make an “analog clock,” that is, a clock with hands that move. You get the time of day from the operating system through
// a library call. A major part of this exercise is to find the functions that give you the time of day and a way of waiting
// for a short period of time (e.g., a second for a clock tick) and to learn to use them based on the documentation you found.
// Hint: clock(), sleep().

// I'll come back to this later.

// 7. Using the techniques developed in the previous exercises, make an image of an airplane “fly around” in a window.
// Have a “Start” and a “Stop” button.

// I'll come back to this later.

// 8. Provide a currency converter. Read the conversion rates from a file on startup. Enter an amount in an input window
// and provide a way of selecting currencies to convert to and from (e.g., a pair of menus).

// I'll come back to this later. I have to fix my input stream and input operator errors.

// 9. Modify the calculator from Chapter 7 to get its input from an input box and return its results in an output box.

// This one is interesting... Hmmm...

// 10. Provide a program where you can choose among a set of functions (e.g., sin() and log()),
// provide parameters for those functions, and then graph them.

// Runtime error here: fl_line_style(): Could not create GDI pen.

/*

class Function_window : public My_window
{
    private:
        Graph_lib::In_box functionMinValue;
        Graph_lib::In_box functionMaxValue;
        Graph_lib::Menu functionListMenu;
        static void cb_log(Address, Address pw)
        {
            reference_to<Function_window>(pw).graphLog();
        }
        static void cb_sin(Address, Address pw)
        {
            reference_to<Function_window>(pw).graphSin();
        }
        static void cb_cos(Address, Address pw)
        {
            reference_to<Function_window>(pw).graphCos();
        }
        void graphLog()
        {
            int minValue = functionMinValue.get_int();
            int maxValue = functionMaxValue.get_int();
            Function functionToGraph{log, minValue, maxValue, Graph_lib::Point{x_max() / 2, y_max() / 2}};
            attach(functionToGraph);
        }
        void graphSin()
        {
            int minValue = functionMinValue.get_int();
            int maxValue = functionMaxValue.get_int();
            Function functionToGraph{sin, minValue, maxValue, Graph_lib::Point{x_max() / 2, y_max() / 2}};
            attach(functionToGraph);
        }
        void graphCos()
        {
            int minValue = functionMinValue.get_int();
            int maxValue = functionMaxValue.get_int();
            Function functionToGraph{cos, minValue, maxValue, Graph_lib::Point{x_max() / 2, y_max() / 2}};
            attach(functionToGraph);
        }
    public:
        // I could have passed a function pointer in the constructor, but I decided to add a menu
        // more menu options == more functions
        Function_window(Graph_lib::Point topLeft, int width, int height, string windowTitle) :
            My_window(topLeft, width, height, windowTitle),
            functionMinValue{Graph_lib::Point{x_max()-310,0}, 50, 20, "Min value:"},
            functionMaxValue{Graph_lib::Point{x_max()-150,0}, 50, 20, "Max value:"},
            functionListMenu{Graph_lib::Point{10,30}, 70, 20, Menu::vertical, "Function list"}
            {
                attach(functionMinValue);
                attach(functionMaxValue);
                functionListMenu.attach(new Graph_lib::Button{Graph_lib::Point{0,0},0,0,"log",cb_log});
                functionListMenu.attach(new Graph_lib::Button{Graph_lib::Point{0,0},0,0,"sin",cb_sin});
                functionListMenu.attach(new Graph_lib::Button{Graph_lib::Point{0,0},0,0,"cos",cb_cos});
                attach(functionListMenu);
            }
};

*/

int main()
{
    /*
    Image_button_window ibw{Graph_lib::Point{100, 100}, 600, 600, "Image-button window"};
    while (1)
    {
        ibw.wait_for_button();
    }
    */
    Function_window fw{Graph_lib::Point{100, 100}, 600, 600, "Function window"};
    fw.wait_for_button();
    return 0;
}
