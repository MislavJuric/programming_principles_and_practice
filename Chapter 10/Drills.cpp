#include "../std_lib_facilities.h"

/*
    1. Start a program to work with points, discussed in §10.4. Begin by defining the data type Point that has two coordinate members x and y.

    2. Using the code and discussion in §10.4, prompt the user to input seven (x,y) pairs. As the data is entered, store it in a vector of Points called original_points.

    3. Print the data in original_points to see what it looks like.

    4. Open an ofstream and output each point to a file named mydata.txt. On Windows, we suggest the .txt suffix to make it easier to look at the data with an ordinary text editor (such as WordPad).

    5. Close the ofstream and then open an ifstream for mydata.txt. Read the data from mydata.txt and store it in a new vector called processed_points.

    6. Print the data elements from both vectors.

    7. Compare the two vectors and print Something's wrong! if the number of elements or the values of elements differ.
*/

struct Point
{
    int x;
    int y;
};

istream& operator >> (istream& is, Point& p)
{
    int x, y;
    is >> x;
    is >> y;
    p.x = x;
    p.y = y;
    return is;

}

const int num_of_elements = 8;

int main()
{
    vector<Point> original_points;
    for (int i = 0; i < num_of_elements; i++)
    {
        int x, y = 0;
        cin >> x >> y;
        original_points.push_back(Point{x, y});
    }
    const string filename = "mydata.txt";
    ofstream ost {filename};
    for (int i = 0; i < num_of_elements; i++)
    {
        ost << original_points[i].x << " " << original_points[i].y << '\n';
    }
    ost.close();
    ifstream ist {filename};
    vector<Point> processed_points;
    for (Point p; ist >> p;)
    {
        processed_points.push_back(p);
    }
    for (int i = 0; i < num_of_elements; i++)
    {
        if ((original_points[i].x != processed_points[i].x) || (original_points[i].y != processed_points[i].y))
        {
            cout << "Something is wrong!" << endl;
        }
    }
    if (original_points.size() != processed_points.size())
    {
        cout << "Something is wrong!" << endl;
    }
    return 0;
}
