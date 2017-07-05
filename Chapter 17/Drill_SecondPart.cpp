#include "../Headers/std_lib_facilities.h"

void print_array(ostream& os, int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        os << a[i] << endl;
    }
}

int main()
{
    // 1. Allocate an int, initialize it to 7, and assign its address to a variable p1.
    int* number = new int{7};
    int* p1 = number;
    //2. Print out the value of p1 and of the int it points to.
    cout << p1 << " " << *p1 << endl;
    int* p2 = new int[7]{1, 2, 4, 8, 16, 32, 64};
    cout << p2 << endl;
    print_array(cout, p2, 7);
    // 5. Declare an int* called p3 and initialize it with p2.
    int* p3 = p2;
    // 6. Assign p1 to p2.
    p1 = p2;
    // right here, I lost the connection to the int I allocated on line 14... memory leak
    // 7. Assign p3 to p2.
    p3 = p2;
    // 8. Print out the values of p1 and p2 and of what they point to.
    cout << p1 << " " << p2 << endl;
    cout << *p1 << " " << *p2 << endl;
    // 9. Deallocate all the memory you allocated from the free store.
    delete[] p2;
    // since p1 and p3 all point to p2's memory, I should put nullptr here
    // also note that I have a memory leak on line 24, where I don't delete the memory I allocated for that single int

    // 10. Allocate an array of ten ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p1.
    p1 = new int[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    // 11. Allocate an array of ten ints, and assign its address to a variable p2.
    p2 = new int[10];
    // 12. Copy the values from the array pointed to by p1 into the array pointed to by p2.
    for (int i = 0; i < 10; i++)
    {
        p2[i] = p1[i];
    }
    // 13. Repeat 10–12 using a vector rather than an array.

    vector<int> tenIntVector{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    vector<int> secondTenIntVector;
    secondTenIntVector = tenIntVector;

    return 0;
}
