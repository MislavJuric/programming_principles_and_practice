#include "std_lib_facilities.h"

using namespace std;

/*

7. Quadratic equations are of the form

a · x^2 + b · x + c = 0

To solve these, one uses the quadratic formula:

<formula for quadratic equations here>

There is a problem, though: if b2–4ac is less than zero, then it will fail. Write a program that can calculate x for a quadratic equation. Create a function that prints out the roots of a quadratic equation, given a, b, c. When the program detects an equation with no real roots, have it print out a message. How do you know that your results are plausible? Can you check that they are correct?

*/

int SolveQuadriaticEquation(int a, int b, int c)
{
    int result;
    if ((pow(b, 2) - (4 * a * c)) < 0)
    {
        error("I can't solve this equation.");
        return 1;
    }
    result = ((-1 * b) + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
    return result;
}

int main()
{
    try
    {
        int a, b, c;
        cin >> a >> b >> c;
        int result = SolveQuadriaticEquation(a, b, c);
        if (result != 1)
        {
            cout << result << endl;
        }
   }
    catch (runtime_error)
    {
        cout << "I can't solve that equation" << endl;
    }
    return 0;
}
