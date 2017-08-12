#include <iostream>
#include <vector>

using namespace std;

//4. Implement count_if() yourself. Test it.

template<typename Iter, typename Predicate>
typename iterator_traits<Iter>::value_type
count_if(Iter first, Iter last, Predicate pred)
{
    typename iterator_traits<Iter>::value_type sum = 0;
    for (Iter it = first; it != last; it++)
    {
        if (pred(*it)) // trouble here?
        {
            sum++;
        }
    }
    return sum;
}

int main()
{
    vector<int> v {1, 2, 3, 1, 5, -1};
    cout << count_if(v.begin(), v.end(), [](int n) { return n > 1; }) << endl;
    return 0;
}
