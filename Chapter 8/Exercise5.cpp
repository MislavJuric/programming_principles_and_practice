#include "../../std_lib_facilities.h"

// 5. Write two functions that reverse the order of elements in a vector<int>. For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1.
// The first reverse function should produce a new vector with the reversed sequence, leaving its original vector unchanged.
// The other reverse function should reverse the elements of its vector without using any other vectors (hint: swap).

vector<int> new_reverse(const vector<int>& argument)
{
    vector<int> toReturn;
    for (int i = argument.size() - 1; i >= 0; i--)
    {
        toReturn.push_back(argument[i]);
    }
    return toReturn;
}

void no_new_reverse(vector<int>& argument)
{
    /*
    int i = 0;
    int j = argument.size() - 1;
    while ((i < (argument.size() / 2)) || (j > (argument.size() / 2)))
    {
        int temp = argument[i];
        argument[i] = argument[j];
        argument[j] = temp;
        i++;
        j--;
    }
    */
    // this code above also does the job, but the line below is more elegant
    reverse(argument.begin(), argument.end());
}

void print(string label, const vector<int>& output)
{
    cout << label << endl;
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
}

int main()
{
    vector<int> toReverse {1,2,3,4,5};
    //vector<int> newVector = new_reverse(toReverse);
    no_new_reverse(toReverse);
    print ("Results: ", toReverse);
    return 0;
}
