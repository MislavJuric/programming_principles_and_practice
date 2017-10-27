#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

// 7. Write a binary search function for a vector<int> (without using the standard one). You can choose any interface you like.
// Test it. How confident are you that your binary search function is correct? Now write a binary search function for a
// list<string>. Test it. How much do the two binary search functions resemble each other? How much do you think they would
// have resembled each other if you had not known about the STL?

vector<int>::iterator binary_search(vector<int>::iterator first, vector<int>::iterator last, int value)
{
    int dist = distance(first, last);
    vector<int>::iterator half = first + (dist / 2); // find the half of the array
    bool found = false;
    int count = 0;
    while (found == false)
    {
        if (*half == value)
        {
            found = true;
            return half;
        }
        else
        {
            count++;
            dist = dist / 2;
            if (*half > value)
            {
                if ((dist / 2) > 0)
                {
                    half = first + (dist / 2);
                }
                else
                {
                    half--; // I decrement it in the case that (dist / 2) == 0
                }
             }
            else if (*half < value)
            {
                if ((dist / 2) > 0)
                {
                     half = half + (dist / 2);
                }
                else
                {
                    half++;
                }
            }
            if ((*half == *first) || (*half == *last)) // why doesn't this check pass when I am on the highest element?
                                                            //  (or on the lowest element)
            {
                return last;
            }
        }
    }
}

int main()
{
    vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9}; // some test vector
    vector<int>::iterator numberSearchedFor = binary_search(v.begin(), v.end(), 3);
    if (numberSearchedFor != v.end())
    {
        cout << "Your number is on " << numberSearchedFor - v.begin() << " index." << endl;
    }
    else
    {
        cout << "Your number hasn't been found." << endl;
    }
    return 0;
}
