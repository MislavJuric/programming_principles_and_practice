#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <cstdlib>

using std::cin;
using std::cout;
using std::cerr;
using std::initializer_list;

// 16. Sometimes, it is desirable that an empty vector be as small as possible. For example, someone might use
// vector<vector<vector<int>>> a lot but have most element vectors empty. Define a vector so that
// sizeof(vector<int>)==sizeof(int*), that is, so that the vector itself consists only of a pointer to a representation
// consisting of the elements, the number of elements, and the space pointer.

// the tasks says define, not define & implement (like task 11, for example)

template<typename T>
class vector
{
    struct IMPL
    {
        T* elem;
        int sz;
        int space; // space pointer? why not just make space an int?
    };
    IMPL* data;
public:
    vector() { data->elem = nullptr; data->sz = 0; data->space = 0; }
    vector(int s);
    vector(initializer_list<T> lst);

    vector(const vector&);            // copy constructor
    vector& operator=(const vector&); // copy assignment

    ~vector() { delete[] data->elem; delete data; }     // destructor

    T& at(int n);                     // checked access
    const T& at(int n) const;         // checked access

    T& operator[ ](int n);            // unchecked access
    const T& operator[ ](int n) const;// unchecked access

    int size() const { return data->sz; }   // the current size
    int capacity() const { return data->space; }
};

//------------------------------------------------------------------------------


int main()
{
    return 0;
}
