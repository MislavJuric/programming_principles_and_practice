#include "std_lib_facilities.h"

using namespace std;

// 2. The following program takes in a temperature value in Celsius and converts it to Kelvin.
// This code has many errors in it. Find the errors, list them, and correct the code.

// I corrected the errors.

double ctok(double c)                   // converts Celsius to Kelvin
{
    // 4. Do exercise 3 again, but this time handle the error inside ctok().
    if (c < -273.15)
    {
        error("Temperature must not be lower than -273.15");
    }
    double k = c + 273.15;
    return k;
}

// 5. Add to the program so that it can also convert from Kelvin to Celsius.

// 6. Write a program that converts from Celsius to Fahrenheit and from Fahrenheit to Celsius (formula in §4.3.3).
// Use estimation (§5.8) to see if your results are plausible.

// Exercise 6 is just handeled by doing these things inside main() (or calling the appropriate functions)

double fromKelvinToCelsius(double kelvinTemp)
{
    return (kelvinTemp - 273.15);
}

int main()
{
    // 3. Absolute zero is the lowest temperature that can be reached; it is –273.15°C, or 0K. The above program,
    // even when corrected, will produce erroneous results when given a temperature below this. Place a check in the
    // main program that will produce an error if a temperature is given below –273.15°C.
    try
    {
        double c = 0;                         // declare input variable
        cin >> c;                    // retrieve temperature to input variable
        /*
        if (c < 273.15)
        {
            error("Temperature can't be lower than 273.15");
        }
        */
        double k = ctok(c);           // convert temperature
        cout << k << '/n' ;                 // print out temperature
    }
    catch (runtime_error)
    {
        cout << "Temperature is lower than -273.15" << endl;
    }
}
