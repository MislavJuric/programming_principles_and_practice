#include <iostream>

using namespace std;

/*
10. A permutation is an ordered subset of a set. For example, say you wanted to pick a combination to a vault. There are 60
possible numbers, and you need three different numbers for the combination. There are P(60,3) permutations for the
combination, where P is defined by the formula

<permutation formula here>

where ! is used as a suffix factorial operator. For example, 4! is 4*3*2*1.

Combinations are similar to permutations, except that the order of the objects doesn’t matter. For example, if you were
making a “banana split” sundae and wished to use three different flavors of ice cream out of five that you had,
you wouldn’t care if you used a scoop of vanilla at the beginning or the end; you would still have used vanilla.
The formula for combinations is

<combination formula here>

Design a program that asks users for two numbers, asks them whether they want to calculate permutations or combinations,
and prints out the result. This will have several parts. Do an analysis of the above requirements.
Write exactly what the program will have to do. Then, go into the design phase. Write pseudo code for the program,
and break it into sub-components. This program should have error checking. Make sure that all erroneous
inputs will generate good error messages.
*/

class Bad_arguments {};

int factorial(int number)
{
    int result = 1;
    for (int i = 1; i <= number; i++)
    {
        result *= i;
    }
    return result;
}

int permutation(int a, int b)
{
    if (a < b)
    {
        throw Bad_arguments{};
    }
    int result;
    result = factorial(a) / factorial(a - b);
    return result;
}

int combination (int a, int b)
{
    int result;
    result = permutation(a, b) / factorial(b);
    return result;
}

int main()
{
    try
    {
        cout << "Enter two numbers for which you want the result: ";
        int a, b;
        cin >> a >> b;
        char choice;
        cout << "What do you want? (P for permutation, C for combination): ";
        cin >> choice;
        int result;
        if ((choice == 'P') || (choice == 'p'))
        {
            result = permutation(a, b);
        }
        if ((choice == 'C') || (choice == 'c'))
        {
            result = combination(a, b);
        }
        cout << "Your result is: " << result << endl;
    }
    catch (Bad_arguments)
    {
        cout << "Your first number must be larger than the second number, otherwise permutation calculation doesn't make sense." << endl;
    }
    return 0;
}
