// Andrea Cocco 2020 
// Chapter 6 
// Programming: principles and practice using C++, 2nd edition
// by Bjarne Stroustrup
// https://www.stroustrup.com/programming.html

/*
 *      The program is a calculator that computes arithmetic expressions like:
 *      5+3*2-(9/3+3)
 *      It accepts addition, subtraction, multiplication, division and 
 *      parenthesis for grouping.
 *
 *      Below is the grammar defining the syntax of the input. 
 *      Tokens are in double quotes.
 *      Alternatives are on separate lines:
 *
 *      Expression:
 *           Term
 *           Expression "+" Term     // addition
 *           Expression "-" Term     // subtraction
 *      Term:
 *           Primary
 *           Term "*" Primary        // multiplication
 *           Term "/" Primary        // division
 *      Primary:
 *           Number
 *           "(" Expression ")"      // grouping
 *      Number:
 *           floating-point-literal
*/ 

#include<iostream>

class Token {    // add something 
public:
        char kind;
        double value;
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
        case '(': case ')': case '+': case '-': case '*': case '/':
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

Token_stream ts;       
// Token t = ts.get();

double expression();

double primary()
{
        Token t = ts.get();
        switch (t.kind) {
        case '8':
                return t.value;
        case '(':        // handle '(' Expression ')'
        {
                double x = expression();
                t = ts.get();
                if (t.kind != ')') {
                        error("expected a closing braket");
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
                if (t.kind == 'p') {
                        std::cout << '=' << val << '\n';
                }
                else if (t.kind == 'q') {
                        break;
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
