#include "../Headers/std_lib_facilities.h"

// 2. Write a template function that takes a vector<T> vt and a vector<U> vu as arguments and returns the sum of all vt[i]*vu[i]s.

// hmmm... the return type is questionable here... what will I return?
// if U has greater precision, I should return a U, if T has greater precision, I should return T

template<typename T, typename U>
U f(vector<T> vt, vector<U> vu)
{
    if (vt.size() != vu.size())
    {
        error("Vectors are not the same size.");
    }
    U toReturn = 0; // or T ... how to express this in code?
    for (int i = 0; i < vt.size(); i++)
    {
        toReturn += vt[i] * vu[i];
     }
    return toReturn;
}

int main()
{
    vector<int> v1 {1, 2, 3};
    vector<int> v2 {4, 5, 6};
    int sum = f(v1, v2);
    cout << sum << endl;
    return 0;
}
