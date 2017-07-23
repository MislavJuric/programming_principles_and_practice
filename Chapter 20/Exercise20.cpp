#include "../Headers/std_lib_facilities.h"
#include <chrono>

// 20. Run a small timing experiment to compare the cost of using vector and list. You can find an explanation of how to time a
// program in §26.6.1. Generate N random int values in the range [0:N). As each int is generated, insert it into a vector<int>
// (which grows by one element each time). Keep the vector sorted; that is, a value is inserted after every previous value that is
// less than or equal to the new value and before every previous value that is larger than the new value. Now do the same
// experiment using a list<int> to hold the ints. For which N is the list faster than the vector? Try to explain your result.
// This experiment was first suggested by John Bentley.



int main()
{
    constexpr int N = 1500;
    vector<int> vec;
    list<int> l;
    auto t1 = std::chrono::system_clock::now();                   // begin time
    bool inserted = false;
    for (int i = 0; i < N; i++)
    {
        int random = randint(0, N);
        for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        {
            if (*it > random)
            {
                vec.insert(it, random);
                inserted = true;
                break;
            }
        }
        if (inserted != true)
        {
            vec.push_back(random);
        }
        inserted = false;
    }
    auto t2 = std::chrono::system_clock::now();                    // end time
    cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds" << endl;
    /*
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    */
    t1 = std::chrono::system_clock::now();                   // begin time
    inserted = false;
    for (int i = 0; i < N; i++)
    {
        int random = randint(0, N);
        for (list<int>::iterator it = l.begin(); it != l.end(); it++)
        {
            if (*it > random)
            {
                l.insert(it, random);
                inserted = true;
                break;
            }
        }
        if (inserted != true)
        {
            l.push_back(random);
        }
        inserted = false;
    }
    t2 = std::chrono::system_clock::now();                    // end time
    cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds" << endl;
    return 0;
}
