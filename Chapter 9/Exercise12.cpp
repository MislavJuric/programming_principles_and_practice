#include "../std_lib_facilities.h"

//12. Change the representation of a Date to be the number of days since January 1, 1970 (known as day 0), represented as a
// long int, and re-implement the functions from §9.8. Be sure to reject dates outside the range we can represent that way
// (feel free to reject days before day 0, i.e., no negative days).

// Not the best version ever, but it works

enum class Month
{
          jan=0, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date
{
    public:
        class Invalid { };                               // to throw as exception

        Date(int y, Month m, int d);         // check for valid date and initialize
        Date();                                              // default constructor
        // the default copy operations are fine

        // nonmodifying operations:
        long int get_day() const { return day; }

        // modifying operations:
        void add_day(int n);
        void add_month(int n);
        void add_year(int n);
    private:
        long int day;
};

bool is_date(int y, Month m, int d);  // true for valid date
bool leapyear(int y);           // true if y is a leap year

bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);

ostream& operator<<(ostream& os, const Date& d);

istream& operator>>(istream& is, Date& dd);

//-------------------------------------declarations end here------------------------------------------------

//-------------------------------------definitions begin here-----------------------------------------------

bool check_date(int, Month, int);

Date::Date(int yy, Month mm, int dd)
{
        // could be more refined
          if (check_date(yy, mm, dd) == true)
          {
              int y_days = (yy - 1970) * 365;
              int m_days = int(mm) * 30;
              int d_days = dd - 1;
              day = y_days + m_days + d_days;
          }
          else
          {
              error ("Ooops! Looks like your date is invalid!");
          }
}

const int& default_date()
{
          static int dd = 0;
          return dd;
}

Date::Date()
{
    day = default_date();
}

void Date::add_day(int n)
{
          day += n;
}

void Date::add_month(int n)
{
          day += (n * 30);
}

void Date::add_year(int n)
{
    day += (n * 365);
}
// helper functions:

bool check_date(int y, Month m, int d)
{
    // could be more elaborate
          if (y < 1970)
          {
              return false;
          }
          if ((m < Month::jan) || (m > Month::dec))
          {
              return false;
          }
          if ((d < 0) || (d > 31))
          {
              return false;
          }
          return true;
}

bool leapyear(int y)
{

}

bool operator==(const Date& a, const Date& b)
{
          return a.get_day() == b.get_day();
}

bool operator!=(const Date& a, const Date& b)
{
          return !(a==b);
}
ostream& operator<<(ostream& os, const Date& d)
{
          return os << d.get_day();
}

/*
istream& operator>>(istream& is, Date& dd)
{
          int y, m, d;
          char ch1, ch2, ch3, ch4;
          is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
          if (!is) return is;
          if (ch1!= '(' || ch2!=',' || ch3!=',' || ch4!=')') {       // oops: format error
                    is.clear(ios_base::failbit);                            // set the fail bit
          return is;
          }

          dd = Date(y, Month(m),d);                                   // update dd

          return is;
}
*/

enum class Day {
          sunday, monday, tuesday, wednesday, thursday, friday, saturday
};

Day day_of_week(const Date& d)
{
          // . . .
}

Date next_Sunday(const Date& d)
{
          // ...
}

Date next_weekday(const Date& d)
{
          // . . .
}


int main()
{
    try
    {
        Date d {1971, Month::feb, 15};
        cout << d << endl;
    }
    catch (...)
    {
        cout << "Ooops! Something went wrong." << endl;
    }
    return 0;
}
