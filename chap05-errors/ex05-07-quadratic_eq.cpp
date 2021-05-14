// Andrea Cocco 2020 
// Chapter 5 exercise 07 from the book:
// Programming: principles and practice using C++, 2nd edition
// by Bjarne Stroustrup
// https://www.stroustrup.com/programming.html

/*
 *      Write a program that can calculate x for a quadratic 
 *      equation. Create a function that prints out the roots of a 
 *      quadratic equation, given a, b, c. When the program detects 
 *      an equation with no real roots, have it print out a message.
 *      How do you know that your results are plausible? Can you 
 *      check that they are correct?
*/

#include<iostream>
#include<cmath>
#include<iomanip>

void error(std::string s)
{
        throw std::runtime_error(s);
}

double quadratic_eq(double a, double b, double c)
{
        if (a == 0 || b == 0 || c == 0) {
                error("Not a quadratic equation");
        }

        double delta = 0;
        delta = pow(b, 2)-4*(a*c);

        if (delta < 0) {
                error("The equation does not have real roots");
        }
        return delta;
}

int main()
try {
        double a = 0;
        double b = 0;
        double c = 0;
        double result = 0;
        std::cout << "Insert a, b, c" << '\n';
        std::cin >> a >> b >> c;
        if (!std::cin) {
                error("Someting went bad with the read");
        }
        else {
                result = quadratic_eq(a, b, c);
        }
        std::cout << result << '\n';
}
catch (std::runtime_error& e) {
        std::cerr << "runtime error: " << e.what() << '\n';
        return 1;
}
