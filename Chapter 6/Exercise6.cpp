#include <iostream>
#include <string>

using namespace std;

// 6. Write a program that checks if a sentence is correct according to the “English” grammar in §6.4.1.
// Assume that every sentence is terminated by a full stop (.) surrounded by whitespace. For example, birds fly but
// the fish swim . is a sentence, but birds fly but the fish swim (terminating dot missing) and birds fly but the fish swim.
// (no space before dot) are not. For each sentence entered, the program should simply respond “OK” or “not OK.”
// Hint: Don’t bother with tokens; just read into a string using >>.

// Hmmm... I have a problem with this... I don't know how I would implement this grammar without tokenizing.
// Tokenizing would make it a lot easier.

/*
    Original grammar:


    Sentence:
              Noun Verb                                            // e.g., C++ rules
              Sentence Conjunction Sentence      // e.g., Birds fly but fish swim
    Conjunction:
              'and'
              'or'
              'but'
    Noun:
              'birds'
              'fish'
              'C++'
    Verb:
              'rules'
              'fly'
              'swim'
*/

int main()
{

    return 0;
}
