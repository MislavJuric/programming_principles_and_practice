#include "../Headers/std_lib_facilities.h"

// 8. Do exercise 7 again, but this time read into a std::string rather than to memory you put on the free store
// (string knows how to use the free store for you).

int main()
{
    string input;
    char inputChar;
    cin >> inputChar;
    while (inputChar != '!')
    {
        input += inputChar;
        cin >> inputChar;
    }
    return 0;
}
