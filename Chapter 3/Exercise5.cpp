#include <iostream>

using namespace std;

// 5 Modify the program above (Exercise 4) to ask the user to enter floating-point values and store them in double variables.
// Compare the outputs of the two programs for some inputs of your choice. Are the results the same? Should they be?
// What’s the difference?

int main()
{
    double val1;
    double val2;
    cout << "Enter 2 decimal numbers: ";
    cin >> val1 >> val2;
    cout << endl;
    if (val1 < val2)
    {
        cout << "First number is smaller then the second." << endl;
    }
    else
    {
        cout << "Second number is smaller then the first." << endl;
    }
    cout << "Sum of the numbers is: " << (val1 + val2) << endl;
    cout << "Difference of the 2 numbers is: " << (val1 - val2) << endl;
    cout << "Product of the 2 numbers is: " << (val1 * val2) << endl;
    cout << "Ratio of the 2 numbers is: " << (val1 / val2) << endl;
    return 0;
}
