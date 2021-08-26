// Andrea Cocco 2020 
// Chapter 6 exercise 9 
// Programming: principles and practice using C++, 2nd edition
// by Bjarne Stroustrup
// https://www.stroustrup.com/programming.html

/*
 *      Write a program that reads digits and composes them into integers.
 *      For example, 123 is read as the characters 1, 2 and 3. The program
 *      should output 123 is 1 hundred and 2 tens and 3 ones. The number
 *      should be output as an int value. Handle numbers with one, two, three
 *      or four digits.
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
try{
        char n {' '};
        constexpr char c {'0'};    // need this to convert char to int properly
        int x {0};
        vector<int> digits;
        vector<string> units {"ones", "tens", "hundreds", "thousands"};

        // input char and output int until quit with 'q'
        while (cin >> n && n != 'q') {
                // input validation
                if ((n < 'q' && n < '0') || (n > '9')) error("invalid input");
                x = n-c;    // subtract '0' to char for correct conversion to int
                digits.push_back(x);
        }
        // scaffolding
        for (int i : digits)
                cout << i;
                cout << '\n';
}
catch(runtime_error e) {
        cerr << e.what() << '\n';
}
