#include "../Headers/std_lib_facilities.h"

// 1. Write a template function f() that adds the elements of one vector<T> to the elements of another;
// for example, f(v1,v2) should do v1[i]+=v2[i] for each element of v1.

template<typename T>
vector<T> f(const vector<T>& v1, const vector<T>& v2)
{
    if (v1.size() != v2.size())
    {
        error("Vectors are not the same size.");
    }
    vector<T> toReturn;
    for (int i = 0; i < v1.size(); i++)
    {
        toReturn.push_back(v1[i] + v2[i]);
    }
    return toReturn;
}

int main()
{
    /*
    vector<int> v1 {1, 2, 3};
    vector<int> v2 {4, 5, 6, 7};
    */
    vector<string> v1 {"Marco"};
    vector<string> v2 {"Polo"};
    vector<string> result = f(v1, v2);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}
