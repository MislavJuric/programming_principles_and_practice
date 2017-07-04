#include "../std_lib_facilities.h"

// 7. Modify the program from the previous exercise so that it replaces don't with do not, can't with cannot, etc.;
// leaves hyphens within words intact (so that we get “ do not use the as-if rule ”); and converts all characters to lower case.

string whitespaceChange(string input)
{
    stringstream sstream {input};
    string toReturn;
    string word;
    while (sstream >> word)
    {
        cout << word << endl;
        int strLen = word.length();
        bool doubleQuotes = false;
        if (word == "don't") // moglo se sve u vektor, pa iterirati kroz njega
        {
            toReturn += "do not ";
            continue;
        }
        if (word == "can't")
        {
            toReturn += "cannot ";
            continue;
        }
        if (word == "wouldn't")
        {
            toReturn += "would not ";
            continue;
        }
        if (word == "hasn't")
        {
            toReturn += "has not ";
            continue;
        }
        for (int i = 0; i < strLen; i++)
        {
            cout << "Executed" << endl;
            if ((word[i] == ',') && (doubleQuotes == false))
            {
                toReturn += ' ';
                continue;
            }
            if ((word[i] == ';') && (doubleQuotes == false))
            {
                toReturn += ' ';
                continue;
            }
            if ((word[i] == '?') && (doubleQuotes == false))
            {
                toReturn += ' ';
                continue;
            }
            if ((word[i] == '.') && (doubleQuotes == false))
            {
                toReturn += ' ';
                continue;
            }
            if ((word[i] == '\'') && (doubleQuotes == false))
            {
                toReturn += ' ';
                continue;
            }
            if (word[i] == '\"')
            {
                doubleQuotes = true;
                toReturn += ' ';
                continue;
            }
            if ((word[i] == '\"') && (doubleQuotes == true))
            {
                doubleQuotes = false;
                toReturn += ' ';
                continue;
            }
            toReturn += tolower(word[i]);
        }
        toReturn += ' '; // because word is not extracted with the space
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
