#include "../Headers/std_lib_facilities.h"

/*
    9. Define an Order class with (customer) name, address, data, and vector<Purchase> members. Purchase is a class with a
    (product) name, unit_price, and count members. Define a mechanism for reading and writing Orders to and from a file.
    Define a mechanism for printing Orders. Create a file of at least ten Orders, read it into a vector<Order>, sort it
    by name (of customer), and write it back out to a file. Create another file of at least ten Orders of which about a
    third are the same as in the first file, read it into a list<Order>, sort it by address (of customer), and write it
    back out to a file. Merge the two files into a third using std::merge().
*/

class Purchase
{
    private:
        string name; // product name
        int unit_price;
        int count;
    public:
        Purchase(string name, int unit_price, int count) : name{name}, unit_price{unit_price}, count{count} { }
        Purchase() { }
        friend istream& operator >> (istream& is, Purchase& p);
        friend ostream& operator << (ostream& os, const Purchase& p);
};

class Order
{
    private:
        string name; // customer name
        string address;
        string data;
        vector<Purchase> purchases;
    public:
        Order(string name, string address, string data, vector<Purchase> purchases) : name{name}, address{address}, data{data}, purchases{purchases} { }
        Order() { }
        friend istream& operator >> (istream& is, Order& o);
        friend ostream& operator << (ostream& os, const Order& o);
};

istream& operator >> (istream& is, Purchase& p)
{
    string name;
    int unit_price;
    int count;
    // I'll try to trim this up real nice...
    char braces;
    char comma;
    is >> braces;
    if (braces != '(') // the problem is that my program expects parentheses after each purchase (even after the last one)
                       // so it throws the "Format not valid" error... I'll have to see how to handle it
    {
        error("Format not valid.");
    }
    is >> name;
    is >> comma;
    if (comma != ',')
    {
        error("Format not valid.");
    }
    is >> unit_price;
    is >> comma;
    if (comma != ',')
    {
        error("Format not valid.");
    }
    is >> count;
    is >> braces;
    if (braces != ')')
    {
        error("Format not valid.");
    }
    p.name = name;
    p.unit_price = unit_price;
    p.count = count;
    return is;
}

istream& operator >> (istream& is, Order& o)
{
    string name;
    string address;
    string data;
    string tag;
    is >> tag;
    if (tag != "Name:")
    {
        error("Format not valid.");
    }
    is >> name;
    is >> tag;
    if (tag != "Address:")
    {
        error("Format not valid.");
    }
    getline(is, address);
    is >> tag;
    if (tag != "Data:")
    {
        error("Format not valid.");
    }
    getline(is, data);
    char braces;
    is >> braces;
    if (braces != '{')
    {
        error("Format not valid.");
    }
    Purchase temp;
    char comma;
    while (is >> temp)
    {
        o.purchases.push_back(temp);
    }
    is >> braces;
    if (braces != '}')
    {
        error("Format not valid.");
    }
    o.name = name;
    o.address = address;
    o.data = data;
    return is;
}

ostream& operator << (ostream& os, const Purchase& p)
{
    os << '(';
    os << p.name << ', ' << p.unit_price << ', ' << p.count;
    os << ')';
    return os;
}

ostream& operator << (ostream& os, const Order& o)
{
    os << "Name: " << o.name << '\n';
    os << "Address: " << o.address << '\n';
    os << "Data: " << o.data << '\n';
    os << '{';
    for (int i = 0; i < o.purchases.size(); i++)
    {
        os << o.purchases[i] << ", ";
    }
    os << '}';
    return os;
}

int main()
{
    ifstream ifs{"Exercise9.txt"};
    Order order;
    ifs >> order;
    cout << order << endl;
    return 0;
}
