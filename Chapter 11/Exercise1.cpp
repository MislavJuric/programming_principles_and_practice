#include "../std_lib_facilities.h"

using namespace std;

// 1. Write a program that reads a text file and converts its input to all lower case, producing a new file.

int main()
{
    ifstream in {"e1in.txt"};
    ofstream out {"e1out.txt"};
    string line;
    while (getline(in, line))
    {
        int stringLength = line.length();
        for (int i = 0; i < stringLength; i++)
        {
            line[i] = tolower(line[i]);
        }
        out << line << endl;
    }
    return 0;
}
