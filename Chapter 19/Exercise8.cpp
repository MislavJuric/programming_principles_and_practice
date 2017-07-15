#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <cstdlib>

// 8. Implement an allocator (§19.3.7) using the basic allocation functions malloc() and free() (§B.11.4).
// Get vector as defined by the end of §19.4 to work for a few simple test cases. Hint: Look up “placement new” and
// “explicit call of destructor” in a complete C++ reference.

using std::cin;
using std::cout;
using std::cerr;
using std::initializer_list;

//------------------------------------------------------------------------------

template<class T> class allocator {
public:
    // ...
    T* allocate(int n);            // allocate space for n objects of type T
    void deallocate(T* p, int n);  // deallocate n objects of type T starting at p

    void construct(T* p, const T& v); // construct a T with the value v in p
    void destroy(T* p);            // destroy the T in p
};

//------------------------------------------------------------------------------

// allocator implementation (I wrote this)

template<typename T>
T* allocator<T>::allocate(int n)
{
    malloc(sizeof(T)*n);
}

template<typename T>
void allocator<T>::deallocate(T* p, int n)
{
    T* temp = p;
    for(int i = 0; i < n; i++)
    {
        free(temp);
        temp++;
    }
}

template<typename T>
void allocator<T>::construct(T* p, const T& v)
{
    p = malloc(sizeof(T));
    *p = v;
}

template<typename T>
void allocator<T>::destroy(T* p)
{
    free(p);
    p = nullptr;
}

//------------------------------------------------------------------------------

struct out_of_range { /* ... */ }; // class used to report range access errors

template<class T, class A = allocator<T> > class vector {
    A alloc;                       // use allocate to handle memory for elements
    int sz;                        // the size
    T* elem;                       // a pointer to the elements
    int space;                     // size+free_space
public:
    vector() : sz(0), elem(0), space(0) { }
    vector(int s);
    vector(initializer_list<T> lst); // I added this one

    vector(const vector&);            // copy constructor
    vector& operator=(const vector&); // copy assignment

    ~vector() { delete[ ] elem; }     // destructor

    T& at(int n);                     // checked access
    const T& at(int n) const;         // checked access

    T& operator[ ](int n);            // unchecked access
    const T& operator[ ](int n) const;// unchecked access

    int size() const { return sz; }   // the current size
    int capacity() const { return space; }
};

//------------------------------------------------------------------------------

// functions I added that were declared, but not defined

template<class T, class A>
vector<T, A>::vector(int s)                    // constructor (s is the element count)
    :sz{s}, elem{new T[sz]}    // uninitialized memory for elements
{
    for (int i = 0; i<sz; ++i) elem[i] = 0.0;   // initialize
}

template<class T, class A>
vector<T, A>::vector(initializer_list<T> lst)                  // initializer-list constructor
    :sz{lst.size()}, elem{new T[sz]}   // uninitialized memory
                                            // for elements
{
    copy( lst.begin(),lst.end(),elem);    // initialize (using std::copy(); §B.5.2)
}

template<typename T, typename A>
vector<T, A>::vector(const vector& arg)
// allocate elements, then initialize them by copying
    :sz{arg.sz}, elem{new T[arg.sz]}
{
    copy(arg,arg+sz,elem);  // std::copy(); see §B.5.2
}

template<typename T, typename A>
vector<T, A>& vector<T, A>::operator=(const vector& a)
// make this vector a copy of a
{
    T* p = new T[a.sz];                // allocate new space
    copy(a.elem,a.elem+a.sz,elem);             // copy elements
    delete[] elem;                                              // deallocate old space
    elem = p;                                                     // now we can reset elem
    sz = a.sz;
    return *this;                             // return a self-reference (see §17.10)
}

//------------------------------------------------------------------------------

template<class T, class A >  T& vector<T,A>::at(int n)
{
    if (n<0 || sz<=n) throw out_of_range();
    return elem[n];
}

//------------------------------------------------------------------------------

template<class T, class A >  T& vector<T,A>::operator[ ](int n) // as before
{
    return elem[n];
}

//------------------------------------------------------------------------------

void print_some(vector<int>& v)
{
    int i = -1;
    cin >> i;
    while(i!= -1) try {
        cout << "v[" << i << "]==" << v.at(i) << "\n";
    }
    catch(out_of_range) {
        cout << "bad index: " << i << "\n";
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    vector<int> v(10);
    print_some(v);
}
catch (std::exception& e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    return 2;
}
