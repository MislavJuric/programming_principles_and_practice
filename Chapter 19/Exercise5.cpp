#include "../Headers/std_lib_facilities.h"

// 5. Define a class Int having a single member of class int. Define constructors, assignment, and operators +, –, *, / for it.
// Test it, and improve its design as needed (e.g., define operators << and >> for convenient I/O).

class Int
{
    private:
        int val;
    public:
        Int() { }
        Int(int val) : val{val} {  }
        int getVal() const { return val; }
        void setVal(int valArg) { val = valArg; }
        // I need critique on my copy constructor, copy assignment, move constructor and move assignment
        Int(const Int& arg) : val{arg.getVal()} {  } // copy constructor
        Int& operator = (const Int& rhs) // copy assignment
        {
            setVal(rhs.getVal());
            //if (this != rhs)
            //{
                // I don't think I should do anything here... Memory isn't allocated on heap
            //}
            return *(this);
        }
        Int (const Int&& arg) : val{arg.getVal()} { } // move constructor
        Int& operator= (const Int&& arg) // move assignment
        {
            val = arg.getVal(); // use std::move here
            return *this;
        }
        friend Int operator + (const Int& arg1, const Int& arg2);
        friend Int operator - (const Int& arg1, const Int& arg2);
        friend Int operator * (const Int& arg1, const Int& arg2);
        friend Int operator / (const Int& arg1, const Int& arg2);
};

Int operator + (const Int& arg1, const Int& arg2)
{
    Int toReturn;
    toReturn.setVal(arg1.getVal() + arg2.getVal());
    return toReturn;
}

Int operator - (const Int& arg1, const Int& arg2)
{
    Int toReturn;
    toReturn.setVal(arg1.getVal() - arg2.getVal());
    return toReturn;
}

Int operator * (const Int& arg1, const Int& arg2)
{
    Int toReturn;
    toReturn.setVal(arg1.getVal() * arg2.getVal());
    return toReturn;
}

Int operator / (const Int& arg1, const Int& arg2)
{
    Int toReturn;
    toReturn.setVal(arg1.getVal() / arg2.getVal());
    return toReturn;
}

istream& operator >> (istream& is, Int& i) // why do overloaded operators always return a reference to themselves?
{
    int val;
    is >> val;
    i.setVal(val);
    return is;
}

ostream& operator << (ostream& os, const Int& i)
{
    os << i.getVal();
    return os;
}

int main()
{
    Int n1{2};
    Int n2{3};
    cout << (n1 + n2) << endl;
    // error: cannot bind 'std::ostream {aka std::basic_ostream<char>}' lvalue to 'std::basic_ostream<char>&&'
    return 0;
}
