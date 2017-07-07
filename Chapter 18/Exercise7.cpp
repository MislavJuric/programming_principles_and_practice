#include "../Headers/std_lib_facilities.h"

// 7. Write versions of the cat_dot()s from the previous exercises to take C-style strings as arguments and return a
// free-store-allocated C-style string as the result. Do not use standard library functions or types in the implementation.
// Test these functions with several strings. Be sure to free (using delete) all the memory you allocated from free store
// (using new). Compare the effort involved in this exercise with the effort involved for exercises 5 and 6.

// I'll immediately implement the cat_dot() function with the separator

char* cat_dot(const char* firstString, const char* secondString, const char* separator)
{
    if ((firstString == nullptr) || (secondString == nullptr) || (separator == nullptr))
    {
        error("Ooops! One of the pointers is a null pointer.");
    }
    int firstStringLength = 0;
    while (firstString[firstStringLength] != '\0')
    {
        firstStringLength++;
    }
    int secondStringLength = 0;
    while (secondString[secondStringLength] != '\0')
    {
        secondStringLength++;
    }
    int separatorLength = 0;
    while (separator[separatorLength] != '\0')
    {
        separatorLength++;
    }
    int allocationLength = firstStringLength + separatorLength + secondStringLength + 1; // + 1 for '\0'
    char* toReturn = new char[allocationLength];
    for (int i = 0; i < firstStringLength; i++)
    {
        toReturn[i] = firstString[i];
    }
    for (int i = firstStringLength; i < (firstStringLength + separatorLength); i++)
    {
        toReturn[i] = separator[i - firstStringLength];
    }
    for (int i = (firstStringLength + separatorLength); i < (firstStringLength + separatorLength + secondStringLength); i++)
    {
        toReturn[i] = secondString[i - (firstStringLength + separatorLength)];
    }
    toReturn[firstStringLength + separatorLength + secondStringLength] = '\0';
    return toReturn;
}

int main()
{
    char* result = cat_dot("Niels", "Bohr", "---");
    int index = 0;
    while (result[index] != '\0')
    {
        cout << result[index];
        index++;
    }
    delete[] result;
    return 0;
}
