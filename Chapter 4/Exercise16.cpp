#include <iostream>
#include <vector>

using namespace std;

// 16. In the drill, you wrote a program that, given a series of numbers, found the max and min of that series.
// The number that appears the most times in a sequence is called the mode. Create a program that finds the mode of a set
// of positive integers.

int main()
{
    vector<int> count;
    vector<int> values;
    bool found = false;
    for (int input; cin >> input;)
    {
        for (int i = 0; i < values.size(); i++)
        {
            if (values[i] == input)
            {
                // possible segfault here? hmmm...
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
    cout << values[mode_index] << endl;
    return 0;
}
