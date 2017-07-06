#include "../Headers/std_lib_facilities.h"

// Array drill

// 1. Define a global int array ga of ten ints initialized to 1, 2, 4, 8, 16, etc.

int* ga = new int[10]{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

// 2. Define a function f() taking an int array argument and an int argument indicating the number of elements in the array.

void f (int arr[], int numberOfElements)
{
    /*

    3. In f():

    a. Define a local int array la of ten ints.

    b. Copy the values from ga into la.

    c. Print out the elements of la.

    d. Define a pointer p to int and initialize it with an array allocated on the free store with the
       same number of elements as the argument array.

    e. Copy the values from the argument array into the free-store array.

    f. Print out the elements of the free-store array.

    g. Deallocate the free-store array.

    */

    int* la = new int[10];

    for (int i = 0; i < numberOfElements; i++)
    {
        la[i] = ga[i];
    }
    for (int i = 0; i < numberOfElements; i++)
    {
        cout << la[i] << endl;
    }
    int* p = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; i++)
    {
        p[i] = arr[i];
    }
    for (int i = 0; i < numberOfElements; i++)
    {
        cout << p[i] << endl;
    }
    delete[] p;
}

int main()
{
    /*
    4. In main():

    a. Call f() with ga as its argument.

    b. Define an array aa with ten elements, and initialize it with the first ten factorial values
    (1, 2*1, 3*2*1, 4*3*2*1, etc.).

    c. Call f() with aa as its argument.
    */
    f(ga, 10);
    int* aa = new int[10]{1, (2*1), (3*2*1), (4*3*2*1), (5*4*3*2*1), (6*5*4*3*2*1), (7*6*5*4*3*2*1), (8*7*6*5*4*3*2*1), (9*8*7*6*5*4*3*2*1), (10*9*8*7*6*5*4*3*2*1)};
    f(aa, 10);
    return 0;
}
