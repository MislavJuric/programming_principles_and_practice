#include "../std_lib_facilities.h"

// 2. Design and implement a Name_pairs class holding (name,age) pairs where name is a string and age is a double.
// Represent that as a vector<string> (called name) and a vector<double> (called age) member. Provide an input operation
// read_names() that reads a series of names. Provide a read_ages() operation that prompts the user for an age for each name.
// Provide a print() operation that prints out the (name[i],age[i]) pairs (one per line) in the order determined by the name
// vector. Provide a sort() operation that sorts the name vector in alphabetical order and reorganizes the age vector to match.
// Implement all “operations” as member functions. Test the class (of course: test early and often).

// 3. Replace Name_pair::print() with a (global) operator << and define == and != for Name_pairs.



class Name_pairs
{
    public:
        // const metode koje dobivaju size vectora (jedino je pitanje kako dobiti pristup samim vektorima?

        void read_names();
        void read_ages();
        // void print();
        void sort();
    private:
        friend ostream& operator<<(ostream& os, const Name_pairs& np);
        friend bool operator == (const Name_pairs& n1, const Name_pairs& n2);
        friend bool operator != (const Name_pairs& n1, const Name_pairs& n2);
        vector<string> name;
        vector<double> age;
};

void Name_pairs::read_names()
{
    string input;
    cin >> input;
    while(input != "NoName")
    {
        name.push_back(input);
        cin >> input;
    }
}

void Name_pairs::read_ages()
{
    for (string s : name)
    {
        cout << "Enter the age for " << s << ":" << endl;
        double input;
        cin >> input;
        age.push_back(input);
    }
}

/*
void Name_pairs::print()
{
    for (int i = 0; i < name.size(); i++)
    {
        cout << name[i] << " " << age[i] << endl;
    }
}
*/

bool operator == (const Name_pairs& n1, const Name_pairs& n2)
{
    return ((n1.name == n2.name) && (n1.age == n2.age));
}

bool operator != (const Name_pairs& n1, const Name_pairs& n2)
{
    return (!((n1.name == n2.name) && (n1.age == n2.age)));
}

ostream& operator<<(ostream& os, const Name_pairs& np)
{
    int name_size = np.name.size();
    for (int i = 0; i < name_size; i++)
    {
        os << np.name[i] << " " << np.age[i] << endl;
    }
    return os;
}

void Name_pairs::sort() // could be more efficient?
{
    vector<string> name_copy = name;
    vector<double> age_copy = age;
    std::sort(name.begin(), name.end());
    for (int i = 0; i < name.size(); i++)
    {
        for (int j = 0; j < name_copy.size(); j++)
        {
            if (name[i] == name_copy[j])
            {
                age[i] = age_copy[j];
            }
        }
    }
}

int main()
{
    Name_pairs test;
    test.read_names();
    test.read_ages();
    cout << test << endl;
    test.sort();
    cout << test << endl;
    return 0;
}
