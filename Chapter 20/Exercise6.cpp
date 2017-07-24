#include "../Headers/std_lib_facilities.h"

using Line = vector<char>;             // a line is a vector of characters

// 6. Write a find-and-replace operation for Documents based on §20.6.2.

class Text_iterator// keep track of line and character position within a line
{
        list<Line>::iterator ln;
        Line::iterator pos;
    public:
        // start the iterator at line ll’s character position pp:
        Text_iterator(list<Line>::iterator ll, Line::iterator pp)
                :ln{ll}, pos{pp} { }

        char& operator*() { return *pos; }
        Text_iterator& operator++();

        bool operator==(const Text_iterator& other) const
                { return ln==other.ln && pos==other.pos; }
        bool operator!=(const Text_iterator& other) const
                { return !(*this==other); }
};

namespace std
{
    template<>
    struct iterator_traits<Text_iterator>
    {
        typedef ptrdiff_t          difference_type;
        typedef char               value_type;
        typedef char*              pointer;
        typedef char&              reference;
        typedef input_iterator_tag iterator_category;
    };
}

Text_iterator& Text_iterator::operator++()
{
    ++pos;                                       // proceed to next character
    if (pos==(*ln).end())
    {
        ++ln;                                // proceed to next line
        pos = (*ln).begin();       // bad if ln==line.end(); so make sure it isn’t
    }
    return *this;
}

struct Document {
          list<Line> line;                        // a document is a list of lines
          Document() { line.push_back(Line{}); }
          Text_iterator begin()               // first character of first line
                    { return Text_iterator(line.begin(), (*line.begin()).begin()); }
          Text_iterator end()                 // one beyond the last character of the last line
          {
                    auto last = line.end();
                    --last;          // we know that the document is not empty
                    return Text_iterator(last, (*last).end());
          }
};

istream& operator>>(istream& is, Document& d)
{
    for (char ch; is.get(ch); )
    {
        d.line.back().push_back(ch);         // add the character
        if (ch=='\n')
            d.line.push_back(Line{});     // add another line
    }
    if (d.line.back().size()) d.line.push_back(Line{});    // add final empty line
    // above line? what does it do?
    return is;
}

void erase_line(Document& d, int n)
{
          if (n<0 || d.line.size()-1<=n) return;
          auto  p = d.line.begin();
          advance(p,n);
          d.line.erase(p);
}


void print(Document& d)
{
          for (auto p : d) cout << p;
}

bool match(Text_iterator first, Text_iterator last, const string& s)
{
    Text_iterator iter = first;
    bool isMatch = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (*iter != s[i])
        {
            isMatch = false;
            break;
        }
        ++iter;
    }
    return isMatch;
}

Text_iterator find_txt(Text_iterator first, Text_iterator last, const string& s)
{
          if (s.size()==0) return last;      // can’t find an empty string
          char first_char = s[0];
          while (true) {
                    auto p = find(first,last,first_char);
                    if (p==last || match(p,last,s)) return p;
                    first = ++p;                     // look at the next character
          }
}

//-----------------------------Exercise 6----------------------------------

void find_and_replace(Text_iterator first, Text_iterator last, const string& stringToLookFor, const string& stringToReplaceWith)
{
    if (stringToLookFor.size() == 0) return;
    char first_char = stringToLookFor[0];
    Text_iterator firstOccurence;
    while (true)
    {
        auto p = find(first, last, first_char);
        if (match(p, last, s))
        {
            firstOccurence = p;
        }
        if (p == last)
        {
            // error("Your string couldn't be found.");
        }
        first = ++p;
    }
    for (int i = 0; i < stringToLookFor.size(); i++)
    {
        Text_iterator it = firstOccurence;
        // this needs to work even if the string I'm replacing it with is smaller and if it is bigger
        if (stringToLookFor.size() == stringToReplaceWith.size())
        {
            for (int j = 0; j < stringToLookFor.size(); j++)
            {
                *it = stringToReplaceWith[j];
                it++;
            }
        }
        else if (stringToReplaceWith.size() < stringToLookFor.size())
        {
            // have to think this one through more...
        }
    }
}

//-----------------------------Exercise 6----------------------------------

int main()
{
    Document d;
    ifstream ifs{"Document.txt"};
    ifs >> d;
    Text_iterator t = find_txt(d.begin(), d.end(), "Darlene");
    cout << *t << endl;
    print(d);
    return 0;
}
