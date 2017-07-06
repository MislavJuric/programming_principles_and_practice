#include "../Headers/std_lib_facilities.h"

// 6. Modify cat_dot() from the previous exercise to take a string to be used as the separator (rather than dot)
// as its third argument.

string cat_dot(const string& s1, const string& s2, const string& separator)
{
    string result;
    result += s1;
    result += separator;
    result += s2;
    return result;
}

int main()
{
    string result = cat_dot("Niels", "Bohr", ",");
    cout << result << endl;
    return 0;
}
