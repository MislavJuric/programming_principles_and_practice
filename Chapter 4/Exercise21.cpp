#include "std_lib_facilities.h"

using namespace std;

// 21. Modify the program from exercise 19 so that when you enter an integer, the program will output all the names with
// that score or score not found.

struct entry
{
    string name;
    int score;
};

int main()
{
    vector<entry> entries;
    string name;
    int score;
    cin >> name >> score;
    while ((name != "NoName") && (score != 0))
    {
        entries.push_back(entry{name, score});
        cin >> name >> score;
        for (int i = 0; i < entries.size(); i++)
        {
            if (entries[i].name == name)
            {
                error("Name must be unique.");
            }
        }
    }
    int input;
    cout << "Enter the score you want to find players by: " << endl;
    cin >> input;
    cout << endl;
    bool found = false;
    for (int i = 0; i < entries.size(); i++)
    {
        if (entries[i].score == input)
        {
            cout << entries[i].name << endl;
            found = true;
        }
    }
    if (found == false)
    {
        cout << "score not found" << endl;
    }
    return 0;
}
