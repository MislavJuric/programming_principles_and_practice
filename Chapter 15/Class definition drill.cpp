#include "../Headers/std_lib_facilities.h"

// 1. Define a struct Person containing a string name and an int age.

struct Person
{
    // 5. Make the representation of Person private, and provide
    // const member functions name() and age() to read the name and age.
    private:
        string name;
        int age;
    // 4. Give Person a constructor initializing name and age.
    public:
        Person(string name, int age) : name(name), age(age) { }
        string getnName() const { return name; }
        int getAge() const { return age; }
};

// 3. Define an input (>>) and an output (<<) operator for Person;
// read in a Person from the keyboard (cin) and write it out to the screen (cout).

//6. Modify >> and << to work with the redefined Person.

/*
istream& operator>> (istream& is, Person& p)
{
    string name;
    int age;
    is >> name;
    is >> age;
    p.name = name;
    p.age = age;
    return is; // why do I return the input stream?
}

ostream& operator<< (ostream& os, Person& p)
{
    os << p.getName() << " " << p.getAge(); // I take care of endl; in my calling function
    return os;
}

*/

// I have problems with 6. here; I'll get back to this


int main()
{
    // 2. Define a variable of type Person, initialize it with “Goofy” and 63, and write it to the screen (cout).
    Person p{"Goofy", 63};
    cout << p << endl;
    return 0;
}
