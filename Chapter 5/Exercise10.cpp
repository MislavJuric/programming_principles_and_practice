#include <iostream>
#include <vector>

using namespace std;

// 10. Modify the program from exercise 8 to use double instead of int. Also, make a vector of doubles containing the
// N–1 differences between adjacent values and write out that vector of differences.

int main()
{
    vector<double> inputs;
    vector<double> differences;
    for (int i; cin >> i;)
    {
        inputs.push_back(i);
    }
    for (int i = 0; i < inputs.size() - 1; i++)
    {
        int j = i + 1;
        differences.push_back(inputs[j] - inputs[i]);
    }
    for (int i = 0; i < differences.size(); i++)
    {
        cout << differences[i] << endl;
    }
    return 0;
}
