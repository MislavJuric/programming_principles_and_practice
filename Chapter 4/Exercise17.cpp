#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 17. Write a program that finds the min, max, and mode of a sequence of strings.

int main()
{
    string min;
    string max;
    vector<string> values;
    vector<int> count;
    bool found = false;
    for (string input; cin >> input;)
    {
        for (int i = 0; i < values.size(); i++)
        {
            if (values[i] == input)
            {
                count[i]++;
                found = true;
            }
        }
        if (found == false)
        {
            values.push_back(input);
            count.push_back(1);
        }
        found = false; // bool has to be reset to false
    }
    int mode_index = 0;
    int mode = 0;
    for (int i = 0; i < count.size(); i++)
    {
        if (count[i] > mode)
        {
            mode = count[i];
            mode_index = i;
        }
    }
    cout << "Mode is " << values[mode_index] << endl;
    if (values.size() > 0)
    {
        min = values[0];
        max = values[0];
    }
    for (int i = 1; i < values.size(); i++)
    {
        if (values[i].size() < min.size())
        {
            min = values[i];
        }
        if (values[i].size() > max.size())
        {
            max = values[i];
        }
    }
    cout << "Minimum is " << min << endl;
    cout << "Maximum is " << max << endl;
    return 0;
}
