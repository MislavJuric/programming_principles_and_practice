#include "../../std_lib_facilities.h"

// 11. Write a function that finds the smallest and the largest element of a vector argument and also computes the mean and
// the median. Do not use global variables. Either return a struct containing the results or pass them back through reference
// arguments. Which of the two ways of returning several result values do you prefer and why?

struct retType
{
    double largest;
    double mean;
    double median;
};

retType func(const vector<double>& numbers)
{
    retType toReturn{0, 0, 0};
    double maxi = 0;
    int sum = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        sum += numbers[i];
        if (maxi < numbers[i])
        {
            maxi = numbers[i];
        }
    }
    toReturn.largest = maxi;
    vector<double> aCopy = numbers;
    sort(aCopy.begin(), aCopy.end());
    int index = aCopy.size() / 2;
    toReturn.median = aCopy[index];
    toReturn.mean = sum / (numbers.size() - 1);
    return toReturn;
}

int main()
{
    vector<double> numbers {1,2,3,4,5};
    retType result = func(numbers);
    cout << "Largest is " << result.largest << ", median is " << result.median << ", and mean is " << result.mean << endl;
}
