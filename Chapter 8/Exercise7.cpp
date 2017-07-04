#include "../../std_lib_facilities.h"

// 7. Read five names into a vector<string> name, then prompt the user for the ages of the people named and store the ages in
// a vector<double> age. Then print out the five (name[i],age[i]) pairs. Sort the names (sort(name.begin(),name.end()))
// and print out the (name[i],age[i]) pairs. The tricky part here is to get the age vector in the correct order to match the
// sorted name vector.
// Hint: Before sorting name, take a copy and use that to make a copy of age in the right order after sorting name.
// Then, do that exercise again but allowing an arbitrary number of names.

int main()
{
    vector<string> names;
    vector<int> ages;
    int n;
    cout << "How many names do you want to enter?" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        int age;
        cin >> name >> age;
        names.push_back(name);
        ages.push_back(age);
    }
    vector<string> names_copy = names;
    vector<int> new_ages = ages;
    sort(names.begin(), names.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (names[i] == names_copy[j])
            {
                new_ages[i] = ages[j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << names[i] << " " << new_ages[i] << endl;
    }
}
