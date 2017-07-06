#include "../Headers/std_lib_facilities.h"

// 5. Write a function, string cat_dot(const string& s1, const string& s2), that concatenates two strings with a dot in between.
// For example, cat_dot('Niels', 'Bohr') will return a string containing Niels.Bohr.

string cat_dot(const string& s1, const string& s2)
{
    string result;
    result += s1;
    result += '.';
    result += s2;
    return result;
}

int main()
{
    string result = cat_dot("Niels", "Bohr");
    cout << result << endl;
    return 0;
}
