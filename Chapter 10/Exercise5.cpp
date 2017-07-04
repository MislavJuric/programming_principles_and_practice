#include "../std_lib_facilities.h"

//5. Write the function print_year() mentioned in §10.11.2.

const int not_a_reading = -7777;       // less than absolute zero
const int not_a_month = -1;

struct Day
{
    vector<double> hour {vector<double>(24,not_a_reading)};
};

struct Month
{                                         // a month of temperature readings
    int month {not_a_month};         // [0:11] January is 0
    vector<Day> day {32};                // [1:31] one vector of readings per day
};

struct Year
{               // a year of temperature readings, organized by month
    int year;                                         // positive == A.D.
    vector<Month> month {12};    // [0:11] January is 0
};

struct Reading
{
    int day;
    int hour;
    double temperature;
};

void end_of_loop(istream& ist, char term, const string& message)
{
          if (ist.fail()) {                // use term as terminator and/or separator
                    ist.clear();
                    char ch;
                    if (ist>>ch && ch==term) return;             // all is fine
                    error(message);
          }
}

istream& operator>>(istream& is, Reading& r)
// read a temperature reading from is into r
// format: ( 3 4 9.7 )
// check format, but don’t bother with data validity
{
    char ch1;
    if (is>>ch1 && ch1!='(')
    {                                // could it be a Reading?
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2;
    int d;
    int h;
    double t;
    is >> d >> h >> t >> ch2;
    if (!is || ch2!=')') error("bad reading");      // messed-up reading
    r.day = d;
    r.hour = h;
    r.temperature = t;
    return is;
}

constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

bool is_valid(const Reading& r)
// a rough test
{
          if (r.day<1 || 31<r.day) return false;
          if (r.hour<0 || 23<r.hour) return false;
          if (r.temperature<implausible_min|| implausible_max<r.temperature)
                    return false;
          return true;
}

int month_to_int(string m)
{
    if (m == "jan")
    {
        return 0;
    }
    else if (m == "feb")
    {
        return 1;
    }
    else if (m == "mar")
    {
        return 2;
    }
    else if (m == "apr")
    {
        return 3;
    }
    else if (m == "may")
    {
        return 4;
    }
    else if (m == "jun")
    {
        return 5;
    }
    else if (m == "jul")
    {
        return 6;
    }
    else if (m == "aug")
    {
        return 7;
    }
    else if (m == "sep")
    {
        return 8;
    }
    else if (m == "oct")
    {
        return 9;
    }
    else if (m == "nov")
    {
        return 10;
    }
    else if (m == "dec")
    {
        return 11;
    }
}

istream& operator>>(istream& is, Month& m)
// read a month from is into m
// format: { month feb . . . }
{
          char ch = 0;
          if (is >> ch && ch!='{')
          {
                    is.unget();
                    is.clear(ios_base::failbit);                  // we failed to read a Month
                    return is;
          }

          string month_marker;
          string mm;
          is >> month_marker >> mm;
          if (!is || month_marker!="month") error("bad start of month");
          m.month = month_to_int(mm);
          int duplicates = 0;
          int invalids = 0;
          for (Reading r; is >> r; ) {
                    if (is_valid(r)) {
                              if (m.day[r.day].hour[r.hour] != not_a_reading)
                                        ++duplicates;
                              m.day[r.day].hour[r.hour] = r.temperature;
                    }
                    else
                              ++invalids;
          }
          if (invalids) error("invalid readings in month",invalids);
          if (duplicates) error("duplicate readings in month", duplicates);
          end_of_loop(is,'}',"bad end of month");
          return is;
}

istream& operator>>(istream& is, Year& y)
// read a year from is into y
// format: { year 1972 . . . }
{
          char ch;
          is >> ch;
          if (ch!='{') {
                    is.unget();
                    is.clear(ios::failbit);
                    return is;
          }

          string year_marker;
          int yy;
          is >> year_marker >> yy;
          if (!is || year_marker!="year") error("bad start of year");
          y.year = yy;

          while(true) {
                    Month m;            // get a clean m each time around
                    if(!(is >> m)) break;
                    y.month[m.month] = m;
          }

          end_of_loop(is,'}',"bad end of year");
          return is;
}

ofstream& print_year(ofstream& ofs, Year& y)
{
    ofs << y.year;
    for (Month m : y.month)
    {
        ofs << m.month;
        for (Day d : m.day)
        {
            for (double hour : d.hour)
            {
                ofs << hour;
            }
        }
    }
}

int main()
{
    // open an input file:
    cout << "Please enter input file name\n";
    string iname;
    cin >> iname;
    ifstream ifs {iname};
    if (!ifs) error("can't open input file",iname);

    ifs.exceptions(ifs.exceptions()|ios_base::badbit);       // throw for bad()

    // open an output file:
    cout << "Please enter output file name\n";
    string oname;
    cin >> oname;
    ofstream ofs {oname};
    if (!ofs) error("can't open output file",oname);

    // read an arbitrary number of years:
    vector<Year> ys;
    while(true) {
              Year y;                  // get a freshly initialized Year each time around
              if (!(ifs>>y)) break;
              ys.push_back(y);
    }
    cout << "read " << ys.size() << " years of readings\n";

    for (Year& y : ys) print_year(ofs,y);
    return 0;
}
