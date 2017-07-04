#include "../std_lib_facilities.h"

// 1. Write a program that produces the sum of all the numbers in a file of whitespace-separated integers.

int main()
{
    string filename;
    cout << "Enter the full path for filename from which you want to read the numbers (with the file extension): " << endl;
    cin >> filename;
    ifstream ist {filename};
    int sum = 0;
    if (!ist)
    {
        error ("Ooops! Couldn't open the file!");
    }
    else
    {
        for (int number; ist >> number;)
        {
            sum += number;
        }
    }
    cout << sum << endl;
}
