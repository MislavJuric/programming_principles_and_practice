#include "../std_lib_facilities.h"

//13. Design and implement a rational number class, Rational. A rational number has two parts: a numerator and a denominator,
// for example, 5/6 (five-sixths, also known as approximately .83333). Look up the definition if you need to.
// Provide assignment, addition, subtraction, multiplication, division, and equality operators. Also, provide a conversion
// to double. Why would people want to use a Rational class?

class Rational
{
    public:
        Rational(int n, int d) : numerator(n), denominator(d) {}

        int get_numerator() const { return numerator; };
        int get_denominator() const { return denominator; };

        void operator = (const Rational& r)
        {
            numerator = r.numerator;
            denominator = r.denominator;
        }

        operator double() const
        {
            double toReturn = double(this->numerator) / this->denominator;
            return toReturn;
        }

    private:
        int numerator;
        int denominator;
};

int common_denominator(const int& d1, const int& d2)
{
    for (int i = 1; i <= (d1 * d2); i++)
    {
        if (((i % d1) == 0) && ((i % d2) == 0))
        {
            return i;
        }
    }
}

Rational operator + (const Rational& r1, const Rational& r2)
{
    int cd = common_denominator(r1.get_denominator(), r2.get_denominator());
    int r1_multiplier = cd / r1.get_denominator();
    int r2_multiplier = cd / r2.get_denominator();
    int new_r1_numerator = r1_multiplier * r1.get_numerator();
    int new_r2_numerator = r2_multiplier * r2.get_numerator();
    Rational result {(new_r1_numerator + new_r2_numerator), cd};
    return result;
}

Rational operator - (const Rational& r1, const Rational& r2)
{
    int cd = common_denominator(r1.get_denominator(), r2.get_denominator());
    int r1_multiplier = cd / r1.get_denominator();
    int r2_multiplier = cd / r2.get_denominator();
    int new_r1_numerator = r1_multiplier * r1.get_numerator();
    int new_r2_numerator = r2_multiplier * r2.get_numerator();
    Rational result {(new_r1_numerator - new_r2_numerator), cd};
    return result;
}

Rational operator * (const Rational& r1, const Rational& r2)
{
    int new_numerator = r1.get_numerator() * r2.get_numerator();
    int new_denominator = r1.get_denominator() * r2.get_denominator();
    Rational result (new_numerator, new_denominator);
    return result;
}

Rational operator / (const Rational& r1, const Rational& r2)
{
    int new_numerator = r1.get_numerator() * r2.get_denominator();
    int new_denominator = r1.get_denominator() * r2.get_numerator();
    Rational result (new_numerator, new_denominator);
    return result;
}

bool operator == (const Rational& r1, const Rational& r2)
{
    return ((r1.get_numerator() == r2.get_numerator()) && (r1.get_denominator() == r2.get_denominator()));
}

int main()
{
    Rational r1{2, 3};
    Rational r2{5, 6};
    Rational result = r1 + r2;
    double d_result = result;
    cout << d_result << endl;
    return 0;
}
