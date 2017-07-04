#include "../../std_lib_facilities.h"

// 13. Write a function that takes a vector<string> argument and returns a vector<int> containing the number of characters in
// each string. Also find the longest and the shortest string and the lexicographically first and last string.
// How many separate functions would you use for these tasks? Why?

vector<int> countChars(const vector<string>& argument)
{
    vector<int> toReturn;
    for (int i = 0; i < argument.size(); i++)
    {
        int length = argument[i].size();
        toReturn.push_back(length);
    }
    return toReturn;
}

string longest(const vector<string>& argument)
{
    vector<int> lengths;
    for (int i = 0; i < argument.size(); i++)
    {
        int length = argument[i].size();
        lengths.push_back(length);
    }
    int max = 0;
    int max_index = 0;
    for (int i = 0; i < lengths.size(); i++)
    {
        if (lengths[i] > max)
        {
            max = lengths[i];
            max_index = i;
        }
    }
    return argument[max_index];
}

string shortest(const vector<string>& argument)
{
    vector<int> lengths;
    for (int i = 0; i < argument.size(); i++)
    {
        int length = argument[i].size();
        lengths.push_back(length);
    }
    int min = INT_MAX;
    int min_index = 0;
    for (int i = 0; i < lengths.size(); i++)
    {
        if (lengths[i] < min)
        {
            min = lengths[i];
            min_index = i;
        }
    }
    return argument[min_index];
}

// In retrospect, lfirst and llast don't really work so well - what if you have two words that start with the same letter,
// say letter "a"? Step through the code and see for yourself.

string lfirst (const vector<string>& argument)
{
    string first = argument[0]; // some error checking might go here; to avoid out-of-range indexes
    for (int i = 1; i < argument.size(); i++)
    {
        if (first < argument[i])
        {
            first = argument[i];
        }
    }
    return first;
}

string llast(const vector<string>& argument)
{
    string last = argument[0]; // some error checking might go here; to avoid out-of-range indexes
    for (int i = 1; i < argument.size(); i++)
    {
        if (last > argument[i])
        {
            last = argument[i];
        }
    }
    return last;
}

int main()
{
    vector<string> argument {"Mislav", "baka", "dido", "Filip"};
    vector<int> lengths = countChars(argument);
    for (int i = 0; i < lengths.size(); i++)
    {
        cout << lengths[i] << endl;
    }
    string longe = longest(argument);
    string shorte = shortest(argument);
    string lex_first = lfirst(argument);
    string lex_last = llast(argument);
    cout << longe << " " << shorte << " " << lex_first << " " << lex_last << endl;
}
