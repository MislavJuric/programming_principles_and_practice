#include "../../std_lib_facilities.h"

// 6. Write versions of the functions from exercise 5, but with a vector<string>.

vector<string> new_reverse(const vector<string>& argument)
{
    vector<string> toReturn;
    for (int i = argument.size() - 1; i >= 0; i--)
    {
        toReturn.push_back(argument[i]);
    }
    return toReturn;
}

void no_new_reverse(vector<string>& argument)
{
    int i = 0;
    int j = argument.size() - 1;
    while ((i < (argument.size() / 2)) || (j > (argument.size() / 2)))
    {
        string temp = argument[i];
        argument[i] = argument[j];
        argument[j] = temp;
        i++;
        j--;
    }
}

void print(string label, const vector<string>& output)
{
    cout << label << endl;
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
}

int main()
{
    vector<string> toReverse {"this", "Should", "be", "printed", "in", "reverse"};
    //vector<string> newVector = new_reverse(toReverse);
    no_new_reverse(toReverse);
    print ("Results: ", toReverse);
    return 0;
}
