#include "../std_lib_facilities.h"

//3. Write a program that reads the data from raw_temps.txt created in exercise 2 into a vector and then calculates the mean
// and median temperatures in your data set. Call this program temp_stats.cpp.

const string filename = "raw_temps.txt";

struct Reading                 // a temperature reading
{
    int hour;                  // hour after midnight [0:23]
    char unit;
    double temperature;        // in Fahrenheit
};

istream& operator >> (istream& is, Reading& r)
{
    int hour;
    char unit;
    double temperature;
    is >> hour >> unit >> temperature;
    r.hour = hour;
    r.unit = unit;
    r.temperature = temperature;
    return is;
}

int main()
{
    ifstream ist {filename};
    vector<Reading> readings;
    for (Reading r; ist >> r;)
    {
        readings.push_back(r);
    }
    for (Reading r : readings)
    {
        cout << r.hour << r.unit << " " << r.temperature << endl;
    }
    double sum = 0;
    vector<double> temps;
    // 4. Modify the store_temps.cpp program from exercise 2 to include a temperature suffix c for Celsius or f for Fahrenheit
    // temperatures. Then modify the temp_stats.cpp program to test each temperature, converting the Celsius readings to
    // Fahrenheit before putting them into the vector.
    for (Reading r : readings)
    {
        double to_add = r.temperature;
        if (r.unit == 'c')
        {
            to_add = (to_add * (9/5)) + 32;
        }
        sum += r.temperature;
        // workaround za sort
        temps.push_back(r.temperature);
    }
    double mean = sum / readings.size();
    sort(temps.begin(), temps.end());
    double median = temps[temps.size() / 2];
    cout << "Mean is: " << mean << endl;
    cout << "Median is: " << median << endl;
    return 0;
}
