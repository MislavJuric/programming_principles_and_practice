#include <iostream>

using namespace std;

// 9. Try to calculate the number of rice grains that the inventor asked for in exercise 8 above. You’ll find that the number
// is so large that it won’t fit in an int or a double. Observe what happens when the number gets too large to represent
// exactly as an int and as a double. What is the largest number of squares for which you can calculate the exact number of
// grains (using an int)? What is the largest number of squares for which you can calculate the approximate number of grains
// (using a double)?

int main()
{
    double sum = 1;
    for (int i = 1; i <= 64; i++)
    {
        int current_grains = 1;
        for (int j = 0; j < i; j++)
        {
            current_grains *= 2;
        }
        sum += current_grains;
        // cout << current_grains << endl;
    }
    cout << "Sum is: " << sum << endl;
    return 0;
}
