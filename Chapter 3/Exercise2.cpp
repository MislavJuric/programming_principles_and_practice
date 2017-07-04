#include <iostream>

using namespace std;

// 2 Write a program in C++ that converts from miles to kilometers. Your program should have a reasonable prompt for the user
// to enter a number of miles. Hint: There are 1.609 kilometers to the mile.

int main()
{
    double miles;
    cout << "Enter how many miles you want to convert to kilometres: ";
    cin >> miles;
    cout << endl;
    cout << "Number of kilometres in your number of miles: " << (miles * 1.609) << endl;
    return 0;
}
