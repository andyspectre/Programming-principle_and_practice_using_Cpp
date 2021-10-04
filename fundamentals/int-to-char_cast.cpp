// Andrea Cocco 2020 
// Chapter 6 exercise 9 
// Programming: principles and practice using C++, 2nd edition
// by Bjarne Stroustrup
// https://www.stroustrup.com/programming.html

/*
 *      Write a program that reads digit and composes them into integers.
 *      For example, 123 is read as the characters 1, 2 and 3. The program
 *      should output 123 is 1 hundred and 2 tens and 3 ones. The number
 *      should be output as an int value. Handle numbers with one, two, three
 *      or four digit.
*/

#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::runtime_error;
using std::cerr;

void error(string s) {
        throw runtime_error(s);
}

int main()
try
{
        vector<int> digit;
        vector<string> unit = {" ones ", " tens ", " hundreds ", " thousands "};
        cout <<  "Enter an integer witn no more than " << unit.size()
                << "\ndigit followed by semicolon and a newline: ";
        char ch;
        while (cin >> ch) {
                if (ch < '0' || '9' < ch) break;
                digit.push_back(ch - '0');
        }
        if (digit.size() == 0) error("no digits");
        if (unit.size() < digit.size()) error("Cannot handle that many digits");

        for (int i = 0; i < digit.size(); ++i) {
                cout << char('0' + digit[i]);
        }
        cout << '\n';

        int num = 0;
        for (int i = 0; i < digit.size(); ++i) {
                if (digit[i]) {
                        cout << digit[i] << unit[digit.size()-i-1];
                }
                num = num*10+digit[i];
        }
        cout << "\nthat is " << num << '\n';
}
catch(runtime_error e) {
        cerr << e.what() << '\n';
}
