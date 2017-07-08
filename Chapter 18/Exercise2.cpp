#include "../Headers/std_lib_facilities.h"

// 2. Write a function, char* findx(const char* s, const char* x), that finds the first occurrence of the C-style string x in s.
// Do not use any standard library functions. Do not use subscripting; use the dereference operator * instead.

char* findx(const char* s, const char* x)
{
    if (s == nullptr) error("I can't work with null pointers.");
    if (x == nullptr) error("I can't work with null pointers.");
    // find the number of elements in x
    int xSize = 0;
    while(*(x + xSize) != '\0')
    {
        xSize++;
    }
    int sSize = 0;
    while(*(s + sSize) != '\0')
    {
        sSize++;
    }
    int matchingCharCount = 0;
    for (int i = 0; i <= sSize; i++)
    {
        if (matchingCharCount == xSize)
        {
            return const_cast<char*>(s + i - xSize);
        }
        if (*(x + matchingCharCount) == *(s + i))
        {
            matchingCharCount++;
        }
        else
        {
            matchingCharCount = 0;
        }
    }
    // if the string isn't found
    return nullptr; // or throw an exception
}

int main()
{
    char* testString = new char[8]{'T', 'e', 's', 't', 'i', 'n', 'g', '\0'};
    char* x = new char[4]{'i', 'n', 'g', '\0'};
    char* firstOccurence = findx(testString, x);
    cout << firstOccurence << endl;
    delete firstOccurence; 
    delete[] x;
    delete[] testString;
    return 0;
}
