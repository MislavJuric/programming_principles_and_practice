#include "../Headers/std_lib_facilities.h"

using namespace std;

// 4. Consider what happens if you give strdup(), findx(), and strcmp() an argument that is not a C-style string. Try it!
// First figure out how to get a char* that doesn’t point to a zero-terminated array of characters and then use it
// (never do this in real — non-experimental — code; it can create havoc). Try it with free-store-allocated and stack-allocated
// “fake C-style strings.” If the results still look reasonable, turn off debug mode. Redesign and re-implement those three
// functions so that they take another argument giving the maximum number of elements allowed in argument strings.
// Then, test that with correct C-style strings and “bad” strings.

char* strdup(const char* arg, int maxSize)
{
    if (arg == nullptr) error("I can't deal with null pointers.");
    // count the number of chars in arg
    int argSize = 0;
    while (*(arg + argSize) != '\0')
    {
        argSize++;
    }
    argSize++; // to get 1 character for '\0'
    cout << argSize << endl;
    if (argSize > maxSize)
    {
        error("Argument is larger than is supported.");
    }
    char* newMemory = new char[argSize];
    for (int i = 0; i < argSize; i++)
    {
        *(newMemory + i) = *(arg + i);
    }
    return newMemory;
}

char* findx(const char* s, const char* x, int maxSize)
{
    if (s == nullptr) error("I can't work with null pointers.");
    if (x == nullptr) error("I can't work with null pointers.");
    // find the number of elements in x
    int xSize = 0;
    while(*(x + xSize) != '\0')
    {
        xSize++;
    }
    if (xSize > maxSize)
    {
        error("Argument 2 is larger than is supported.");
    }
    int sSize = 0;
    while(*(s + sSize) != '\0')
    {
        sSize++;
    }
    if (sSize > maxSize)
    {
        error("Argument 1 is larger than is supported.");
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

int strcmp(const char* s1, const char* s2, int maxSize)
{
    if (s1 == nullptr) error("I can't deal with null pointers.");
    if (s2 == nullptr) error ("I can't deal with null pointers.");
    int s1Size = 0;
    int s2Size = 0;
    while (*(s1 + s1Size) != '\0')
    {
        s1Size++;
    }
    if (s1Size > maxSize)
    {
        error("Argument 1 is larger than is supported.");
    }
    while (*(s2 + s2Size) != '\0')
    {
        s2Size++;
    }
    if (s2Size > maxSize)
    {
        error("Argument 2 is larger than is supported.");
    }
    int longer = 0;
    int shorter = 0;
    if (s2Size > s1Size)
    {
        longer = s2Size;
        shorter = s1Size;
    }
    else if(s1Size > s2Size)
    {
        longer = s1Size;
        shorter = s2Size;
    }
    else
    {
        longer = s1Size; // or s2Size, they are the same length
        shorter = s2Size;
    }
    for (int i = 0; i < shorter; i++)
    {
        if (*(s1 + i) > *(s2 + i))
        {
            return -1;
        }
        else if (*(s1 + i) < *(s2 + i))
        {
            return 1;
        }
    }
    if ((shorter != longer) && (shorter == s2Size))
    {
        return 1; // I consider shorter words lexicologically first
    }
    if ((shorter != longer) && (shorter == s1Size))
    {
        return -1;
    }
    if (shorter == longer)
    {
        return 0;
    }
}

int main()
{
    char* testString = new char[8]{'T', 'e', 's', 't', 'i', 'n', 'g', '\0'};
    char* testStringBad = new char[7]{'T', 'e', 's', 't', 'i', 'n'};
    char testStringStack[7] {'T', 'e', 's', 't', 'i', 'n', 'g'};
    // char* copiedString = strdup(testStringStack, 8); // this gives wierd behaviour
    char* copiedString = strdup(testStringBad, 8);
    cout << copiedString << endl;
    delete[] copiedString;
    delete[] testString;
    return 0;
}
