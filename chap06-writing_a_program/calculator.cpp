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

double primary()
{
        Token t = ts.get();
        switch (t.kind) {
        case '8':
                return t.value;
        default:
                error("primary expected");
                return 1;
        }
}

int main()
{
        double val = 0;
        std::cout << "Expression: ";
        // Token t = ts.get(); 
        // if (t.kind != '8') {
        //         std::cout << t.kind << '\n';
        // }
        // else {
        //         std::cout << t.value << '\n';
        // }
        // ts.putback(t);
        val = primary();
        std::cout << val << '\n';
        
}
