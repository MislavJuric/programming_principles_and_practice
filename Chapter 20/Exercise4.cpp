#include "../Headers/std_lib_facilities.h"

// 4. Find and fix the errors in the Jack-and-Jill example from §20.3.1 by using STL techniques throughout.

// What errors are here? It compiles fine...

template<typename Iterator>
Iterator high(Iterator first, Iterator last)
          // return an iterator to the element in [first:last) that has the highest value
{
    Iterator high = first;
    for (Iterator p = first; p!=last; ++p)
        if (*high<*p) high = p;
    return high;
}

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

void fct()
{
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);
    vector<double>* jill_data = get_from_jill();

    double* jack_high = high(jack_data,jack_data+jack_count);
    vector<double>& v = *jill_data;
    double* jill_high = high(&v[0],&v[0]+v.size());
    cout << "Jills high " << *jill_high << "; Jacks high " << *jack_high;
    // . . .
    delete[] jack_data;
    delete jill_data;
}


int main()
{
    fct();
    return 0;
}
