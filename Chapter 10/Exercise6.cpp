#include "../std_lib_facilities.h"

// 6. Define a Roman_int class for holding Roman numerals (as ints) with a << and >>. Provide Roman_int with an as_int()
// member that returns the int value, so that if r is a Roman_int, we can write
// cout << 'Roman' << r << ' equals ' << r.as_int() << '\n';.

class Roman_int
{
    public:
        Roman_int(int numeral);

        int as_int();
        string int_to_Roman();
        friend istream& operator >> (istream& os, Roman_int& r);
    private:
        int numeral;
};

Roman_int::Roman_int(int numeral) : numeral(numeral) {}

string Roman_int::int_to_Roman()
{
    string toReturn;
    int number = numeral;
    while (number > 0)
    {
        if (number >= 1000)
        {
            toReturn += "M";
            number -= 1000;
        }
        else if (number >= 900)
        {
            toReturn += "CM";
            number -= 900;
        }
        else if (number >= 500)
        {
            toReturn += "D";
            number -= 500;
        }
        else if (number >= 400)
        {
            toReturn += "CD";
            number -= 400;
        }
        else if (number >= 100)
        {
            toReturn += "C";
            number -= 100;
        }
        else if (number >= 90)
        {
            toReturn += "XC";
            number -= 90;
        }
        else if (number >= 50)
        {
            toReturn += "L";
            number -= 50;
        }
        else if (number >= 40)
        {
            toReturn += "XL";
            number -= 40;
        }
        else if (number >= 10)
        {
            toReturn += "X";
            number -= 10;
        }
        else if (number >= 9)
        {
            toReturn += "IX";
            number -= 9;
        }
        else if (number >= 5)
        {
            toReturn += "V";
            number -= 5;
        }
        else if (number >= 4)
        {
            toReturn += "IV";
            number -= 4;
        }
        else if (number >= 1)
        {
            toReturn += "I";
            number -= 1;
        }
    }
    return toReturn;
}

int Roman_int::as_int()
{
    return numeral;
}

ostream& operator << (ostream& os, Roman_int& r)
{
    os << r.int_to_Roman();
    return os;
}

istream& operator >> (istream& is, Roman_int& r) // unos rimskih brojeva bi se mogao napraviti tako da se parsea string koji se unese
{
    is >> r.numeral;
    return is;
}

int main()
{
    Roman_int r {1009};
    cout << r << endl;
    return 0;
}
