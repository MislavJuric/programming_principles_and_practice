#include "../Headers/std_lib_facilities.h"

// 1. Write a function, char* strdup(const char*), that copies a C-style string into memory it allocates on the free store.
// Do not use any standard library functions. Do not use subscripting; use the dereference operator * instead.

char* strdup(const char* arg)
{
    if (arg == nullptr) error("I can't deal with null pointers.");
    // count the number of chars in arg
    int argSize = 0;
    while (*(arg + argSize) != '\0')
    {
        argSize++;
    }
    argSize++; // to get 1 character for '\0'
    char* newMemory = new char[argSize];
    for (int i = 0; i < argSize; i++)
    {
        *(newMemory + i) = *(arg + i);
    }
    return newMemory;
}

int main()
{
    char* testString = new char[8]{'T', 'e', 's', 't', 'i', 'n', 'g', '\0'};
    char* copiedString = strdup(testString);
    cout << copiedString << endl;
    delete[] copiedString;
    delete[] testString;
    return 0;
}
