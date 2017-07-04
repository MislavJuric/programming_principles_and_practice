#include "../std_lib_facilities.h"

// 6. Write a program that replaces punctuation with whitespace. Consider . (dot), ; (semicolon), , (comma), ? (question mark),
// - (dash), ' (single quote) punctuation characters. Don’t modify characters within a pair of double quotes (').
// For example, “- don't use the as-if rule.” becomes “ don t use the as if rule ”.

string whitespaceChange(string input)
{
    int strLen = input.length();
    string toReturn;
    bool doubleQuotes = false;
    for (int i = 0; i < strLen; i++)
    {
        if ((input[i] == ',') && (doubleQuotes == false))
        {
            toReturn += ' ';
            continue;
        }
        if ((input[i] == ';') && (doubleQuotes == false))
        {
            toReturn += ' ';
            continue;
        }
        if ((input[i] == '?') && (doubleQuotes == false))
        {
            toReturn += ' ';
            continue;
        }
        if ((input[i] == '.') && (doubleQuotes == false))
        {
            toReturn += ' ';
            continue;
        }
        if ((input[i] == '\'') && (doubleQuotes == false))
        {
            toReturn += ' ';
            continue;
        }
        if (input[i] == '\"')
        {
            doubleQuotes = true;
            toReturn += ' ';
            continue;
        }
        if ((input[i] == '\"') && (doubleQuotes == true))
        {
            doubleQuotes = false;
            toReturn += ' ';
            continue;
        }
        toReturn += input[i];
    }
    return toReturn;
}

int main()
{
    string input;
    getline(cin, input);
    string newString = whitespaceChange(input);
    cout << newString << endl;
    return 0;
}
