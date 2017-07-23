#include "../Headers/std_lib_facilities.h"

// 11. Given a list<int> as a (by-reference) parameter, make a vector<double> and copy the elements of the list into it.
// Verify that the copy was complete and correct. Then print the elements sorted in order of increasing value.

vector<double> copyToVector(list<int>& arg)
{
    vector<double> toReturn;
    for (list<int>::iterator it = arg.begin(); it != arg.end(); it++)
    {
        toReturn.push_back(*it);
    }
    return toReturn;
}

int main()
{
    list<int> arg{1, 2, 5, 4, 3};
    vector<double> vec = copyToVector(arg);
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    return 0;
}
