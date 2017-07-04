#include <iostream>
#include <climits>

using namespace std;

// 11. Write a program that writes out the first so many values of the Fibonacci series, that is, the series that
// starts with 1 1 2 3 5 8 13 21 34. The next number of the series is the sum of the two previous ones.
// Find the largest Fibonacci number that fits in an int.

int Fibonnaci()
{
    int f1 = 1;
    int f2 = 1;
    int fn = 0;
    while (fn <= (INT_MAX - 100)) // or while (fn >= 0) --- maybe this is better
    {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    return f1;
}


int main()
{
    int result = Fibonnaci();
    cout << result << endl;
    return 0;
}
