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

using std::cin;
using std::cout;

int main()
{
        char n {' '};
        constexpr char c {'0'};    // need this to convert char to int properly
        int x {0};
        
        // input char and output int until quit with 'q'
        while (cin >> n && n != 'q') {
                x = n-c;    // subtract '0' to char for correct conversion to int
                cout << x << '\n';
        }
}
        
