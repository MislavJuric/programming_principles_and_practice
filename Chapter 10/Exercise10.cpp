/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

// 10. Add a command from x to the calculator from Chapter 7 that makes it take input from a file x. Add a command to y
// to the calculator that makes it write its output (both standard output and error output) to file y. Write a collection
// of test cases based on ideas from §7.3 and use that to test the calculator. Discuss how you would use these commands for
// testing.

#include "../std_lib_facilities.h"

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
const char constant = 'const';
const char help = 'H';
const char from = 'F';

void helpMessage()
{
    cout << "Terminate expressions with ';', enter any expression and declare variables with 'let variable_name = some value'" << endl;
}

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
	// case '\n': // look into this
        // return Token(print);
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s+=ch;
			cin.putback(ch); // I don't understand why we put back the character in the cin?
			if (s == "let") return Token(let); // returns a token which symbolizes the "let" keyword
			if (s == "const") return Token(constant);
			if (s == "quit") return Token(name); //huh? doesn't make any sense (maybe it's a logical error inserted)
			if (s == "sqrt") return Token(square_root);
			if ((s == "h") || (s == "H")) return Token(help);
			if (s == "from") return Token(from);
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
	bool constant;
	Variable(string n, double v, bool c) :name(n), value(v), constant(c) { }
};

Token_stream ts;
double expression();

class Symbol_table
{
    private:
        vector<Variable> names;
    public:
        // function bodies should be declared outside of the class body, like "double Symbol_table::get_value(string s)"
        double get_value(string s)
        {
            for (int i = 0; i<names.size(); ++i)
                if (names[i].name == s) return names[i].value;
            error("get: undefined name ",s);
        }

        void set_value(string s, double d)
        {
            for (int i = 0; i < names.size(); ++i)
                if ((names[i].name == s) && (names[i].constant == false))
                {
                    names[i].value = d;
                    return;
                }
            error("set: Either your name is undefined or you are trying to modify a constant variable");
        }

        bool is_declared(string s)
        {
            for (int i = 0; i<names.size(); ++i)
                if (names[i].name == s) return true;
            return false;
        }
        double declaration(bool constant)
        {
            Token t = ts.get();
            if (t.kind != 'a') error ("name expected in declaration");
            string name = t.name;
            if (is_declared(name))
            {
                /*
                ts.putback(t);
                return assignment();
                */
                error("Name is already declared.");
            }
            Token t2 = ts.get();
            if (t2.kind != '=') error("= missing in declaration of " ,name);
            double d = expression();
            names.push_back(Variable(name,d,constant));
            return d;
        }
        double assignment()
        {
            Token t = ts.get();
            if (t.kind != 'a')
            {
                error("name expected in declaration");
            }
            string name = t.name;
            if (!(is_declared(name)))
            {
                error("Name has to be declared before an assignment");
            }
            Token t2 = ts.get();
            if (t2.kind != '=')
            {
                error("'=' expected");
            }
            double d = expression();
            set_value(name, d);
            return d;
        }
        void add(string s, double d, bool c)
        {
            names.push_back(Variable(s, d, c));
        }
};

Symbol_table variableNames;

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case '-':
		return - primary();
    case '+':
        return primary();
	case number:
		return t.value;
	case name:
		return variableNames.get_value(t.name);
    case help:
        helpMessage();
        break;
    /*
    case square_root:
        return mathematical_function(); // works now (doesn't throw "primary expected" error), but evaluates wrong results
    */
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
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

double expression()
{
	double left = term();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
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

double statement()
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return variableNames.declaration(false);
    case name:
        ts.putback(t);
        return variableNames.assignment();
    case constant:
        return variableNames.declaration(true);
    case from:
    {
        Token t2 = ts.get();
        if (t2.kind != 'a')
        {
            cout << "Name of file stream expected" << endl;
            break;
        }

    }
	default:
		ts.putback(t); // Instead of putback, there were a lot of ungets... I don't think that would work.
		return expression();
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
    variableNames.add("k", 1000, true); // predefined name k - is this OK (maybe I should add a new const)?
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
