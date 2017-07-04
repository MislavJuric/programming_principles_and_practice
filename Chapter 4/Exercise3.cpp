#include <iostream>
#include <vector>
#include <algorithm>
#include <cfloat>

using namespace std;

// 3. Read a sequence of double values into a vector. Think of each value as the distance between two cities along a given route.
// Compute and print the total distance (the sum of all distances). Find and print the smallest and greatest distance between two neighboring cities.
// Find and print the mean distance between two neighboring cities.

int main()
{
    vector<double> distances;
    for (double input; cin >> input;)
    {
        distances.push_back(input);
    }
    double smallest = DBL_MAX;
    double greatest = 0;
    double sum = 0;
    distances.sort(distances.begin(), distances.end());
    for (int i = 0; i < distances.size(); i++)
    {
        if (smallest > distances[i])
        {
            smallest = distances[i];
        }
        if (greatest < distances[i])
        {
            greatest = distances[i];
        }
        sum += distances[i];
    }
    cout << "Sum of the distances is " << sum << endl;
    cout << "Smallest distance is " << smallest << endl;
    cout << "Greatest distance is " << greatest << endl;
    cout << "Mean distance is " << distances[distances.size()/2] << endl;
    return 0;
}
