#include "../std_lib_facilities.h"

//11. Write a function vector<string> split(const string& s, const string& w) that returns a vector of whitespace-separated
// substrings from the argument s, where whitespace is defined as “ordinary whitespace” plus the characters in w.

vector<string> split (const string& s, const string& w)
{
    vector<string> toReturn;
    vector<char> whitespace;
    for (int i = 0; i < w.size(); i++)
    {
        whitespace.push_back(w[i]);
    }
    stringstream sstream {s};
    string word;
    while (sstream >> word)
    {
        for (int j = 0; j < word.size(); j++)
        {
            for (int i = 0; i < whitespace.size(); i++)
            {
                if (word[j] == whitespace[i])
                {
                    word[j] = ' ';
                }
            }
        }
        toReturn.push_back(word);
    }
    return toReturn;
}

int main()
{
    string s = "There ain't no grave to hold my body down.";
    string w = ".'Ty";
    vector<string> result = split(s, w);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}
