// Andrea Cocco 2020 
// Chapter 5 exercise 05 from the book:
// Programming: principles and practice using C++, 2nd edition
// by Bjarne Stroustrup
// https://www.stroustrup.com/programming.html

/*
 *      Add to the program (n.03) so that it can also convert from 
 *      Kelvin to Celsius.
*/

#include<iostream>


void error(std::string s)
{
        throw std::runtime_error(s);
}

double ctok(double v, char u)
/*      c is degrees in Celsius. The minimum value is -273.15
 *      which is the absolute zero.
*/
{
        constexpr double abs_zero = -273.15;
        double converted_t = 0;

        if (v < abs_zero) {
                error("Value lower than absolute zero");
        }
        if (!(u == 'k' || u == 'K' || u == 'c' || u == 'C')) {
                error("Unit of temperature not supported");
        }

        if (u == 'k' || u == 'K') { 
                converted_t = v + abs_zero;
        }
        else {
                converted_t = v - abs_zero;
        }
        return converted_t; 
}

int main()
try {

        double v = 0;
        double convert_temps = 0;
        char u = ' ';
        char converted = ' ';

        while (true) { 
        std::cout << "Insert temperature value in Celsius [C]"
        << " or Kelvin [K]: ";
                std::cin >> v >> u;

                if (!std::cin) {
                        error("Invalid input");  
                }
                else {
                        convert_temps = ctok(v, u);
                } 
                if (u == 'k' || u == 'K') {
                        converted = 'C';
                }
                else {
                        converted = 'K';
                }

                std::cout << v << " degrees " << u 
                << " are " << convert_temps << " " 
                << converted << '\n';
        }
        return 0;
}
catch (std::runtime_error& e) {
        std::cerr << "runtime error: " << e.what() << '\n';
        return 1;
}
