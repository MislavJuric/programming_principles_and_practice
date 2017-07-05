#include "../Headers/std_lib_facilities.h"

// 5. Write a function, char* findx(const char* s, const char* x), that finds the first occurrence of the C-style string x in s.

char* findx (const char* s, const char* x)
{
    if (s == nullptr)
    {
        error("Your s pointer is empty.");
    }
    if (x == nullptr)
    {
        error("Your x pointer is empty.");
    }
    // first I'll count how many elements x has
    int xElementCount = 0;
    while (x[xElementCount] != '\0')
    {
        xElementCount++;
    }
    int xIndex = 0;
    int sIndex = 0;
    while (s[sIndex] != '\0')
    {
        if (s[sIndex] == x[xIndex]) // we have a match
        {
            xIndex++;
        }
        else if (xIndex == xElementCount)
        {
            return const_cast<char*>(&s[sIndex - xIndex]); // return a pointer to the first letter of the string searched for
            // I have to be really careful with this one! const_cast should be avoided (as Stroustrup says) and used
            // when all else fails
        }
        else if (s[sIndex] != x[xIndex])
        {
            xIndex = 0;
        }
        sIndex++;
    }
    cout << "We couldn't find the string you were looking for." << endl;
    return nullptr; // if nothing is found
}

int main()
{
    char* testString = new char[13]{'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o',  'r', 'l', 'd', '!', '\0'};
    char* stringToLookFor = new char[4]{'l', 'l', 'o', '\0'};
    char* result = findx(testString, stringToLookFor);
    cout << *result << endl;
    return 0;
}
