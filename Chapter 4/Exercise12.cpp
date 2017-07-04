#include "../Headers/std_lib_facilities.h"

// 12. Modify the program described in the previous exercise (Exercise 11) to take an input value max and then find
// all prime numbers from 1 to max.

int main()
{
    vector<int> primes;
    int max;
    cout << "To what number do you want to calculate primes?" << endl;
    cin >> max;
    bool prime = true;
    for (int i = 2; i <= max; i++)
    {
        for (int j = 2; j <= i; j++)
        {
            if (i == j)
            {
                break;
            }
            if ((i % j) == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime == true)
        {
            primes.push_back(i);
        }
        prime = true;
    }
    for (int i = 0; i < primes.size(); i++)
    {
        cout << primes[i] << endl;
    }
    return 0;
}
