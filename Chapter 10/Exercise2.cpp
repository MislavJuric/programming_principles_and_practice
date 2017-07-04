#include "../std_lib_facilities.h"

//2. Write a program that creates a file of data in the form of the temperature Reading type defined in §10.5.
// For testing, fill the file with at least 50 “temperature readings.” Call this program store_temps.cpp and the file it
// creates raw_temps.txt.

const string filename = "raw_temps.txt";
const int number_of_loops = 50;

struct Reading
{                              // a temperature reading
    int hour;                  // hour after midnight [0:23]
    char unit;
    double temperature;        // in Fahrenheit
};

ostream& operator << (ostream& os, const Reading& r)
{
    os << r.hour <<  r.unit << " " << r.temperature;
    return os;
}

int main()
{
    srand(time(0));
    char temps[2] {'c', 'f'};
    ofstream ost {filename};
    for (int i = 0; i < number_of_loops; i++)
    {
        Reading r {(rand() % 24), (temps[rand() % 2]), (rand() % 100)};
        ost << r << '\n';
    }
    return 0;
}
