#include "../Headers/std_lib_facilities.h"

// 7. Find the lexicographical last string in an unsorted vector<string>.

string last(vector<string>& arg)
{
    if (arg.size() == 0) return "";
    string toReturn = arg[0];
    for (int i = 1; i < arg.size(); i++)
    {
        if (arg[i] > toReturn)
        {
            toReturn = arg[i];
        }
    }
    return toReturn;
}

int main()
{
    vector<string> arg{"First", "Zoloft", "Second"};
    string f = last(arg);
    cout << f << endl;
    return 0;
}
