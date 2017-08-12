#include "../Headers/std_lib_facilities.h"

istream& operator >> (istream& is, vector<double>& arg)
{
    double number;
    is >> number;
    arg.push_back(number);
}

template <typename T>
void printVector(const vector<T>& arg)
{
    for (int i = 0; i < arg.size(); i++)
    {
        cout << arg[i] << " ";
    }
    cout << endl;
}

int main()
{
    // 1. Read some floating-point values (at least 16 values) from a file into a vector<double> called vd.
    vector<double> vd;
    ifstream ifs{"Drills-more_vector.txt"};
    for (int i = 0; i < 16; i++)
    {
       ifs >> vd;
    }
    // 2. Output vd to cout.
    printVector<double>(vd);
    // 3. Make a vector vi of type vector<int> with the same number of elements as vd; copy the elements from vd into vi.
    vector<int> vi(vd.size());
    copy(vd.begin(), vd.end(), vi.begin());
    printVector<int>(vi);
    // 4. Output the pairs of (vd[i],vi[i]) to cout, one pair per line.
    for (int i = 0; i < vd.size(); i++)
    {
        cout << vd[i] << " " << vi[i] << endl;
    }
    // 5. Output the sum of the elements of vd.
    double sum = accumulate(vd.begin(), vd.end(), 0.0);
    cout << sum << endl;
    // 6. Output the difference between the sum of the elements of vd and the sum of the elements of vi.
    int sumvi = accumulate(vi.begin(), vi.end(), 0);
    cout << (sum - sumvi) << endl;
    // 7. There is a standard library algorithm called reverse that takes a sequence (pair of iterators) as arguments;
    // reverse vd, and output vd to cout.
    reverse(vd.begin(), vd.end());
    printVector<double>(vd);
    // 8. Compute the mean value of the elements in vd; output it.
    cout << (sum / vd.size()) << endl;
    // 9. Make a new vector<double> called vd2 and copy all elements of vd with values lower than (less than) the mean into vd2.
    vector<double> vd2 (vd.size());
    copy_if(vd.begin(), vd.end(), vd2.begin(), [](int n) { return n < 6; });
    printVector<double>(vd2);
    // 10. Sort vd; output it again.
    sort(vd); // defined in std_lib_facilities.h
    printVector<double>(vd);
    return 0;
}
