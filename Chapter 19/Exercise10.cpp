#include <iostream>

// 10. Implement a simple unique_ptr supporting only a constructor, destructor, –>, *, and release().
// In particular, don’t try to implement an assignment or a copy constructor.

using namespace std;

template<typename T>
class unique_ptr
{
    private:
        T* elem;
    public:
        unique_ptr(T* arg);
        ~unique_ptr();

        // my -> operator isn't right... hmmmm...
        T operator->() const
        {
            return elem;
        }

        T operator*() const
        {
            return *(elem);
        }

        void release();
};

template<typename T>
unique_ptr<T>::unique_ptr(T* arg)
{
    elem = arg;
}

template<typename T>
unique_ptr<T>::~unique_ptr()
{
    delete elem;
}

template<typename T>
void unique_ptr<T>::release()
{
    delete elem;
    elem = nullptr;
}

int main()
{
    int* myInt = new int{3};
    unique_ptr<int> up{myInt};
    cout << *up << endl;
    return 0;
}
