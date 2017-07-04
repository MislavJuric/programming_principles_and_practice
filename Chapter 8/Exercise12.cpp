#include "../../std_lib_facilities.h"

// 12. Improve print_until_s() from §8.5.2. Test it. What makes a good set of test cases? Give reasons. Then, write a
// print_until_ss() that prints until it sees a second occurrence of its quit argument.

void print_until_s(const vector<string>& v, string quit)
{
          for(string s : v)
          {
                    if (s==quit) return;
                    cout << s << '\n';
          }
}

void print_until_ss(const vector<string>& v, string quit)
{
    int count = 0;
          for(string s : v)
          {
                    if (s == quit)
                    {
                        count++;
                        if (count == 2)
                        {
                            return;
                        }
                    }
                    cout << s << '\n';
          }
}

int main()
{
    vector<string> argument {"I", "am", "quit", "quit", "skull"};
    print_until_s(argument, "quit");
}
