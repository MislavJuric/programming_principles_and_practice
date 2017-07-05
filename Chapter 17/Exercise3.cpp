#include "../Headers/std_lib_facilities.h"

// 3. Write a function, void to_lower(char* s), that replaces all uppercase characters in the C-style string s with their
// lowercase equivalents. For example, Hello, World! becomes hello, world!. Do not use any standard library functions.
// A C-style string is a zero-terminated array of characters, so if you find a char with the value 0 you are at the end.

void to_lower(char* s)
{
    if (s == nullptr)
    {
        error("Your pointer doesn't point to anything.");
    }
    int index = 0;
    char currentChar = s[index];
    constexpr int asciioffset = 32;
    while (currentChar != '\0')
    {
        currentChar = s[index];
        if ((currentChar >= 65) && (currentChar <= 90)) // 97 being the value of 'a', since all characters
                                                        // are represented as numbers
        {
            // if I modify currentChar here, I modify a local variable; I need to modify s[index]
            s[index] += asciioffset;
        }
        index++;
    }
}

int main()
{
    char* testString = new char[13]{'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o',  'r', 'l', 'd', '!', '\0'};
    to_lower(testString);
    for (int i = 0; i < 13; i++) // I hard-coded 13 just to check if my function works, this isn't good practice
    {
        cout << testString[i];
    }
    return 0;
}
