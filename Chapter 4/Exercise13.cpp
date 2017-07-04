#include <iostream>
#include <vector>

using namespace std;

// 13. Create a program to find all the prime numbers between 1 and 100. There is a classic method for doing this,
// called the “Sieve of Eratosthenes.” If you don’t know that method, get on the web and look it up.
// Write your program using this method.

int main()
{
    vector<bool> numbers(101); // svi su po defaultu false
    /* for (int i = 2; i <= 100; i++)
    {
        cout << i << " is true." << endl;
        if (numbers[i] == false)
        {
            for (int j = (i + i); j <= 100; j += i)
            {
                cout << j << " is true." << endl;
                numbers[i] = true;
            }
        }
    } */
    for (int i = 2; i <= 100; i++)
    {
        if (numbers[i] == false)
        {
            for (int j = (2 * i); j <= 100; j += i)
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
