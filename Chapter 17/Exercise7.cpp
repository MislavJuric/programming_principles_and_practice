#include "../Headers/std_lib_facilities.h"

// 7. Write a program that reads characters from cin into an array that you allocate on the free store. Read individual characters
// until an exclamation mark (!) is entered. Do not use a std::string. Do not worry about memory exhaustion.

int main()
{
    // I will assume that because of this sentence "Do not worry about memory exhaustion.", I allocate
    // a fixed-size array on the heap and then read elements into it.
    constexpr int arraySize = 100; // when I put this = 1, it doesn't segfault... Hmmm...
    char* arr = new char[arraySize];
    char input;
    cin >> input;
    int index = 0;
    while (input != '!')
    {
        cin >> input;
        arr[index] = input;
        index++;
    }
    // char* pointerToLastElement = arr[index];
    // now I could deallocate all the memory I didn't use (if 100 was too much)
    return 0;
}
