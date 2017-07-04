#include <iostream>

using namespace std;

// 15. Write a program that takes an input value n and then finds the first n primes.

int main()
{
    int n;
    cin >> n;
    int num_of_primes = 0;
    int i = 2;
    while (num_of_primes != n)
    {
        bool prime = true;
        for (int j = 2; j <= i; j++)
        {
            if (((i % j) == 0) && (i != j))
            {
                prime = false;
            }
        }
        if (prime == true)
        {
            cout << i << endl;
            num_of_primes++;
        }
        i++;
    }
    return 0;
}
