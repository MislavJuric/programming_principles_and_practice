#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. Define template<typename T> struct S { T val; };.


template<typename T> struct S;
template<typename T>
istream& operator >> (istream& is, S<T> &s); // I have to forward declare this
template<typename T>
ostream& operator << (ostream& os, S<T> &s);


template<typename T> struct S
{
    private:
        // 7. Make val private.
        T val;
    public:
        // 2. Add a constructor, so that you can initialize with a T.
        S(T arg) : val{arg} { }
        // 5. Add a function template get() that returns a reference to val.
        T& get();
        const T& get() const;
        // 9. Add a set() function template so that you can change val.
        /*
        void set(T arg)
        {
            val = arg;
        }
        */
        S<T>& operator =(const S<T>& rhs)
        {
            val = rhs.get(); // error: request for member 'get' in 'rhs', which is of non-class type 'const int'
            // what should I return?
            return *this;
        }
        // error: declaration of 'operator=' as non-function (on line 35)
        // error: expected ';' at end of member declaration (on line 35)
        // error: expected unqualified-id before '<' token (on line 35)
        friend istream& operator >> <T>(istream& is, S<T> &s); // note the <T> here
        friend ostream& operator << <T>(ostream& os, S<T> &s);
};

template<typename T>
istream& operator >> (istream& is, S<T> &s)
{
    T value;
    is >> value;
    s = value;
    return is;
}

// 10. Replace set() with an S<T>::operator=(const T&). Hint: Much simpler than §19.2.5.

// error: 'T& operator=(const T&)' must be a nonstatic member function (on line 52)

// 6. Put the definition of get() outside the class.

template<typename T>
T& S<T>::get()
{
    return val;
}

// 11. Provide const and non-const versions of get().

template<typename T>
const T& S<T>::get() const
{
    return val;
}

// error: invalid initialization of reference of type 'std::basic_string<char>&' from expression of type 'const std::basic_string<char>'

// 12. Define a function template<typename T> read_val(T& v) that reads from cin into v.
template<typename T>
void read_val(T& v)
{
    cin >> v;
}


template<typename T>
ostream& operator << (ostream& os, S<T> &s)
{
    os << s.get();
    return os;
}

// 14. Bonus: Define input and output operators (>> and <<) for vector<T>s. For both input and output use a { val, val, val }
// format. That will allow read_val() to also handle the S<vector<int>> variable.

template<typename T>
istream& operator >> (istream& is, vector<T> &vec)
{
    char ch1;
    cin >> ch1;
    if (ch1 != '{')
    {
        // error("Bad format.");
    }
    for (int i;;)
    {
        char comma;
        cin >> i;
        vec.push_back(i);
        cin >> comma;
    }
    cin >> ch1;
    if (ch1 != '}')
    {
        // error("Bad format.");
    }
    return is;
}

template<typename T>
ostream& operator << (ostream& os, vector<T> &vec)
{
    os << "{ ";
    for (int i = 0; i < (vec.size() - 1); i++)
    {
        os << vec[i] << ", ";
    }
    os << vec[vec.size() - 1] << " }";
    return os;
}

int main()
{
    // 3. Define variables of types S<int>, S<char>, S<double>, S<string>, and S<vector<int>>;
    // initialize them with values of your choice.
    S<int> i{3};
    S<char> c{'a'};
    S<double> d{2.02};
    S<string> s{"myString"};
    S<vector<int>> vi{{1, 2, 3, 4, 5}};


    // 4. Read those values and print them.

    /*
    cin >> i;
    cout << i << endl;
    cin >> c;
    cout << c << endl;
    cin >> d;
    cout << d << endl;
    cin >> s;
    cout << s << endl;
    for (int i; i != -1;) // let's consider -1 a terminating number
    {
        cin >> i;
        vi.get().push_back(i);
    }
    for (int i = 0; i < vi.get().size(); i++)
    {
        cout << vi.get()[i] << endl;
    }
    */

    // 8. Do 4 again using get().
    cout << i.get() << endl;
    cout << c.get() << endl;
    cout << d.get() << endl;
    cout << s.get() << endl;
    for (int i = 0; i < vi.get().size(); i++)
    {
        cout << vi.get()[i] << endl;
    }

    // 13. Use read_val() to read into each of the variables from 3 except the S<vector<int>> variable.

    read_val(i);
    read_val(c);
    read_val(d);
    read_val(s);
    return 0;
}
