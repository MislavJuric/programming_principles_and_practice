#include "../Headers/std_lib_facilities.h"

// 4. Write a function, char* strdup(const char*), that copies a C-style string into memory it allocates on the free store.
// Do not use any standard library functions.

char* strdup(const char* arg)
{
    if (arg == nullptr)
    {
        error ("Your pointer doesn't point to anything");
    }
    int stringLength = 0;
    while (arg[stringLength] != '\0') // assuming that the string is ended with an '\0'
    {
        stringLength++;
    }
    stringLength++; // I need this increment for the final "element" of the string, the '\0'
    char* toReturn = new char[stringLength];
    for (int i = 0; i < stringLength; i++)
    {
        toReturn[i] = arg[i];
    }
    return toReturn;
}

int main()
{
    char* testString = new char[13]{'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o',  'r', 'l', 'd', '!', '\0'};
    char* copiedTestString = strdup(testString);
    for (int i = 0; i < 13; i++) // I hard-coded 13 just to check if my function works, this isn't good practice
    {
        cout << copiedTestString[i];
    }
    return 0;
}
