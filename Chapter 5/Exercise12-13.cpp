#include "std_lib_facilities.h"

using namespace std;

// 12. Implement a little guessing game called (for some obscure reason) “Bulls and Cows.”
// The program has a vector of four different integers in the range 0 to 9 (e.g., 1234 but not 1122) and it
// is the user’s task to discover those numbers by repeated guesses. Say the number to be guessed is 1234 and the user
// guesses 1359; the response should be “1 bull and 1 cow” because the user got one digit (1) right and in the right
// position (a bull) and one digit (3) right but in the wrong position (a cow). The guessing continues until the user
// gets four bulls, that is, has the four digits correct and in the correct order.

// maybe a more elegant solution is possible

// 13. The program is a bit tedious because the answer is hard-coded into the program.
// Make a version where the user can play repeatedly (without stopping and restarting the program) and each game
// has a new set of four digits. You can get four random digits by calling the random number generator randint(10)
// from std_lib_facilities.h four times. You will note that if you run that program repeatedly, it will pick the same
// sequence of four digits each time you start the program. To avoid that, ask the user to enter a number (any number)
// and call srand(n) where n is the number the user entered before calling randint(10). Such an n is called a seed,
// and different seeds give different sequences of random numbers.

// a repeated playing can be done using a while loop and an input (for example, after the end of a game session,
// you can ask the user "Continue playing? (y/n)"), but I didn't put this because I want a new random seed to be
// entered every time

int main()
{
    int seed;
    cout << "Enter a random seed: ";
    cin >> seed;
    cout << endl;
    srand(seed);
    vector<int> number;
    number.push_back(randint(10));
    number.push_back(randint(10));
    number.push_back(randint(10));
    number.push_back(randint(10));
    for (int i = 0; i < number.size(); i++) // test
    {
        cout << number[i] << " ";
    }
    cout << endl;
    int a, b, c, d;
    bool done = false;
    int bull = 0;
    int cow = 0;
    while (done == false)
    {
        cin >> a >> b >> c >> d;
        if (a == number[0])
        {
            bull++;
        }
        if (b == number[1])
        {
            bull++;
        }
        if (c == number[2])
        {
            bull++;
        }
        if (d == number[3])
        {
            bull++;
        }
        for (int i = 0; i < number.size(); i++)
        {
            if ((a == number[i]) && (i != 0))
            {
                cow++;
            }
            if ((b == number[i]) && (i != 1))
            {
                cow++;
            }
            if ((c == number[i]) && (i != 2))
            {
                cow++;
            }
            if ((d == number[i]) && (i != 3))
            {
                cow++;
            }
        }
        cout << bull << " bulls and " << cow << " cows" << endl;
        if (bull == 4)
        {
            done = true;
            cout << "You won the game!" << endl;
        }
        bull = 0;
        cow = 0;
    }
    return 0;
}
