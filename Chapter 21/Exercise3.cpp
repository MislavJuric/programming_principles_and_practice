#include <iostream>
#include <vector>

using namespace std;

// 3. Implement count() yourself. Test it.

template<typename Iter, typename T>
typename iterator_traits<Iter>::value_type
count(Iter first, Iter last, T value)
// T should be of type int or double
{
    typename iterator_traits<Iter>::value_type sum = 0;
    for (Iter it = first; it != last; it++)
    {
        if (*it == value)
        {
            sum++;
        }
    }
    return sum;
}

int main()
{
    vector<int> v {1, 2, 3, 1, 5};
    cout << count(v.begin(), v.end(), 1) << endl;
    return 0;
}
