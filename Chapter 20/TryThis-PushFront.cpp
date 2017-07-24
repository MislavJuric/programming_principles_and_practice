#include <iostream>
#include <memory>

using namespace std;

struct out_of_range { /* . . . */ };   // class used to report range access errors

template<typename T, typename A = allocator<T>>
class vector {
/*
          invariant:
          if 0<=n<sz, elem[n] is element n
          sz<=space;
          if sz<space there is space for (space–sz) doubles after elem[sz–1]
*/
      A alloc;
      int sz;                          // the size
      T* elem;      // pointer to the elements (or 0)
      int space;               // number of elements plus number of free slots
public:
      vector() : sz{0}, elem{nullptr}, space{0} { }
      vector(initializer_list<double> lst)                  // initializer-list constructor
                    :sz{lst.size()}, elem{new T[sz]}   // uninitialized memory
                                                                                         // for elements
      {
          copy( lst.begin(),lst.end(),elem);    // initialize (using std::copy(); §B.5.2)
      }

      vector(const vector&);                                   // copy constructor
      vector& operator=(const vector&);            // copy assignment

      vector(vector&&);                                          // move constructor
      vector& operator=(vector&&);                   // move assignment

      ~vector() { delete[] elem; }                                      // destructor

      T& at(int n);                            // checked access
      const T& at(int n) const;      // checked access

      T& operator[ ](int n) { return elem[n]; }    // access: return reference
      const T& operator[](int n) const { return elem[n]; }

      int size() const { return sz; }
      int capacity() const { return space; }

      void resize(int newsize, T def = T());                                        // growth
      void push_back(const T& val);
      void push_front(const T& val);
      void reserve(int newalloc);

      /*

      //---------------------20.5 code---------------------------

      using size_type = unsigned long;
      using value_type = T;
      using iterator = T*;
      using const_iterator = const T*;

      // I have to implement begin() and end()

      iterator begin();
      const_iterator begin() const;
      iterator end();
      const_iterator end() const;

      size_type size();

      //---------------------20.5 code---------------------------

      //---------------------20.8 code---------------------------

      // using iterator = T*;      // T* is the simplest possible iterator
      // I declared this above line on line 54.

      iterator insert(iterator p, const T& val);
      iterator erase(iterator p);

      //---------------------20.8 code---------------------------

      */
};

//---------------------20.8 code--------------------------

/*

template<typename T, typename A>            // requires Element<T>() &&
                                            // Allocator<A>() (§19.3.3)
typename vector<T,A>::iterator vector<T,A>::erase(iterator p)
{
          if (p==end()) return p;
          for (auto pos = p+1; pos!=end(); ++pos)
                    *(pos-1) = *pos;                 // copy element “one position to the left”
          alloc.destroy(&*(end()-1));        // destroy surplus copy of last element
          --sz;
          return p;
}

template<typename T, typename A>             // requires Element<T>() &&
                                             // Allocator<A>() (§19.3.3)
typename vector<T,A>::iterator vector<T,A>::insert(iterator p, const T& val)
{
          int index = p-begin();
          if (size()==capacity())
                    reserve(size()==0?8:2*size());   // make sure we have space

          // first copy last element into uninitialized space:
          alloc.construct(elem+sz,*back());

          ++sz;
          iterator pp = begin()+index;      // the place to put val
          for (auto pos = end()-1; pos!=pp; --pos)
                    *pos = *(pos-1);                // copy elements one position to the right
          *(begin()+index) = val;               // “insert” val
          return pp;
}

*/

//---------------------20.8 code--------------------------

template<typename T, typename A > T& vector<T,A>::at(int n)
{
          if (n<0 || sz<=n) throw ::out_of_range();
          return elem[n];
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
{
      if (this==&a) return *this;      // self-assignment, no work needed

      if (a.sz<=space) {                     // enough space, no need for new allocation
                for (int i = 0; i<a.sz; ++i) elem[i] = a.elem[i];        // copy elements
                sz = a.sz;
                return *this;
      }

      T* p = new T[a.sz];                         // allocate new space
      for (int i = 0; i<a.sz; ++i) p[i] = a.elem[i];        // copy elements
      delete[] elem;                                    // deallocate old space
      space = sz = a.sz;                             // set new size
      elem = p;                                           // set new elements
      return *this;                                      // return a self-reference
}

template<typename T, typename A>
vector<T,A>::vector(vector&& a)
          :sz{a.sz}, elem{a.elem}                // copy a’s elem and sz
{
          a.sz = 0;                                          // make a the empty vector
          a.elem = nullptr;
}

template<typename T, typename A>
vector<T, A>& vector<T, A>::operator=(vector&& a) // move a to this vector
{
          delete[] elem;                                // deallocate old space
          elem = a.elem;                              // copy a’s elem and sz
          sz = a.sz;
          a.elem = nullptr;                          // make a the empty vector
          a.sz = 0;
          return *this;                                 // return a self-reference (see §17.10)
}

template<typename T, typename A>
void vector<T,A>::reserve(int newalloc)
{
      if (newalloc<=space) return;               // never decrease allocation
      T* p = alloc.allocate(newalloc);          // allocate new space
      for (int i=0; i<sz; ++i) alloc.construct(&p[i],elem[i]);       // copy
      for (int i=0; i<sz; ++i) alloc.destroy(&elem[i]);                 // destroy
      alloc.deallocate(elem,space);             // deallocate old space
      elem = p;
      space = newalloc;
}

template<typename T, typename A>
void vector<T,A>::resize(int newsize, T val)
{
      reserve(newsize);
      for (int i=sz; i<newsize; ++i) alloc.construct(&elem[i],val);   // construct
      for (int i = newsize; i<sz; ++i) alloc.destroy(&elem[i]);            // destroy
      sz = newsize;
}

template<typename T, typename A>
void vector<T,A>::push_back(const T& val)
{
      if (space==0) reserve(8);                            // start with space for 8 elements
      else if (sz==space) reserve(2*space);      // get more space
      alloc.construct(&elem[sz],val);                 // add val at end
      ++sz;                                                              // increase the size
}

template<typename T, typename A>
void vector<T,A>::push_front(const T& val)
{
      if (space==0) reserve(8);                            // start with space for 8 elements
      else if (sz==space) reserve(2*space);      // get more space
      for (int i = sz; i > 0; i--)
      {
          elem[i] = elem[i - 1];
      }
      alloc.construct(&elem[0], val);
      sz++;
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    cout << "-----------------------" << endl;
    v.push_front(6);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    // 19.4 stao
    return 0;
}
