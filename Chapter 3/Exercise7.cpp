#include <iostream>

using namespace std;

// 7 Do exercise 6, but with three string values. So, if the user enters the values Steinbeck, Hemingway, Fitzgerald,
// the output should be Fitzgerald, Hemingway, Steinbeck.

// a lot of if statements...

int main()
{
    string a, b, c;
    string greatest, middle, smallest;
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
