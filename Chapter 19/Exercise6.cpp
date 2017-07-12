#include "../Headers/std_lib_facilities.h"

// 6. Repeat the previous exercise, but with a class Number<T> where T can be any numeric type.
// Try adding % to Number and see what happens when you try to use % for Number<double> and Number<Number>.

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

int main()
{
    /*
    Number<double> n1{2.22};
    Number<double> n2{3.33};
    */
    /*
    Number<Number<int>> n1{2};
    Number<Number<int>> n2{3};
    */
    Number<int> n1{2};
    Number<int> n2{3};
    cout << n1 % n2 << endl;
    return 0;
}
