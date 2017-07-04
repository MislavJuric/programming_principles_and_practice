#include "../../std_lib_facilities.h"

// 4. An int can hold integers only up to a maximum number. Find an approximation of that maximum number by using fibonacci().

void print(string label, const vector<int>& output)
{
    cout << label << endl;
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
}

void fibonnaci (int x, int y, vector<int>& f_numbers, int n)
{
    f_numbers.push_back(x);
    f_numbers.push_back(y);
    int first = x;
    int second = y;
    int trail = 0;
    for (int i = 0; i < n; i++)
    {
        int new_number = first + second;
        first = second;
        second = new_number;
        f_numbers.push_back(new_number);
        if (new_number < 0)
        {
            cout << "Int limit is approx. " << trail << endl;
        }
        trail = new_number;
    }
}

int main()
{
    vector<int> f_numbers;
    fibonnaci(1, 2, f_numbers, 50);
    print("Results:", f_numbers);
}
