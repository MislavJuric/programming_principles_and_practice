#include "std_lib_facilities.h"

using namespace std;

// 20. Modify the program from exercise 19 so that when you enter a name, the program will output the corresponding score
// or name not found.

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
    string toSearch;
    cout << "Enter the name you want to search for: ";
    cin >> toSearch;
    cout << endl;
    bool found = false;
    for (int i = 0; i < entries.size(); i++)
    {
        if (entries[i].name == toSearch)
        {
            cout << entries[i].score << endl;
            found = true;
        }
    }
    if (found == false)
    {
        cout << "name not found" << endl;
    }
    return 0;
}
