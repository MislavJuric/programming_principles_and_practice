#include "../std_lib_facilities.h"

/*

    4. Write a program called multi_input.cpp that prompts the user to enter several integers in any combination of octal, decimal, or hexadecimal, using the 0 and 0x base suffixes; interprets the numbers correctly; and converts them to decimal form. Then your program should output the values in properly spaced columns like this:


     0x43    hexadecimal   converts to    67  decimal
     0123    octal                 converts to    83  decimal
         65    decimal            converts to    65  decimal

*/

int convertString(string input)
{
    int base = 10;
    int startPos = 0;
    if ((input[0] == '0') && (input[1] != 'x'))
    {
        base = 8;
        startPos = 1;
    }
    if ((input[0] == '0') && (input[1] == 'x'))
    {
        base = 16;
        startPos = 2;
    }
    vector<int> digits;
    for (int i = startPos; i < input.length(); i++)
    {
        if ((input[i] == 'A') || (input[i] > 'A'))
        {
            digits.push_back((int) (input[i] - 55));
            continue;
        }
        digits.push_back((int) (input[i] - '0'));
    }
    int result = 0;
    int exponent = 0;
    for (int i = (digits.size() - 1); i >= 0; i--)
    {
        result += pow(base, exponent) * digits[i];
        exponent++;
    }
    return result;
}

string base(string input)
{
    if ((input[0] == '0') && (input[1] != 'x'))
    {
        return "octal";
    }
    if ((input[0] == '0') && (input[1] == 'x'))
    {
        return "hexadecimal";
    }
    return "decimal";
}

int main()
{
    string input;
    cin >> input;
    cout << input << " " << base(input) << '\t' << " converts to " << convertString(input) << " decimal" << endl;
}
