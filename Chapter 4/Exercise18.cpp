#include <iostream>
#include <cmath>

using namespace std;

/*

18. Write a program to solve quadratic equations. A quadratic equation is of the form

ax2 + bx + c = 0

If you don’t know the quadratic formula for solving such an expression, do some research. Remember, researching how to solve a problem is often necessary before a programmer can teach the computer how to solve it. Use doubles for the user inputs for a, b, and c. Since there are two solutions to a quadratic equation, output both x1 and x2.

*/

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double x1 = (-b+sqrt(pow(b, 2) - 4*a*c))/(2*a);
    double x2 = (-b-sqrt(pow(b, 2) - 4*a*c))/(2*a);
    cout << x1 << " " << x2 << endl;
    return 0;
}
