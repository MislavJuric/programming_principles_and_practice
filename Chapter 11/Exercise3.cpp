#include "../std_lib_facilities.h"

using namespace std;

// 3. Write a program that removes all vowels from a file (“disemvowels”). For example, Once upon a time! becomes nc pn tm!.
// Surprisingly often, the result is still readable; try it on your friends.

int main()
{
    ofstream temp {"temp.txt"};
    ifstream in {"e3in.txt"};
    string word;
    while (in >> word)
    {
        for (int i = 0; i < word.length(); i++)
        {
            char c = word[i];
            if ((c != 'a') && (c != 'e') && (c != 'o') && (c != 'i') && (c != 'u') && (c != 'A') && (c != 'E') && (c != 'I') && (c != 'O') && (c != 'U'))
            {
                temp << c;
            }
        }
        temp << ' ';
    }
    remove("e3in.txt");
    cout << strerror(errno) << endl; // Permission denied... Da nije zato sto nisam zatvorio datoteku?
    rename("temp.txt", "e3in.txt");
    return 0;
}
