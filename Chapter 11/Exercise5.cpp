#include "../std_lib_faclities.h"

// 5. Write a program that reads strings and for each string outputs the character classification of each character,
// as defined by the character classification functions presented in §11.6. Note that a character can have several
// classifications (e.g., x is both a letter and an alphanumeric).

void characterClassification(string input)
{
    int strLen = strlen(input);
    for (int i = 0; i < strLen; i++)
    {
        // isalnum() checks would go here...
    }
}

int main()
{
    string input;
    characterClassification(input);
    return 0;
}
