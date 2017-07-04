#include "std_lib_facilities.h"

using namespace std;

/*

8. Write a program that reads and stores a series of integers and then computes the sum of the first N integers.
First ask for N, then read the values into a vector, then calculate the sum of the first N values. For example:

“Please enter the number of values you want to sum:”

3

“Please enter some integers (press '|' to stop):”

12 23 13 24 15 |

“The sum of the first 3 numbers ( 12 23 13 ) is 48.”

Handle all inputs. For example, make sure to give an error message if the user asks for a sum of more numbers than
there are in the vector.

*/

int main()
{
    try
    {
        int n;
        vector<int> inputs;
        cin >> n;
        for (int i; cin >> i;)
        {
            inputs.push_back(i);
        }
        int sum = 0;
        if (n > (inputs.size() - 1))
        {
            error("N is greater than the sum");
        }
        for (int i = 0; i < n; i++)
        {
            sum += inputs[i];
        }
        cout << "Your sum is: " << sum << endl; // output formatting isn't exactly as it is in the exercise
    }
    catch (runtime_error)
    {
        cout << "N is too large" << endl;
    }
    return 0;
}
