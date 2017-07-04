#include "../std_lib_facilities.h"

// 14. Design and implement a Money class for calculations involving dollars and cents where arithmetic has to be
// accurate to the last cent using the 4/5 rounding rule (.5 of a cent rounds up; anything less than .5 rounds down).
// Represent a monetary amount as a number of cents in a long int, but input and output as dollars and cents, e.g., $123.45.
// Do not worry about amounts that don’t fit into a long int.

// 15. Refine the Money class by adding a currency (given as a constructor argument). Accept a floating-point initializer as 
// long as it can be exactly represented as a long int. Don’t accept illegal operations. For example, Money*Money doesn’t 
// make sense, and USD1.23+DKK5.00 makes sense only if you provide a conversion table defining the conversion factor between 
// U.S. dollars (USD) and Danish kroner (DKK).

// 16. Define an input operator (>>) that reads monetary amounts with currency denominations, such as USD1.23 and DKK5.00, 
// into a Money variable. Also define a corresponding output operator (>>).

class Money
{
    public:
        Money (double amount, string currency);
        Money() : number_of_cents(0), currency("HRK") {}

        long int get_number_of_cents() const { return number_of_cents; };
        string get_currency() const { return currency; }
        friend istream& operator >> (istream &is, Money& m);
    private:
        string currency;
        long int number_of_cents;
};

Money::Money(double amount, string currency)
{
    int dollars = amount;
    double cents = amount - dollars;
    int to_ret_d = dollars * 100;
    if (cents >= 0.5)
    {
        to_ret_d++; // rounds the cents up to a full dollar (if they are roundable)
    }
    this->number_of_cents = to_ret_d;
    this->currency = currency;
}

ostream& operator << (ostream& os, const Money& m)
{
    os << m.get_currency() << " " << m.get_number_of_cents();
    return os;
}

istream& operator >> (istream &is, Money& m)
{
    is >> m.currency >> " " >> m.number_of_cents; // does it mean I require space in my input operations?
    return is;
}

int main()
{
    Money test;
    cin >> test;
    cout << test << endl;
    return 0;
}
