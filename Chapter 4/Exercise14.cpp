#include <iostream>
#include <vector>

using namespace std;

// 14. Modify the program described in the previous exercise to take an input value max and then find
// all prime numbers from 1 to max.

int main()
{
    int max_number;
    cin >> max_number;
    vector<bool> numbers(max_number); // svi su po defaultu false
    for (int i = 2; i <= max_number; i++)
    {
        if (numbers[i] == false)
        {
            for (int j = (2 * i); j <= max_number; j += i)
            {
                numbers[j] = true; // paziti na indekse (i i j)
            }
        }
    }
    for (int i = 1; i < numbers.size(); i++)
    {
        if (numbers[i] == false)
        {
            cout << i << endl;
        }
    }
    return 0;
}
