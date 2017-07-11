#include "../Headers/std_lib_facilities.h"

// 3. Write a template class Pair that can hold a pair of values of any type. Use this to implement a simple symbol table like the
// one we used in the calculator (§7.8).

template<typename T, typename U>
class Pair
{
    private:
        // I'll implement this as a dictionary, so here are key, value pairs
        T key;
        U value;
    public:
        Pair(T key, U value) : key{key}, value{value} {  }
        T getKey() { return key; }
        U getValue() { return value; }
        void setKey(T keyArg) { key = keyArg; }
        void setValue(U valueArg) { value = valueArg; }
};

int main()
{
    using PairCharString = Pair<char, string>;
    vector<PairCharString> pairs;
    pairs.push_back(PairCharString{'n', "number"});
    pairs.push_back(PairCharString{'v', "variable"});
    pairs.push_back(PairCharString{'c', "constant"});
    char key = 'v';
    for (int i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].getKey() == key)
        {
            cout << pairs[i].getValue() << endl;
        }
    }
    return 0;
}
