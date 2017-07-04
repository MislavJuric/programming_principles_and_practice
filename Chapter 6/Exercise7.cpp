#include "../Headers/std_lib_facilities.h"

// 7. Write a grammar for bitwise logical expressions. A bitwise logical expression is much like an arithmetic expression
// except that the operators are ! (not), ~ (complement), & (and), | (or), and ^ (exclusive or). Each operator does its
// operation to each bit of its integer operands (see §25.5). ! and ~ are prefix unary operators. A ^ binds tighter than a |
// (just as * binds tighter than +) so that x|y^z means x|(y^z) rather than (x|y)^z. The & operator binds tighter than ^ so
// that x^y&z means x^(y&z).

/*
    The grammar for bitwise logical operations (this might not be 100% accurate):

    Expression (handles |):
        Expression
        Expression | Term1
    Term1 (handles ^):
        Term1
        Term1 ^ Term2
    Term2 (handles &):
        Term2
        Term2 & Primary
    Primary (handles ! and ~):
        integer
        !integer
        ~integer
*/

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case ';':    // for "print"
    case 'q':    // for "quit"
    case '(': case ')': case '!': case '~': case '&': case '|': case '^':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case'8': case '9':
        {
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token('8',val);   // let '8' represent "a number"
        }
    default:
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback()

//------------------------------------------------------------------------------

int expression();    // declaration so that primary() can call expression()
int primary();

//------------------------------------------------------------------------------

// deal with numbers, parentheses, ! and ~
int primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {
            int d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    case '!':
    {
        int d = expression();
        return !d;
    }
    case '~':
    {
        int d = expression();
        return ~d;
    }

    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with &
int term2()
{
    int left = primary();
    Token t = ts.get();
    switch (t.kind)
    {
        case '&':
        {
            int right = primary();
            return left & right;
            break;
        }
        default:
            ts.putback(t);
            return left;

    }
}

//------------------------------------------------------------------------------

// deal with ^
int term1()
{
    int left = term2();
    Token t = ts.get();        // get the next token from token stream

    while(true) { // why while(true) here?
        switch (t.kind) {
        case '^':
        {
            int right = term2();
            return left ^ right;
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
   }
}

//------------------------------------------------------------------------------

// deal with |
int expression()
{
    int left = term1();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch(t.kind) {
        case '|':
        {
            int right = term1();
            return left | right;
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    double val = 0;
    while (cin) {
        cout << "> ";
        Token t = ts.get();

        if (t.kind == 'q') break; // 'x' for quit
        if (t.kind == ';')        // '=' for "print now"
            cout << "=" << val << '\n';
        else
            ts.putback(t);
        val = expression();
    }
	keep_window_open();
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
	keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
	keep_window_open();
    return 2;
}

//------------------------------------------------------------------------------

