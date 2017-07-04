#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

/*

Go through this drill step by step. Do not try to speed up by skipping steps. Test each step by entering at least three pairs of values -
more values would be better.

1. Write a program that consists of a while-loop that (each time around the loop) reads in two ints and then prints them.
Exit the program when a terminating '|' is entered.

2. Change the program to write out the "smaller value is:" followed by the smaller of the numbers and the "larger value is:" followed by the larger value.

3. Augment the program so that it writes the line the numbers are equal (only) if they are equal.

4. Change the program so that it uses doubles instead of ints.

5. Change the program so that it writes out the numbers are almost equal after writing out which is the larger and the smaller if
the two numbers differ by less than 1.0/100.

6. Now change the body of the loop so that it reads just one double each time around. Define two variables to keep track of which is
the smallest and which is the largest value you have seen so far. Each time through the loop write out the value entered.
If it’s the smallest so far, write the smallest so far after the number. If it is the largest so far, write the largest so far after the number.

7. Add a unit to each double entered; that is, enter values such as 10cm, 2.5in, 5ft, or 3.33m. Accept the four units: cm, m, in, ft.
Assume conversion factors 1m == 100cm, 1in == 2.54cm, 1ft == 12in. Read the unit indicator into a string.
You may consider 12 m (with a space between the number and the unit) equivalent to 12m (without a space).

8. Reject values without units or with “illegal” representations of units, such as y, yard, meter, km, and gallons.

9. Keep track of the sum of values entered (as well as the smallest and the largest) and the number of values entered.
When the loop ends, print the smallest, the largest, the number of values, and the sum of values. Note that to keep the sum,
you have to decide on a unit to use for that sum; use meters.

10. Keep all the values entered (converted into meters) in a vector. At the end, write out those values.

11. Before writing out the values from the vector, sort them (that’ll make them come out in increasing order).

*/

int main()
{
    double input;
    double smallest = INT_MAX, largest = 0;
    vector<double> inputs;
    string unit;
    int sum = 0;
    int num_of_values = 0;
    while (cin >> input >> unit)
    {
        cout << input << " " << unit << endl;
        if (unit == "m")
        {
            input *= 100; // conversion in cm
        }
        if (unit == "in")
        {
            input *= 2.54;
        }
        if (unit == "ft")
        {
            input *= 12;
        }
        sum += (input / 100);
        num_of_values++;
        inputs.push_back(input / 100);
        if ((unit != "m") && (unit != "in") && (unit != "ft"))
        {
            cout << "I don't know how to handle that input." << endl;
        }
        if (smallest > input)
        {
            smallest = input;
            cout << "Smallest so far." << endl;
        }
        if (largest < input)
        {
            largest = input;
            cout << "Largest so far." << endl;
        }

        /*

        if (first > second)
        {
            cout << "Smaller value is " << second << " and the bigger value is " << first << "." << endl;
            if ((first - second) < 0.01)
            {
                cout << "Numbers are almost equal." << endl;
            }
        }
        else if (first == second)
        {
            cout << "Numbers are equal" << endl;
        }
        else
        {
            cout << "Smaller value is " << first << " and the bigger value is " << second << "." << endl;
            if ((second - first) < 0.01)
            {
                cout << "Numbers are almost equal." << endl;
            }
        }

        */
    }
    cout << "Smallest: " << smallest << endl;
    cout << "Largest: " << largest << endl;
    cout << "Sum: " << sum << endl;
    cout << "Number of values: " << num_of_values << endl;
    sort(inputs.begin(), inputs.end());
    for (int i = 0; i < inputs.size(); i++)
    {
        cout << inputs[i] << " ";
    }
    cout << endl;
    return 0;
}
