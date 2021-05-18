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
        double result = 0;

        if (a == 0) {        // not quadratic, only one result
                result = -(c/b);
                return result;
        }
        else if (b == 0) {        // incomplete quadratic equation 
                result = -(c/a);
                if (result > 0) {        // results should be + and - 
                        result = sqrt(result);
                }
                else {
                        error("Impossible negative square");
                }
                return result;
        }
        else if (c == 0) {        // incomplete quadratic equation
                result = -(b/a);        // the other result should be 0
                return result;
        }
        else {        // here I only calculate the Delta
                double delta = 0;
                delta = (b*b)-4*(a*c);

                if (delta < 0) {
                        error("The equation does not have real roots");
                }
                return delta;
        }
}

int main()
/*
        This program can be refactored and modified to get both the 
        results of a quadratic equation. Here I only get one result 
        from incomplete quadratic equations and the delta from the 
        complete ones. The easyest way probably would be to change 
        the double function to a void function.
*/
try {
        double a = 0;
        double b = 0;
        double c = 0;
        double x = 0;
        std::cout << "Insert a, b, c" << '\n';
        std::cin >> a >> b >> c;
        if (!std::cin) {
                error("Someting went bad with the read");
        }
        else {
                x = quadratic_eq(a, b, c);
        }
        std::cout << x << '\n';
}
catch (std::runtime_error& e) {
        std::cerr << "runtime error: " << e.what() << '\n';
        return 1;
}
