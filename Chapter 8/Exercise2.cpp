#include "../../std_lib_facilities.h"

// 2. Write a function print() that prints a vector of ints to cout.
// Give it two arguments: a string for “labeling” the output and a vector.

void print(string label, vector<int>& output)
{
    cout << label << " ";
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
}

int main()
{
    string arg1 = "Some label";
    vector<int> v {1, 2, 3, 4, 5};
    print(arg1, v);
    return 0;
}
