#include "../Headers/std_lib_facilities.h"

// 2. Get the Jack-and-Jill example from §20.1.2 to work. Use input from a couple of small files to test it.

double* get_from_jack(int* count);  // Jack puts doubles into an array and
                                                                       // returns the number of elements in *count
vector<double>* get_from_jill();      // Jill fills the vector

double* get_from_jack(int* count)
{
    constexpr int nrOfInputs = 10;
    ifstream ifs{"Jack.txt"};
    *count = nrOfInputs;
    double* arr = new double[nrOfInputs];
    for (int i = 0; i < nrOfInputs; i++)
    {
        ifs >> arr[i];
    }
    return &arr[0];
}

vector<double>* get_from_jill()
{
    constexpr int nrOfInputs = 10;
    vector<double>* toReturn = new vector<double>;
    ifstream ifs{"Jill.txt"};
    for (int i = 0; i < nrOfInputs; i++)
    {
        int toPushBack = 0;
        ifs >> toPushBack;
        toReturn->push_back(toPushBack);
    }
    return toReturn;
}

double* high(double* first, double* last)
// return a pointer to the element in [first,last) that has the highest value
{
          double h = -1;
          double* high;
          for(double* p = first; p!=last; ++p)
                    if (h<*p) { high = p; h = *p; }
          return high;
}

void fct()
{
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);
    vector<double>* jill_data = get_from_jill();
    // . . .
    double* jack_high = high(jack_data,jack_data+jack_count);
    vector<double>& v = *jill_data;
    double* jill_high = high(&v[0],&v[0]+v.size());
    cout << "Jills max: " << *jill_high << "; Jacks max: " << *jack_high;
    // . . .
    delete[] jack_data;
    delete jill_data;
}

int main()
{
    fct();
    return 0;
}
