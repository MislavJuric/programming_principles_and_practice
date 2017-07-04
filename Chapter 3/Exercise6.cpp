#include <iostream>

using namespace std;

// 6 Write a program that prompts the user to enter three integer values, and then outputs the values in numerical sequence
// separated by commas. So, if the user enters the values 10 4 6, the output should be 4, 6, 10. If two values are the same,
// they should just be ordered together. So, the input 4 5 4 should give 4, 4, 5.

// a lot of if statements...

int main()
{
    int a, b, c;
    int greatest, middle, smallest;
    cin >> a >> b >> c;
    if (a == b)
    {
        if (a < c)
        {
            smallest = a;
            middle = b;
        }
        else
        {
            middle = a;
            greatest = b;
        }
    }
    if (a == c)
    {
        if (a < b)
        {
            smallest = a;
            middle = c;
        }
        else
        {
            middle = a;
            greatest = c;
        }
    }
    if (b == c)
    {
        if (b < a)
        {
            smallest = b;
            middle = c;
        }
        else
        {
            middle = c;
            greatest = b;
        }
    }
    if (a > b)
    {
        if (a > c)
        {
            greatest = a;
            if (b > c)
            {
                middle = b;
                smallest = c;
            }
            if (c > b)
            {
                middle = c;
                smallest = b;
            }
        }

    }
    if (b > a)
    {
        if (b > c)
        {
            greatest = b;
            if (a > c)
            {
                middle = a;
                smallest = c;
            }
            if (c > a)
            {
                middle = c;
                smallest = a;
            }
        }
    }
    if (c > a)
    {
        if (c > b)
        {
            greatest = c;
            if (a > b)
            {
                middle = a;
                smallest = b;
            }
            if (b > a)
            {
                middle = b;
                smallest = a;
            }
        }
    }
    cout << smallest << " " << middle << " " << greatest << endl;
    return 0;
}
