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

// I misinterpreted the task... I thought that all counted_ptr<T> should point to the same object, while this is not the case

// gonna re-implement this (Hint: PIMPL)

// using namespace std;

template<typename T>
class counted_ptr
{
    private:
        T* elem {nullptr};
        int* useCount {0};
    public:
        counted_ptr(T initValue);
        ~counted_ptr();
        counted_ptr(const counted_ptr& other); // copy constructor
        counted_ptr(counted_ptr&& other); // move constructor
        counted_ptr& operator= (const counted_ptr& other); // copy assignment
        counted_ptr& operator= (counted_ptr&& other); // move assignment


        T* getElem() { return elem; }
        void incrementUseCount() { *useCount++; }
        int getUseCount() { return *useCount; }
};

template<typename T>
counted_ptr<T>::counted_ptr(T initValue)
{
    elem = new T;
    *elem = initValue;
    useCount = new int;
    incrementUseCount();
}

template<typename T>
counted_ptr<T>::~counted_ptr()
{
    *useCount--;
    if (*useCount == 0)
    {
        delete elem;
        delete useCount;
    }
}

template<typename T>
counted_ptr<T>::counted_ptr(const counted_ptr& other) // copy constructor
{
    elem = other.elem;
    incrementUseCount(); // I think I made a mistake here; other's use count should match this object's use count after this line
}

template<typename T>
counted_ptr<T>::counted_ptr(counted_ptr&& other) // move constructor
{
    elem = other.elem;
    incrementUseCount();
    other.useCount = useCount; // I think I'm missing this line in the above code
}

template<typename T>
counted_ptr<T>& counted_ptr<T>::operator= (const counted_ptr& other) // copy assignment
{
    delete elem;
    delete useCount;
    elem = other.elem;
    useCount = new int;
    incrementUseCount();
}

template<typename T>
counted_ptr<T>& counted_ptr<T>::operator= (counted_ptr&& other)
{
    delete elem;
    delete useCount;
    elem = other.elem;
    useCount = new int;
    incrementUseCount();
    other.useCount = useCount;
}

int main()
{
    counted_ptr<std::string> p{"pizza"};
    counted_ptr<std::string> s = p;
    std::cout << p.getUseCount() << std::endl;
    return 0;
}
