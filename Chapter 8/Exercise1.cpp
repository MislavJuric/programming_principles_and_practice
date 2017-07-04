
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "../../std_lib_facilities.h"

// 1. Modify the calculator program from Chapter 7 to make the input stream an explicit parameter (as shown in §8.5.8),
// rather than simply using cin. Also give the Token_stream constructor (§7.8.2) an istream& parameter so that when we
// figure out how to make our own istreams (e.g., attached to files), we can use the calculator for those.
// Hint: Don’t try to copy an istream.

struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string name): kind(ch), name(name) { }
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { } // buffer(0) possible? Why? Isn't buffer a Token? Is it using the first constructor and passing in just the kind?
    Token_stream(istream& input_stream); // why no shit here?
	Token get();
	void unget(Token t) { buffer=t; full=true; } // is this needed?
    void putback(Token t);
	void ignore(char);
};

// symbols for kinds of tokens
const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char square_root = 's';

Token Token_stream::get()
{
	if (full) { full=false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.putback(ch);
		double val;
		cin >> val;
		return Token(number,val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;
			cin.putback(ch); // I don't understand why we put back the character in the cin?
			if (s == "let") return Token(let); // returns a token which symbolizes the "let" keyword
			if (s == "quit") return Token(name); //huh? doesn't make any sense (maybe it's a logical error inserted)
			if (s == "sqrt") return Token(square_root);
			return Token(name,s); // returns the token with our variable name
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin>>ch)
		if (ch==c) return;
}

void Token_stream::putback(Token t) // I wrote this method body
{
    if (full == true)
    {
        error("Buffer already full");
    }
    else
    {
        buffer = t;
        full = true;
    }
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

double get_value(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ",s);
}

void set_value(string s, double d)
{
	for (int i = 0; i<=names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ",s);
}

bool is_declared(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression(Token_stream& ts);

/*
double mathematical_function()
{
    double result = expression();
    return (sqrt(result));
}
*/

double primary(Token_stream& ts)
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression(ts);
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case '-':
		return - primary(ts);
    case '+':
        return primary(ts);
	case number:
		return t.value;
	case name:
		return get_value(t.name);
    /*
    case square_root:
        return mathematical_function(); // works now (doesn't throw "primary expected" error), but evaluates wrong results
    */
	default:
		error("primary expected");
	}
}

double term(Token_stream& ts)
{
	double left = primary(ts);
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '*':
			left *= primary(ts);
			break;
		case '/':
		{	double d = primary(ts);
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression(Token_stream& ts)
{
	double left = term(ts);
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term(ts);
			break;
		case '-':
			left -= term(ts);
			break;
        /*
        case square_root:
        {
            double d = term();
            return sqrt(d);
        }
        */
		default:
			ts.putback(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error ("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,name);
	double d = expression(ts);
	names.push_back(Variable(name,d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration();
    /*
    case square_root:
        {
            double d = expression();
            return sqrt(d);
        }
    */
	default:
		ts.putback(t); // Instead of putback, there were a lot of ungets... I don't think that would work.
		return expression(ts);
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
    names.push_back(Variable("k", 1000)); // predefined name k - is this OK (maybe I should add a new const)?
	while(true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get();
		if (t.kind == quit) return;
		ts.putback(t);
		cout << result << statement() << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
{
	try {
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >>c&& c!=';');
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin>>c && c!=';');
		return 2;
	}
}
