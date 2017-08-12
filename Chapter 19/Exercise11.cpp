#include <iostream>
#include <string>

// 11. Design and implement a counted_ptr<T> that is a type that holds a pointer to an object of type T and a pointer to a
// “use count” (an int) shared by all counted pointers to the same object of type T. The use count should hold the number of
// counted pointers pointing to a given T. Let the counted_ptr’s constructor allocate a T object and a use count on the free store.
// Let counted_ptr’s constructor take an argument to be used as the initial value of the T elements.
// When the last counted_ptr for a T is destroyed, counted_ptr’s destructor should delete the T. Give the counted_ptr operations
// that allow us to use it as a pointer. This is an example of a “smart pointer” used to ensure that an object doesn’t get
// destroyed until after its last user has stopped using it. Write a set of test cases for counted_ptr using it as an argument
// in calls, container elements, etc.

// gonna re-implement this (Hint: PIMPL) -- read the below note

// I didn't use PIMPL here

// using namespace std;

template<typename T>
class counted_ptr
{
    private:
        T* elem {nullptr};
        int* useCount {nullptr};
    public:
        counted_ptr(T initValue);
        ~counted_ptr();
        counted_ptr(const counted_ptr& other); // copy constructor
        counted_ptr(counted_ptr&& other); // move constructor
        counted_ptr& operator= (const counted_ptr& other); // copy assignment
        counted_ptr& operator= (counted_ptr&& other); // move assignment


        T* getElem() { return elem; }
        void incrementUseCount() { (*useCount)++; }
        int getUseCount() { return *useCount; }

        T operator * () { return *elem; }
        // I won't implement operator -> since I don't have a struct within this class
};

template<typename T>
counted_ptr<T>::counted_ptr(T initValue)
{
    std::cout << "Constructor" << std::endl;
    elem = new T;
    *elem = initValue;
    useCount = new int;
    *useCount = 0;
    incrementUseCount();
    // *useCount++; // this also doesn't work
    std::cout << "useCount is: " << *useCount << std::endl; // why 0 here?
}

template<typename T>
counted_ptr<T>::~counted_ptr()
{
    std::cout << "Destructor" << std::endl;
    (*useCount)--;
    if (*useCount == 0)
    {
        delete elem;
        delete useCount;
    }
}

template<typename T>
counted_ptr<T>::counted_ptr(const counted_ptr& other) // copy constructor
{
    std::cout << "Copy constructor" << std::endl;
    elem = other.elem;
    useCount = other.useCount;
    incrementUseCount(); // I think I made a mistake here; other's use count should match this object's use count after this line
    // this above line causes a segfault
}

template<typename T>
counted_ptr<T>::counted_ptr(counted_ptr&& other) // move constructor
{
    std::cout << "Move constructor" << std::endl;
    elem = other.elem;
    useCount = other.useCount;
    incrementUseCount();
}

template<typename T>
counted_ptr<T>& counted_ptr<T>::operator= (const counted_ptr& other) // copy assignment
{
    std::cout << "Copy assignment" << std::endl;
    delete elem;
    delete useCount;
    elem = other.elem;
    useCount = other.useCount;
    incrementUseCount();
}

template<typename T>
counted_ptr<T>& counted_ptr<T>::operator= (counted_ptr&& other) // move assignment
{
    std::cout << "Move assignment" << std::endl;
    delete elem;
    delete useCount;
    elem = other.elem;
    useCount = other.useCount;
    incrementUseCount();
}

template<typename T>
counted_ptr<T> f(counted_ptr<T> arg) { return arg; }

int main()
{
    counted_ptr<std::string> p{"pizza"};
    counted_ptr<std::string> s = p;
    std::cout << p.getUseCount() << std::endl;
    counted_ptr<std::string> second{"tuna"};
    s = second;
    std::cout << s.getUseCount() << std::endl;
    std::cout << *s << std::endl;
    s = f(second);
    return 0;
}
