#include "../Headers/std_lib_facilities.h"

// 7. Try your solution to exercise 2 with some Numbers.

template<typename T>
class Number
{
    private:
        T value;
    public:
        Number() {}
        Number(T valArg) : value{valArg} {  }
        T getValue() const { return value; }
        void setValue(T valArg) { value = valArg; }
        Number (const Number& arg) : value{arg.getValue()} { } // copy constructor
        Number& operator = (const Number& rhs) // copy assignment
        {
            setValue(rhs.getValue());
            return *this;
        }
        Number (const Number&& arg) : value{move(arg.getValue())} {  } // move constructor
        Number& operator = (const Number&& arg)
        {
            value = move(arg.getValue());
            return *this;
        }
};

template<typename T>
Number<T> operator + (const Number<T>& arg1, const Number<T>& arg2)
{
    Number<T> toReturn;
    toReturn.setValue(arg1.getValue() + arg2.getValue());
    return toReturn;
}

template<typename T>
Number<T> operator - (const Number<T>& arg1, const Number<T>& arg2)
{
    Number<T> toReturn;
    toReturn.setValue(arg1.getValue() - arg2.getValue());
    return toReturn;
}

template<typename T>
Number<T> operator * (const Number<T>& arg1, const Number<T>& arg2)
{
    Number<T> toReturn;
    toReturn.setValue(arg1.getValue() * arg2.getValue());
    return toReturn;
}

template<typename T>
Number<T> operator / (const Number<T>& arg1, const Number<T>& arg2)
{
    Number<T> toReturn;
    toReturn.setValue(arg1.getValue() / arg2.getValue());
    return toReturn;
}

template<typename T>
Number<T> operator % (const Number<T>& arg1, const Number<T>& arg2)
{
    Number<T> toReturn{arg1.getValue() % arg2.getValue()};
    return toReturn;
}

template<typename T>
istream& operator >> (istream& is, Number<T>& i) // why do overloaded operators always return a reference to themselves?
{
    Number<T> val;
    is >> val;
    i.setValue(val);
    return is;
}

template<typename T>
ostream& operator << (ostream& os, const Number<T>& i)
{
    os << i.getValue();
    return os;
}

template<typename T, typename U>
U f(vector<T> vt, vector<U> vu)
{
    if (vt.size() != vu.size())
    {
        error("Vectors are not the same size.");
    }
    U toReturn = 0;
    for (int i = 0; i < vt.size(); i++)
    {
        toReturn = toReturn + (vt[i] * vu[i]);
     }
    return toReturn;
}

int main()
{
    vector<Number<int>> v1 {Number<int> {2}, Number<int> {3}};
    vector<Number<int>> v2 {Number<int> {4}, Number<int> {5}};
    Number<int> sum = f(v1, v2);
    cout << sum << endl;
    return 0;
}
