#include <iostream>

using namespace std;

// 4 Write a program that prompts the user to enter two integer values. Store these values in int variables named val1 and val2.
// Write your program to determine the smaller, larger, sum, difference, product, and ratio of these values and report
// them to the user.

int main()
{
    int val1;
    int val2;
    cout << "Enter 2 whole numbers: ";
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
