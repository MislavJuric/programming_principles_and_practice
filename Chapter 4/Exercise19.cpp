#include "std_lib_facilities.h"

using namespace std;

// 19. Write a program where you first enter a set of name-and-value pairs, such as Joe 17 and Barbara 22.
// For each pair, add the name to a vector called names and the number to a vector called scores (in corresponding positions,
// so that if names[7]=='Joe' then scores[7]==17). Terminate input with NoName 0. Check that each name is unique and
// terminate with an error message if a name is entered twice. Write out all the (name,score) pairs, one per line.

// I solved this with structs because I found it more convinient

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
    for (int i = 0; i < entries.size(); i++)
    {
        cout << entries[i].name << " " << entries[i].score << endl;
    }
    return 0;
}
