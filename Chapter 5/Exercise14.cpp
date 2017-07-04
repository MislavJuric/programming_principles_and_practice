#include "std_lib_facilities.h"

using namespace std;

/*

14. Read (day-of-the-week,value) pairs from standard input. For example:

Click here to view code image

Tuesday 23 Friday 56 Tuesday –3 Thursday 99

Collect all the values for each day of the week in a vector<int>. Write out the values of the seven day-of-the-week vectors.
Print out the sum of the values in each vector. Ignore illegal days of the week, such as Funday, but accept common
synonyms such as Mon and monday. Write out the number of rejected values.

*/

class dayValue
{
    public:
        string day;
        int value;
};

int main()
{
    vector<dayValue> Monday;
    vector<dayValue> Tuesday;
    vector<dayValue> Saturday;
    string day;
    int value = 0;
    int rejected_count = 0;
    cin >> day;
    cin >> value;
    while ((day != "NoDay") && (value != 0)) // custom check
    {
        if (day == "Monday")
        {
            Monday.push_back(dayValue{day, value});
        }
        else if (day == "Tuesday")
        {
            Tuesday.push_back(dayValue{day, value});
        }
        else if (day == "Saturday")
        {
            Saturday.push_back(dayValue{day, value});
        }
        else
        {
            rejected_count++;
        }
        cin >> day;
        cin >> value;
    }
    int sum = 0;
    for (int i = 0; i < Monday.size(); i++)
    {
        cout << Monday[i].value << endl;
        sum += Monday[i].value;
    }
    cout << "Sum for Monday is: " << sum << endl;
    sum = 0;
    for (int i = 0; i < Tuesday.size(); i++)
    {
        cout << Tuesday[i].value << endl;
        sum += Tuesday[i].value;
    }
    cout << "Sum for Tuesday is: " << sum << endl;
    sum = 0;
    for (int i = 0; i < Saturday.size(); i++)
    {
        cout << Saturday[i].value << endl;
        sum += Saturday[i].value;
    }
    cout << "Sum for Saturday is: " << sum << endl;
    cout << "Number of rejected values is: " << rejected_count << endl;
    return 0;
}
