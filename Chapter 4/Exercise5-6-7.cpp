// Stroustrup defined his own header, which is called "std_lib_facilities.h", where libraries like iostream and vector are included
// somewhere in my code I include the needed libraries myself and somewhere I use "std_lib_facilities.h"

#include "../Headers/std_lib_facilities.h"

using namespace std;

// 5. Write a program that performs as a very simple calculator. Your calculator should be able to handle the four basic math operations — add, subtract,
// multiply, and divide — on two input values. Your program should prompt the user to enter three arguments: two double values and a character to represent
// an operation. If the entry arguments are 35.6, 24.1, and '+', the program output should be The sum of 35.6 and 24.1 is 59.7.

// 6. Make a vector holding the ten string values 'zero', 'one', . . . 'nine'. Use that in a program that converts a digit to its corresponding spelled-out
// value; e.g., the input 7 gives the output seven. Have the same program, using the same input loop, convert spelled-out numbers into their digit form;
// e.g., the input seven gives the output 7.

// 7. Modify the “mini calculator” from exercise 5 to accept (just) single-digit numbers written as either digits or spelled out.

int main()
{
    /*
    cout << "Please enter the number you want to convert to a corresponding string: ";
    int input = 0; // it's always a good idea to initailize variables
    while (cin >> input)
    {
        cout << numberStrings[input] << endl; // input is the index because the number strings match on index input (any number from 1 to 10)
        // WARNING: The code above ("numberStrings[input]") is prone to segfaults, but it is assumed the user will enter the values between 0 and 10
        cout << endl;
        cout << "Please enter a string you want to convert to a number: ";
        string toConvertToNumber;
        int number = 0;
        cin >> toConvertToNumber;
        for (int i = 0; i < numberStrings.size(); i++)
        {
            if (numberStrings[i] == toConvertToNumber)
            {
                number = i;
                break;
            }
        }
        cout << "The number you want is: " << number << endl;
        cout << endl;
        cout << "Please enter the number you want to convert to a corresponding string: ";
    }
    */

    // I went right for Exercise 7

    vector<string> numberStrings{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    cout << "Will you input the numbers as strings or as numbers (strings/numbers)?" << endl;
    string answer;
    cin >> answer;
    while ((answer != "strings") && (answer != "numbers"))
    {
        cout << "I don't recognize your response. Please type it in again." << endl;
        cin >> answer;
    }
    int firstNumber = 0;
    int secondNumber = 0;
    if (answer == "strings")
    {
        string number1;
        string number2;
        cout << "Type in the first number: ";
        cin >> number1;
        cout << endl;
        bool numberValid = false;
        for (int i = 0; i < numberStrings.size(); i++)
        {
            if (number1 == numberStrings[i])
            {
                firstNumber = i;
                numberValid = true;
                break;
            }
        }
        if (numberValid == false)
        {
            error("Number string not supported within this program.");
        }
        cout << "Type in the second number: ";
        cin >> number2;
        cout << endl;
        numberValid = false;
        for (int i = 0; i < numberStrings.size(); i++)
        {
            if (number2 == numberStrings[i])
            {
                secondNumber = i;
                numberValid = true;
                break;
            }
        }
        if (numberValid == false)
        {
            error("Number string not supported within this program.");
        }
    }
    else if (answer == "numbers")
    {
        cout << "Please enter the two numbers you wish to operate on: ";
        cin >> firstNumber >> secondNumber;
        cout << endl;
        if (((firstNumber < 0) || (firstNumber > 10)) || ((secondNumber < 0) || (secondNumber > 10)))
        {
            error("The numbers in these ranges are not supported in this program.");
        }
    }
    cout << "Please input the operation which you want to do (+,-,*,/): ";
    char operation;
    cin >> operation;
    if ((operation != '+') && (operation != '-') && (operation != '*') && (operation != '/'))
    {
        error("This operation is not supported in this program.");
    }
    else
    {
        if (operation == '+')
        {
            cout << "The result is: " << firstNumber + secondNumber << endl;
        }
        else if (operation == '-')
        {
            cout << "The result is: " << firstNumber - secondNumber << endl;
        }
        else if (operation == '*')
        {
            cout << "The result is: " << firstNumber * secondNumber << endl;
        }
        else if (operation == '/')
        {
            cout << "The result is: " << firstNumber / secondNumber << endl;
        }
    }
    return 0;
}
