#include "../std_lib_facilities.h"

//9. Create a Library class. Include vectors of Books and Patrons. Include a struct called Transaction. Have it include a Book,
// a Patron, and a Date from the chapter. Make a vector of Transactions. Create functions to add books to the library,
// add patrons to the library, and check out books. Whenever a user checks out a book, have the library make sure that both
// the user and the book are in the library. If they aren’t, report an error. Then check to make sure that the user owes no fees.
//  If the user does, report an error. If not, create a Transaction, and place it in the vector of Transactions.
// Also write a function that will return a vector that contains the names of all Patrons who owe fees.

enum class Month
{
    Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

class Date
{
    public:
        Date(int y, Month m, int d);
        Date();

        int GetYear() const;
        int GetMonth() const;
        int GetDay() const;

    private:
        int year;
        Month month;
        int day;
};

Date::Date(int y, Month m, int d) : year(y), month(m), day(d) {} // better to have it inline in class body or no?
Date::Date()
{
    year = 1997;
    month = Month::Jan;
    day = 1;
}

enum class Genre
{
    Fiction = 1, Nonfiction, Periodrical, Biography, Children
};

class Book
{
    public:
        Book(string ISBN, string title, Genre genre, string author, string copyright_date, bool is_checked_out);

        string GetISBN() const;
        string GetTitle() const;
        Genre GetGenre() const;
        string GetAuthor() const;
        string GetCopyrightDate() const;
        bool GetIsCheckedOut() const;

        void ChangeIsCheckedOut();
    private:
        string ISBN;
        string title;
        Genre genre;
        string author;
        string copyright_date; // could go with the above Date class
        bool is_checked_out;
        bool operator == (const Book& b);
        bool operator != (const Book& b);
        friend ostream& operator << (ostream& os, const Book& b);
};

string Book::GetTitle() const
{
    return title;
}

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

Book::Book(string ISBN, string title, Genre genre, string author, string copyright_date, bool is_checked_out) : ISBN(ISBN), title(title), genre(genre), author(author), copyright_date(copyright_date), is_checked_out(is_checked_out)
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

class Patron
{
    public:
        void SetFee();

        string GetName() const;
        int GetLibraryCardNumber() const;
        int GetLibraryFees() const;
    private:
        string name;
        int library_card_number;
        int library_fees;
};

string Patron::GetName() const
{
    return name;
}

int Patron::GetLibraryFees() const
{
    return library_fees;
}

bool UserHasLibraryFees(int library_fees)
{
    if (library_fees > 0)
    {
        return true;
    }
    return false;
}

struct Transaction
{
    Transaction (Book b, Patron p) : book(b), patron(p) {}

    Book book;
    Patron patron;
    Date date;
};

class Library
{
    public:
        vector<Patron> GetPatrons() const;

        void AddBook (Patron patron, Book book);
        void AddPatron (Patron patron);
        void CheckOutBook (Book book);

    private:
        vector<Book> books;
        vector<Patron> patrons;
        vector<Transaction> transactions;
};

vector<Patron> Library::GetPatrons() const
{
    return patrons;
}

void Library::AddBook (Patron patron, Book book)
{
    bool patronFound = false;
    for (Patron p : patrons)
    {
        if (p.GetName() == patron.GetName())
        {
            patronFound = true;
        }
    }
    bool bookFound = false;
    for (Book b : books)
    {
        if (b.GetTitle() == book.GetTitle())
        {
            bookFound = true;
        }
    }
    if ((bookFound == false) || (patronFound == false))
    {
        error("Book or patron not found.");
    }
    if (patron.GetLibraryFees() > 0)
    {
        error("Your library fees are greater than 0.");
    }
    Transaction transaction{book, patron};
    transactions.push_back(transaction);
}

vector<Patron> PatronsWhoOweAFee()
{
    Library lib;
    vector<Patron> allPatrons = lib.GetPatrons();
    vector<Patron> toReturn;
    for (Patron p : allPatrons)
    {
        if (p.GetLibraryFees() > 0)
        {
            toReturn.push_back(p);
        }
    }
    return toReturn;
}

int main()
{
    Book myBook{"192-168-1-1", "Internet basics", Genre::Nonfiction , "Some author", "23-12-2014", false};
    cout << myBook << endl;
}
