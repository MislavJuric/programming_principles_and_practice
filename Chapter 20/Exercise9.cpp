#include "../Headers/std_lib_facilities.h"

using Line = vector<char>;             // a line is a vector of characters

// 9. Define a program that counts the number of words in a Document. Provide two versions: one that defines word as
// “a whitespace-separated sequence of characters” and one that defines word as “a sequence of consecutive alphabetic
// characters.” For example, with the former definition, alpha.numeric and as12b are both single words, whereas with the
// second definition they are both two words.

class Text_iterator // keep track of line and character position within a line
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


void print(Document& d)
{
          for (auto p : d) cout << p;
}

int countWordsWhitespace(Document& d)
{
    bool hitWhitespace = false;
    int count = 0;
    for (auto p : d)
    {
        if (((p == ' ') && (hitWhitespace == false)) || ((p == '\n') && (hitWhitespace == false)))
        // need to figure out how to count words right next to the end of file
        {
            hitWhitespace = true;
            count++;
        }
        if (p != ' ')
        {
            hitWhitespace = false;
        }
    }
    return count;
}

int countWordsAlphabet(Document& d) // this also isn't counting words properly... gotta get back to this
{
    bool hitNotAlphabet = false;
    int count = 0;
    for (auto p : d)
    {
        if ((!isalpha(p)) && (hitNotAlphabet == false))
        {
            hitNotAlphabet = true;
            count++;
        }
        if (isalpha(p))
        {
            hitNotAlphabet = false;
        }
    }
    return count;
}

int main()
{
    Document d;
    ifstream ifs{"Document.txt"};
    ifs >> d;
    print(d);
    cout << endl;
    cout << countWordsWhitespace(d) << endl;
    cout << countWordsAlphabet(d) << endl;
    return 0;
}
