#include "../Headers/std_lib_facilities.h"

// 4. Write a function print_array10(ostream& os, int* a) that prints out the values of a (assumed to have ten elements) to os.
void print_array10(ostream& os, int* a)
{
    for (int i = 0; i < 10; i++)
    {
        os << a[i] << endl;
    }
}

// 7. Write a function print_array(ostream& os, int* a, int n) that prints out the values of a (assumed to have n elements) to os.
void print_array(ostream& os, int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        os << a[i] << endl;
    }
}

void print_vector(ostream& os, vector<int>& vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        os << vec[i] << endl;
    }
}

int main()
{
    // 1. Allocate an array of ten ints on the free store using new.
    int* tenIntArray = new int[10];
    // 2. Print the values of the ten ints to cout.
    for (int i = 0; i < 10; i++)
    {
        cout << tenIntArray[i] << endl;
    }
    // 3. Deallocate the array (using delete[]).
    delete[] tenIntArray;
    // 5. Allocate an array of ten ints on the free store; initialize it with the values 100, 101, 102, etc.;
    // and print out its values.
    int* tenIntArray2 = new int[10] {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
    for (int i = 0; i < 10; i++)
    {
        cout << tenIntArray2[i] << endl;
    }
    //6. Allocate an array of 11 ints on the free store; initialize it with the values 100, 101, 102, etc.;
    // and print out its values.

    // this is the same as exercise 5

    // 8. Allocate an array of 20 ints on the free store; initialize it with the values 100, 101, 102, etc.;
    // and print out its values.

    // same as exercise 5

    // 9. Did you remember to delete the arrays? (If not, do it.)

    // Ooops! At the time of writing, I did forget. I just leaked some memory.

    delete[] tenIntArray2;

    // 10. Do 5, 6, and 8 using a vector instead of an array and a print_vector() instead of print_array().

    vector<int> tenElementVec{100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
    print_vector(cout, tenElementVec, 10);
    return 0;
}
