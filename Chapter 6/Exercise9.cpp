#include <iostream>
#include <vector>

using namespace std;

// 9. Write a program that reads digits and composes them into integers. For example, 123 is read as the characters 1, 2, and 3.
// The program should output 123 is 1 hundred and 2 tens and 3 ones. The number should be output as an int value.
// Handle numbers with one, two, three, or four digits. Hint: To get the integer value 5 from the character '5' subtract '0',
// that is, '5'–'0'==5.

int main()
{
    /*
    char digit;
    int number = 0;
    int count = 1;
    digit = cin.get();
    number += digit - '0';
    while (digit != 10)
    {
        digit = cin.get();
        count++;
        digit = digit - '0';
        number += (number * 10) + digit;
        cout << number << endl;
    }
    // cout << number << endl;
    */
    // I have a bug in the commented code; ignore it

    vector<int> digits;
    char digit;
    digit = cin.get();
    int intDigit = (int) (digit - '0');
    digits.push_back(intDigit);
    while (digit != 10)
    {
        digit = cin.get();
        intDigit = (int) (digit - '0');
        digits.push_back(intDigit);
    }
    switch (digits.size() - 1)
    {
        case 1:
            cout << "There are " << digits[0] << " ones.";
            break;
        case 2:
            cout << "There are " << digits[0] << " tens and " << digits[1] << " ones.";
            break;
        case 3:
            cout << "There are " << digits[0] << " hundreds, " << digits[1] << " tens, and " << digits[2] << " ones.";
            break;
        case 4:
            cout << "There are " << digits[0] << " thousands, " << digits[1] << " hundreds, " << digits[2] << " tens, and " << digits[3] << " ones.";
            break;
        default:
            cout << "I can't handle number whose digits are not between 1 and 4." << endl;
    }
    return 0;
}
