#include "../std_lib_facilities.h"

using namespace std;

//2. Write a program that given a file name and a word outputs each line that contains that word together with the line number.
// Hint: getline().

int main()
{
    string filename;
    cout << "Please input filename: " << endl;
    cin >> filename;
    string wordToLookFor;
    cout << "Please enter a word to look for: " << endl;
    cin >> wordToLookFor;
    ifstream in {filename};
    string line;
    int lineCount = 1;
    while(getline(in, line)) // 32 bi trebao biti ASCII code za space
    {
        istringstream iss (line);
        string word;
        while (getline(iss, word, ' '))
        {
            if (word == wordToLookFor)
            {
                cout << "Line number " << lineCount << " contains the word you looked for. The line is as follows: " << endl;
                cout << line << endl;
            }
        }
        lineCount++;
    }
    return 0;
}
