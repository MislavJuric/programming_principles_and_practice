#include <iostream>

using namespace std;

// 12. Complete the definition of list from §20.4.1–2 and get the high() example to run.
// Allocate a Link to represent one past the end.

template<typename Elem>
struct Link
{
          Link* prev;               // previous link
          Link* succ;               // successor (next) link
          Elem val;                   // the value
};

template<typename Elem>
class list {
          // representation and implementation details
          Link<Elem>* first;
          Link<Elem>* last;    // one beyond the last link
public:
          class iterator;                 // member type: iterator

          iterator begin();            // iterator to first element
          iterator end();              // iterator to one beyond last element

          iterator insert(iterator p, const Elem& v);        // insert v into list after p
          iterator erase(iterator p);                                    // remove p from the list

          void push_back(const Elem& v);                      // insert v at end
          void push_front(const Elem& v);                     // insert v at front
          void pop_front();          // remove the first element
          void pop_back();          // remove the last element

          Elem& front();               // the first element
          Elem& back();               // the last element

          // . . .
};

//--------------------------------------------------------------------------------------------

template <typename Elem>
void list<Elem>::push_front(const Elem& v)
{
    Link<Elem>* newNode = new Link<Elem>;
    newNode->val = v;
    newNode->prev = nullptr;
    newNode->succ = first;
}
template <typename Elem>
iterator list<Elem>::begin()
{
    return first;
}

template <typename Elem>
iterator list<Elem>::end()
{
    return last;
}


//--------------------------------------------------------------------------------------------

template<typename Elem>         // requires Element<Elem>() (§19.3.3)
class list<Elem>::iterator {
          Link<Elem>* curr;              // current link
public:
          iterator(Link<Elem>* p) :curr{p} { }

          iterator& operator++() {curr = curr->succ; return *this; }   // forward
          iterator& operator--() { curr = curr->prev; return *this; }   // backward
          Elem& operator*() { return curr->val; }   // get value (dereference)

          bool operator==(const iterator& b) const { return curr==b.curr; }
          bool operator!= (const iterator& b) const { return curr!=b.curr; }
};

template<typename Iter>  // requires Input_iterator<Iter>() (§19.3.3)
Iter high(Iter first, Iter last)
// the return type of the function was "Iterator"... I don't know if that was good
          // return an iterator to the element in [first,last) that has the highest value
{
          Iter high = first;
          for (Iter p = first; p!=last; ++p)
                    if (*high<*p) high = p;
          return high;
}

void f()
{
          list<int> lst; for (int x; cin >> x; ) lst.push_front(x);

          list<int>::iterator p = high(lst.begin(), lst.end());
            if (p==lst.end())             // did we reach the end?
                      cout << 'The list is empty';
            else
                      cout << 'the highest value is ' << *p << '\n';
}

int main()
{
    f();
    return 0;
}
