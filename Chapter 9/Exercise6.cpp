#include "../std_lib_facilities.h"

// 6. Add operators for the Book class. Have the == operator check whether the ISBN numbers are the same for two books.
// Have != also compare the ISBN numbers. Have a << print out the title, author, and ISBN on separate lines.

class Book
{
    public:
        Book(string ISBN, string title, string author, string copyright_date, bool is_checked_out);

        string GetISBN() const;
        string GetTitle() const;
        string GetAuthor() const;
        string GetCopyrightDate() const;
        bool GetIsCheckedOut() const;

        void ChangeIsCheckedOut();
    private:
        string ISBN;
        string title;
        string author;
        string copyright_date; // could go with the above Date class
        bool is_checked_out;
        bool operator == (const Book& b);
        bool operator != (const Book& b);
        friend ostream& operator << (ostream& os, const Book& b);
};

bool Book::operator == (const Book& b)
{
    return (this->ISBN == b.ISBN);
}

bool Book::operator != (const Book& b)
{
    return (this->ISBN != b.ISBN);
}

ostream& operator << (ostream& os, const Book& b)
{
    os << b.title << endl << b.author << endl << b.ISBN;
    return os;
}

bool CheckISBN(string ISBN)
{
    string temp;
    int i = 0;
    for (int j = 0; j < 3; j++) // ISBN looks like n-n-n-x (where n is an integer); hence the 3
    {
        while (ISBN[i] != '-')
        {
            temp += ISBN[i];
            i++;
        }
        for (int z = 0; z < temp.size(); z++)
        {
            if (!isdigit(temp[z]))
            {
                error("Ooops! ISBN must be of type n-n-n-x");
            }
        }
        i++; // skip the '-'
        temp = "";
    }
    char c = ISBN[i];
    if ((!isdigit(c)) && (!isalpha(c)))
    {
        error("Ooops! ISBN must be of type n-n-n-x");
    }
    return true;
}

Book::Book(string ISBN, string title, string author, string copyright_date, bool is_checked_out) : ISBN(ISBN), title(title), author(author), copyright_date(copyright_date), is_checked_out(is_checked_out)
{
    try
    {
        CheckISBN(ISBN);
    }
    catch (runtime_error)
    {
        cout << "Ooops! Looks like our ISBN checker function caught an invalid ISBN." << endl;
    }
}

int main()
{
    Book myBook{"192-168-1-1", "Internet basics", "Some author", "23-12-2014", false};
    cout << myBook << endl;
}
