#include "../../std_lib_facilities.h"

// 9. Write a function that given two vector<double>s price and weight computes a value (an “index”) that is the sum of all
// price[i]*weight[i]. Make sure to have weight.size()==price.size().

double sumCalc(const vector<double>& price, const vector<double>& weight)
{
    if (price.size() != weight.size())
    {
        error("Prices and weights must have the same number of elements");
    }
    double sum = 0;
    for (int i = 0; i < price.size(); i++)
    {
        sum += price[i] * weight[i];
    }
    return sum;
}

int main()
{
    try
    {
        vector<double> price {1, 2, 3, 4, 5};
        vector<double> weight {5, 4, 3, 2, 1};
        double sum = sumCalc(price, weight);
        cout << sum << endl;
    }
    catch (...)
    {
        cout << "Ooops! An error occured." << endl;
    }

}
