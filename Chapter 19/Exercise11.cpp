#include <iostream>

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

template<typename T>
class counted_ptr
{
    private:
        static T* elem;
        static int* useCount; // if I don't initialize it, I will get undefined behaviour... hmmm...
    public:
        counted_ptr(T initValue);
        counted_ptr();
        ~counted_ptr();

};

template<typename T> int* counted_ptr<T>::useCount = nullptr;
template<typename T> T* counted_ptr<T>::elem = nullptr;

template<typename T>
counted_ptr<T>::counted_ptr()
{
    if (*useCount == 0)
    {
        // error("You have to initialize the object counted_ptr points to.");
    }
}

template<typename T>
counted_ptr<T>::counted_ptr(T initValue)
{
    if (elem == nullptr)
    {
        elem = new T{initValue};
    }
    if (useCount == nullptr)
    {
        useCount = new int{1};
    }
    else
    {
        *useCount++;
    }
}

template<typename T>
counted_ptr<T>::~counted_ptr()
{
    *useCount--;
    if (*useCount == 0)
    {
        delete useCount;
        delete elem;
    }
}

int main()
{
    counted_ptr<int> cp{3};

    return 0;
}
