#include <iostream>

using namespace std;

// 4. Write a program to play a numbers guessing game. The user thinks of a number between 1 and 100 and your program asks questions to figure out what the
// number is (e.g., “Is the number you are thinking of less than 50?”). Your program should be able to identify the number after asking no more than
// seven questions. Hint: Use the < and <= operators and the if-else construct.

// This program doesn't work right... Hmmmm...

int main()
{
    int number;
    cin >> number;
    int guess = 50;
    while (number != guess)
    {
        cout << "Is the number you are thinking of less than " << guess << "? (y/n)" << endl;
        char answer;
        cin >> answer;
        if (answer == 'y')
        {
            guess /= 2;
        }
        if (answer == 'n')
        {
            guess += (guess / 2);
        }
    }
    cout << "Your number equals: " << guess << endl;
    return 0;
}
