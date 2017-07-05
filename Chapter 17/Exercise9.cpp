#include "../Headers/std_lib_facilities.h"

// 9. Which way does the stack grow: up (toward higher addresses) or down (toward lower addresses)?
// Which way does the free store initially grow (that is, before you use delete)? Write a program to determine the answers.

int main()
{
    int firstVariable;
    int secondVariable;
    cout << &firstVariable << " " << &secondVariable << endl; // stack grows down
    int* firstHeap = new int;
    int* secondHeap = new int;
    int* thirdHeap = new int;
    cout << firstHeap << " " << secondHeap << " " << thirdHeap << endl; // heap grows up
    return 0;
}
