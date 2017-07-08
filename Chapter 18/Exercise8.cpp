#include "../Headers/std_lib_facilities.h"

// 8. Rewrite all the functions in §18.7 to use the approach of making a backward copy of the string and then comparing;
// for example, take 'home', generate 'emoh', and compare those two strings to see that they are different,
// so home isn’t a palindrome.

bool palindrome(char* arg)
{
    int argSize = 0;
    while (arg[argSize] != '\0')
    {
        argSize++;
    }
    char* backwards = new char[argSize + 1]; // + 1 for '\0'
    int argIndex = 1; // this is 1 because I want to start with the last letter, not with '\0'
    // maybe I could have done this smoother...
    for (int i = argSize; i > 0; i--)
    {
        backwards[argSize - i] = arg[argSize - argIndex];
        cout << "Setting backwards[" << argSize - i  << "] to " << arg[argSize - argIndex] << endl;
        argIndex++;
    }
    backwards[argSize] = '\0';
    // palindrome check
    bool palindrome = true;
    for (int i = 0; i <= argSize; i++)
    {
        if (arg[i] != backwards[i])
        {
            cout << "arg[i] is " << arg[i] << endl;
            cout << "backwards[i] is " << backwards[i] << endl;
            palindrome = false;
            break;
        }
    }
    delete[] backwards;
    return palindrome;
}

int main()
{
    char* word = new char[5]{'H', 'o', 'o', 'H', '\0'};
    cout << palindrome(word) << endl;
    delete[] word;
    return 0;
}
