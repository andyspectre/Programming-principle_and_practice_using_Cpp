// Andrea Cocco 2020 
// Chapter 6 exercise 3 
// Programming: principles and practice using C++, 2nd edition
// by Bjarne Stroustrup
// https://www.stroustrup.com/programming.html

/*
 *  Add a factorial operator: use a suffix "!" operator to represent "factorial"
*/ 

#include<iostream>

class Token {
public:
        char kind;        // what kind of Token
        double value;     // for numbers: a value
};

class Token_stream {    // a "stream" of Tokens
public:
        Token get();    // get a Token
        void putback(Token t);    // put a Token back in to the Token stream
private:
        bool full{false};    // is there a Token in the buffer?
        Token buffer;        // here is where we keep a Token using putback()
};

void error(std::string s)
{
        throw std::runtime_error(s);
}

void Token_stream::putback(Token t)
{
        if (full) {
                error("Buffer already full");
        }
        full = true;
        buffer = t;
}

Token Token_stream::get()
{
        if (full) {
                full = false;
                return buffer;
        }
        char ch;
        std::cin >> ch;

        switch (ch) {
        case 'p':       // for print 
        case 'q':       // for quit
        case '{': case '}': case '(': case ')': case '+': case '-': 
        case '*': case '/': case '!':
                return Token{ch};
        case '.':
        case '0': case '1': case '2': case '3': case '4': case '5':
        case '6': case '7': case '8': case '9':
        {        std::cin.putback(ch);        // put digit back into input stream
                 double val;
                 std::cin >> val;
                 return Token{'8',val};
        }
        default:
                error("Bad Token");
                return Token{'e',1};
        }
}

Token_stream ts;        // provides get() and putback()      

double expression();    // declaration so that primary() can call expression()

double primary()
{
        Token t = ts.get();
        switch (t.kind) {
        case '8':
        {
                double val = t.value;
                t = ts.get();
                if (t.kind == '!') {        // handle factorial
                        int fact = 1;

                        if (val < 0) {
                                error("cant find factorial for negative numbers");
                        }
                        else if (val <= 1) {
                                return fact;
                        }
                        else {
                                for (int i = val; i>=2; --i) {
                                        fact = fact*i;
                                }
                                return fact; 
                        }
                }
                else {
                        ts.putback(t);
                        return val;
                }
        }
        case '(':        // handle '(' Expression ')'
        {
                double x = expression();
                t = ts.get();
                if (t.kind != ')') {
                        error("expected a closing round bracket");
                }
                return x;
        }
        case '{':
        {
                double x = expression();
                t = ts.get();
                if (t.kind != '}') {
                        error("expected a closing curly bracket");
                }
                return x;
        }
        default:
                error("primary expected");
                return 1;
        }
}

double term()
{
        double x =  primary();
        Token t = ts.get();        // get the next Token from the Token stream

        while (true) {
                switch (t.kind) {
                case '*':
                        x *= primary();        // handle Term '*' Primary
                        t = ts.get();
                        break;
                case '/':
                {
                        double d = primary();    // handle Term '/' Primary
                        if (d == 0) {
                                error("divide by zero");
                        }
                        x /= d;
                        t = ts.get();
                        break;
                }
                default:
                        ts.putback(t);    // put t back into the Token stream
                        return x;
                }
        }
        return 1;
}

double expression()
{
        double x = term();
        Token t = ts.get();        // get the next Token from the Token stream

        while (true) {
                switch (t.kind) {
                case '+':        // handle Expression '+' Term
                        x += term();
                        t = ts.get();
                        break;
                case '-':        // handle Expression '-' Term
                        x -= term();
                        t = ts.get();
                        break;
                default:
                        ts.putback(t);    // put t back into the Token stream
                        return x;
                }
        }
}


int main()
try{
        double val = 0;
        while (std::cin) {
                Token t = ts.get();
                
                if (t.kind == 'q') {
                        break;
                }
                if (t.kind == 'p') {
                        std::cout << '=' << val << '\n';
                }
                else {
                        ts.putback(t);
                }
                val = expression();
        }
        return 0;
}

catch (std::runtime_error& e) {
        std::cerr << "runtime error: " << e.what() << '\n';
        return 1;
}
