#include "../Headers/std_lib_facilities.h"

// 10. Write a program that plays the game “Rock, Paper, Scissors.” If you are not familiar with the game do some research
// (e.g., on the web using Google). Research is a common task for programmers. Use a switch-statement to solve this exercise.
// Also, the machine should give random answers (i.e., select the next rock, paper, or scissors randomly).
// Real randomness is too hard to provide just now, so just build a vector with a sequence of values to be used as
// “the next value.” If you build the vector into the program, it will always play the same game, so maybe you should
// let the user enter some values. Try variations to make it less easy for the user to guess which move the machine will make next.

int main()
{
    srand(time(0));
    vector<string> possibleAnswers{"Rock", "Paper", "Scissors"};
    char input;
    cout << "In what way do you curl your palm? (r for Rock/p for Paper/s for Scissors)" << endl;
    cin >> input;
    if ((input != 'r') && (input != 'p') && (input != 's'))
    {
        error("This program can't recognize this input.");
    }
    int randomNumber = rand() % 3; // gives me numbers 0, 1 and 2
    string computerAnswer = possibleAnswers[randomNumber];
    // a while loop could keep this going...
    switch(input)
    {
        case 'r':
            if (computerAnswer == "Rock")
            {
                cout << "Computer choose rock. It's a tie." << endl;
            }
            else if (computerAnswer == "Paper")
            {
                cout << "Computer choose paper. You lose." << endl;
            }
            else
            {
                cout << "Computer choose scissors. You won." << endl;
            }
        break;
        case 'p':
            if (computerAnswer == "Rock")
            {
                cout << "Computer choose rock. You win." << endl;
            }
            else if (computerAnswer == "Paper")
            {
                cout << "Computer choose paper. It's a tie." << endl;
            }
            else
            {
                cout << "Computer choose scissors. You lose." << endl;
            }
        break;
        case 's':
            if (computerAnswer == "Rock")
            {
                cout << "Computer choose rock. You lose." << endl;
            }
            else if (computerAnswer == "Paper")
            {
                cout << "Computer choose paper. You win." << endl;
            }
            else
            {
                cout << "Computer choose scissors. It's a tie." << endl;
            }
        break;
    }
}
