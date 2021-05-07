// Andrea Cocco 2020 
// Chapter 5 exercise 03 from the book:
// Programming: principles and practice using C++, 2nd edition
// by Bjarne Stroustrup
// https://www.stroustrup.com/programming.html

/*
 *      Absolute zero is the lowest temperature that can be reached; 
 *      it is -273.15°C, or 0 K. The above program, even when corrected, 
 *      will produce erroneous results when given a temperature below this. 
 *      Place a check in the main program that will produce an error if a 
 *      temperature is given below -273.15°C.
*/

#include<iostream>


void error(std::string s)
{
        throw std::runtime_error(s);
}

double ctok(double c)
/*      c is degrees in Celsius. The minimum value is -273.15
 *      which is the absolute zero.
*/
{
        constexpr double abs_zero = -273.15;

        if (c < abs_zero) {
                error("Value lower than absolute zero");
        }
        double k = c - abs_zero;
        return k; 
}

int main()
try {
        std::cout << "Insert temperature value in Celsius: ";
        double c = 0;
        std::cin >> c;
        double k = ctok(c);
        std::cout << c << " degrees Celsius are " << k 
                << " Kelvin" << '\n';
        return 0;
}
catch (std::runtime_error& e) {
        std::cerr << "runtime error: " << e.what() << '\n';
        return 1;
}
