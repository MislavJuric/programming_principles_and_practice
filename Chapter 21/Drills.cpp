#include "../Headers/std_lib_facilities.h"

struct Item
{
    string name;
    int iid;
    double value;
    /* . . . */
};

// how come this operator works, and I haven't addressed '\n' explicitly?

istream& operator >> (istream& is, Item& item)
{
    string name;
    int iid;
    double value;
    char ch1;
    char ch2;
    is >> ch1;
    if (ch1 != '{')
    {
        error("Bad formmatting");
    }
    is >> name;
    is >> iid;
    is >> value;
    is >> ch2;
    if (ch2 != '}')
    {
        error("Bad formmatting");
    }
    item.name = name;
    item.iid = iid;
    item.value = value;
}

void printVector(const vector<Item>& arg)
{
    for (int i = 0; i < arg.size(); i++)
    {
        cout << arg[i].name << " " << arg[i].iid << " " << arg[i].value << endl;
    }
}

int main()
{
    // 1. Define a struct Item { string name; int iid; double value; /* . . . */ };, make a vector<Item>, vi, and fill it
    // with ten items from a file.
    ifstream is{"Drills.txt"};
    vector<Item> items;
    for (int i = 0; i < 10; i++)
    {
        Item temp;
        is >> temp;
        items.push_back(temp);
    }
    // 2. Sort vi by name.
    sort(items.begin(), items.end(), [](const Item& item1, const Item& item2) {return item1.name < item2.name; });
    printVector(items);
    cout << "--------------------------------------------------" << endl;
    // 3. Sort vi by iid.
    sort(items.begin(), items.end(), [](const Item& item1, const Item& item2) {return item1.iid < item2.iid; });
    printVector(items);
    cout << "--------------------------------------------------" << endl;
    // 4. Sort vi by value; print it in order of decreasing value (i.e., largest value first).
    sort(items.begin(), items.end(), [](const Item& item1, const Item& item2) {return item1.value > item2.value; });
    printVector(items);
    cout << "--------------------------------------------------" << endl;
    // 5. Insert Item('horse shoe',99,12.34) and Item('Canon S400', 9988,499.95).
    items.push_back(Item{"horse shoe", 99, 12.34});
    items.push_back(Item{"Canon S400", 9988, 499.95});
    // 6. Remove (erase) two Items identified by name from vi.
    string firstName, secondName;
    cin >> firstName >> secondName;
    for (auto it = items.begin(); it != items.end(); it++)
    {
        if ((it->name == firstName) || (it->name == secondName))
        {
            items.erase(it);
        }
    }
    printVector(items);
    cout << "--------------------------------------------------" << endl;
    // 7. Remove (erase) two Items identified by iid from vi.
    int iid1, iid2;
    cin >> iid1 >> iid2;
    for (auto it = items.begin(); it != items.end(); it++)
    {
        if ((it->iid == iid1) || (it->iid == iid2))
        {
            items.erase(it);
        }
    }
    printVector(items);
    // 8. Repeat the exercise with a list<Item> rather than a vector<Item>.
    // I'd do the same thing, and since I used iterators I only have to change the push_back() function to push_front()


}
