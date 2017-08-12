#include "../Headers/std_lib_facilities.h"
#include <map>

// 5. Write a function that reads value pairs from cin and places them in msi.

void readValuePairs(map<string, int>& msi)
{
    /*
    pair<string, int> p;
    cin >> p;
    */
    // pair doesn't have operator >> defined
    string name;
    int value;
    cin >> name >> value;
    msi.insert(pair<string, int>{name, value});
}

istream& operator >> (istream& is, map<string, int>& arg)
{
    string name;
    int value;
    is >> name >> value;
    arg.insert(pair<string, int>{name, value});
    return is;
}

int main()
{
    // 1. Define a map<string,int> called msi.
    map<string, int> msi;
    // 2. Insert ten (name,value) pairs into it, e.g., msi['lecture']=21.
    msi["a"] = 1;
    msi["b"] = 2;
    msi["c"] = 3;
    msi["d"] = 4;
    msi["e"] = 5;
    msi["f"] = 6;
    msi["g"] = 7;
    msi["h"] = 8;
    msi["i"] = 9;
    msi["j"] = 10;
    // 3. Output the (name,value) pairs to cout in some format of your choice.
    for (auto p = msi.begin(); p != msi.end(); p++)
    {
        cout << p->first << " " << p->second << endl;
    }
    // 4. Erase the (name,value) pairs from msi.
    msi.erase(msi.begin(), msi.end());
    readValuePairs(msi);
    // could have made the for loop below better
    for (auto p = msi.begin(); p != msi.end(); p++)
    {
        cout << p->first << " " << p->second << endl;
    }
    // 6. Read ten pairs from input and enter them into msi.
    ifstream ifs{"Drills-map.txt"};
    for (int i = 0; i < 10; i++)
    {
        ifs >> msi;
    }
    // 7. Write the elements of msi to cout.
    for (auto p = msi.begin(); p != msi.end(); p++)
    {
        cout << p->first << " " << p->second << endl;
    }
    // 8. Output the sum of the (integer) values in msi.
    int sum = accumulate(msi.begin(), msi.end(), 0, [] (int value, const std::map<string, int>::value_type& p)
                                                       { return value + p.second; });
    cout << sum << endl;
    // 9. Define a map<int,string> called mis.
    map<int, string> mis;
    // 10. Enter the values from msi into mis; that is, if msi has an element ('lecture',21),
    // mis should have an element (21,'lecture').
    for (auto p = msi.begin(); p != msi.end(); p++)
    {
        mis.insert(pair<int, string>{p->second, p->first});
    }
    // 11. Output the elements of mis to cout.
    for (auto p = mis.begin(); p != mis.end(); p++)
    {
        cout << p->first << " " << p->second << endl;
    }
    return 0;
}
