#include "../Headers/std_lib_facilities.h"

/*

6. Write a simple copy() operation,

template<typename Iter1, typename Iter2>
          // requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2);

that copies [f1,e1) to [f2,f2+(e1–f1)) and returns f2+(e1–f1) just like the standard library copy function.
Note that if f1==e1 the sequence is empty, so that there is nothing to copy.

*/

template<typename Iter1, typename Iter2>
          // requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    if (f1 == e1) return f2;
    Iter2 it2 = f2;
    for (Iter1 it = f1; f1 != e1; it++)
    {
        *it2 = *it;
        it2++;
    }
}

int main()
{
    // 1. Define an array of ints with the ten elements { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }.
    int arr[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // 2. Define a vector<int> with those ten elements.
    vector<int> vi {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // 3. Define a list<int> with those ten elements.
    list<int> li {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // 4. Define a second array, vector, and list, each initialized as a copy of the first array, vector, and list, respectively.
    int arr_copy[10];
    for (int i = 0; i < 10; i++) // there are 10 elements; yes, this is a magic const
    {
        arr_copy[i] = arr[i];
    }
    vector<int> vi_copy = vi;
    list<int> li_copy = li;
    // 5. Increase the value of each element in the array by 2; increase the value of each element in the vector by 3;
    // increase the value of each element in the list by 5.
    for (int i = 0; i < 10; i++)
    {
        arr[i] += 2;
        vi[i] += 3;
    }
    for (list<int>::iterator it = li.begin(); it != li.end(); it++)
    {
        *it += 5;
    }
    // 7. Use your copy() to copy the array into the vector and to copy the list into the array.
    ::copy(&arr[0], &arr[10], vi.begin());
    ::copy(li.begin(), li.end(), &arr[0]);

    /*
    for (int i = 0; i < 10; i++)
    {
        cout << vi[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    */

    return 0;
}
