#include "../../std_lib_facilities.h"

// 3. Create a vector of Fibonacci numbers and print them using the function from exercise 2. To create the vector,
// write a function, fibonacci(x,y,v,n), where integers x and y are ints, v is an empty vector<int>, and n is the number
// of elements to put into v; v[0] will be x and v[1] will be y. A Fibonacci number is one that is part of a sequence where
// each element is the sum of the two previous ones. For example, starting with 1 and 2, we get 1, 2, 3, 5, 8, 13, 21, . . . .
// Your fibonacci() function should make such a sequence starting with its x and y arguments.

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
    for (int i = 0; i < n; i++)
    {
        int new_number = first + second;
        first = second;
        second = new_number;
        f_numbers.push_back(new_number);
    }
}

int main()
{
    vector<int> f_numbers;
    fibonnaci(1, 2, f_numbers, 5);
    print("Results:", f_numbers);
}
