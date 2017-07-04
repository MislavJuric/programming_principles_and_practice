#include "../std_lib_facilities.h"

//10. Write a function vector<string> split(const string& s) that returns a vector of whitespace-separated
// substrings from the argument s.

vector<string> split (const string& s)
{
    vector<string> toReturn;
    stringstream sstream {s};
    string word;
    while (sstream >> word)
    {
        toReturn.push_back(word);
    }
    return toReturn;
}

int main()
{
    string s = "There ain't no grave to hold my body down.";
    vector<string> result = split(s);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}
