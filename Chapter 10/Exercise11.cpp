#include "../std_lib_facilities.h"
#include <sstream>
#include <cstdlib>

//11. Write a program that produces the sum of all the whitespace-separated integers in a text file.
// For example, bears: 17 elephants 9 end should output 26.

const string filename = "e11.txt";

int main()
{
    ifstream ist {filename};
    int number;
    int sum = 0;
    string line;
    while (ist >> line)
    {
        stringstream strstream (line);
        strstream >> number;
        if (!(strstream.fail()))
        {
            sum += number;
        }

    }
    cout << "Sum of the numbers in the file is: " << sum << endl;
    return 0;
}
