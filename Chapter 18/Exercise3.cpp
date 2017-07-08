#include <iostream>

using namespace std;

// 3. Write a function, int strcmp(const char* s1, const char* s2), that compares C-style strings. Let it return a negative number
// if s1 is lexicographically before s2, zero if s1 equals s2, and a positive number if s1 is lexicographically after s2.
// Do not use any standard library functions. Do not use subscripting; use the dereference operator * instead.

int strcmp(const char* s1, const char* s2)
{
    if (s1 == nullptr) error("I can't deal with null pointers.");
    if (s2 == nullptr) error ("I can't deal with null pointers.");
    int s1Size = 0;
    int s2Size = 0;
    while (*(s1 + s1Size) != '\0')
    {
        s1Size++;
    }
    while (*(s2 + s2Size) != '\0')
    {
        s2Size++;
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
    char* s1 = new char[5]{'T', 'e', 's', 't', '\0'};
    char* s2 = new char[3]{'a', 'd', '\0'};
    int result = strcmp(s1, s2);
    cout << result << endl;
    return 0;
}
