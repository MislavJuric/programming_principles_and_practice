#include <iostream>

using namespace std;

// 14. Define a singly-linked list, slist, in the style of std::list. Which operations from list could you reasonably eliminate
// from slist because it doesn’t have back pointers?

template<typename Elem>
struct Link
{
          Link* next;               // successor (next) link
          Elem val;                   // the value
};

template<typename Elem>
class slist
{
    private:
        Link<Elem>* first;
        Link<Elem>* oneBeyondTheLast;

    public:

        slist() : first{nullptr}, oneBeyondTheLast{nullptr} { }

        class iterator;                 // member type: iterator

        iterator begin();            // iterator to first element
        iterator end();              // iterator to one beyond last element

        iterator insert(iterator p, const Elem& v);        // insert v into list after p
        iterator erase(iterator p);                                    // remove p from the list


        void push_front(const Elem& v);
        void push_back(const Elem& v);
        void pop_front();
        void pop_back();
        Elem& front();
        Elem& back();
};

template <typename Elem>
void slist<Elem>::push_front(const Elem& v)
{
    Link<Elem>* newNode = new Link<Elem>;
    newNode->val = v;
    newNode->next = first;
    first = newNode;
}

template <typename Elem>
void slist<Elem>::push_back(const Elem& v)
{
    Link<Elem>* newNode = new Link<Elem>;
    newNode->val = v;
    if (first != nullptr)
    {
        Link<Elem>* trail = nullptr;
        Link<Elem>* loopPtr = first;
        while (loopPtr != nullptr)
        {
            trail = loopPtr;
            loopPtr = loopPtr->next;
        }
        trail->next = newNode;
        newNode->next = nullptr;
        oneBeyondTheLast = newNode->next;
    }
    else
    {
        first = newNode;
        newNode->next = nullptr;
    }
}

template <typename Elem>
void slist<Elem>::pop_front()
{
    Link<Elem>* temp = first;
    first = first->next;
    delete temp;
}

template <typename Elem>
void slist<Elem>::pop_back()
{
    Link<Elem>* trail = nullptr;
    Link<Elem>* trail2 = nullptr;
    Link<Elem>* loopPtr = first;
    bool firstPass = true;
    while (loopPtr != nullptr)
    {
        if (firstPass == false)
        {
            trail2 = trail;
        }
        trail = loopPtr;
        loopPtr = loopPtr->next;
        firstPass = false;
    }
    trail2->next = nullptr;
    delete trail;
}

template <typename Elem>
Elem& slist<Elem>::front()
{
    return first;
}

template <typename Elem>
Elem& slist<Elem>::back()
{
    Link<Elem>* trail = nullptr;
    Link<Elem>* loopPtr = first;
    while (loopPtr != nullptr)
    {
        trail = loopPtr;
        loopPtr = loopPtr->next;
    }
    return trail;
}

template <typename Elem>
typename slist<Elem>::iterator slist<Elem>::begin()
{
    return first;
}

template <typename Elem>
typename slist<Elem>::iterator slist<Elem>::end()
{
    return oneBeyondTheLast;
}

template<typename Elem>         // requires Element<Elem>() (§19.3.3)
class slist<Elem>::iterator
{
          Link<Elem>* curr;              // current link
public:
          iterator(Link<Elem>* p) :curr{p} { }

          iterator& operator++() {curr = curr->next; return *this; }   // forward
          Elem& operator*() { return curr->val; }   // get value (dereference)

          bool operator==(const iterator& b) const { return curr==b.curr; }
          bool operator!= (const iterator& b) const { return curr!=b.curr; }
};

int main()
{
    slist<int> l;
    l.push_back(2);
    l.push_front(3);
    l.push_back(4);
    l.pop_back();
    l.pop_back();
    l.pop_front();
    for (slist<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        cout << *it << endl;
    }
    return 0;
}
