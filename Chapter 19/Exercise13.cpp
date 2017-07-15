#include "../Headers/std_lib_facilities.h"

// 13. Write a Tracer class where its constructor prints a string and its destructor prints a string. Give the strings as
// constructor arguments. Use it to see where RAII management objects will do their job (i.e., experiment with Tracers as
// local objects, member objects, global objects, objects allocated by new, etc.). Then add a copy constructor and a
// copy assignment so that you can use Tracer objects to see when copying is done.

class Tracer
{
    private:
        string conDesString;
    public:
        Tracer(string arg) { conDesString = arg; cout << conDesString << endl; }
        ~Tracer() { cout << conDesString << endl; }
        string getConDesString() const { return conDesString; }
        void setConDesString(string arg) { conDesString = arg; }
        Tracer(const Tracer& arg) : conDesString{arg.getConDesString()} // copy constructor
        {
            cout << "Copy constructor called."  << endl;
        }
        Tracer& operator = (const Tracer& rhs) // copy assignment
        {
            cout << "Copy assignment called." << endl;
            setConDesString(rhs.getConDesString());
            return *this;
        }
};

int main()
{
    Tracer t1{"Constructor & Destructor string."};
    Tracer t2 = t1;
    Tracer t3{"Con & Desc s 2"};
    t2 = t3;
    Tracer* t4 = new Tracer{"Acer1600"};
    return 0;
}
