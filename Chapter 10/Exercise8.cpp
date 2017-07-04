#include "../std_lib_facilities.h"

//8. Write a program that accepts two file names and produces a new file that is the contents of the first file followed by
// the contents of the second; that is, the program concatenates the two files.

const string file1name = "file1.txt";
const string file2name = "file2.txt";
const string destname = "destfile.txt";

int main()
{
    ifstream file1 {file1name};
    ifstream file2 {file2name};
    ofstream destfile {destname};
    string file1_contents;
    string file2_contents;
    string line;
    while (!file1.eof())
    {
        file1 >> line;
        file1_contents += line;
        file1_contents += '\n';
    }
    file1_contents[file1_contents.size() - 1] = '\0';
    while(!file2.eof())
    {
        file2 >> line;
        file2_contents += line;
        file2_contents += '\n';
    }
    file2_contents[file2_contents.size() - 1] = '\0';
    for (char c : file1_contents)
    {
        destfile << c;
    }
    for (char c : file2_contents)
    {
        destfile << c;
    }
    return 0;
}
