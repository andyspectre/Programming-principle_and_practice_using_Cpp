// Andrea Cocco 2020 
// Chapter 3 exercise 10 from the book:
// Programming: principles and practice using C++, 2nd edition
// by Bjarne Stroustrup
// https://www.stroustrup.com/programming.html

/*
 *      Write a program that takes an operation followed by two operands 
 *      and outputs the result. Read the operation into a 
 *      string called "operation" and use an if-statement to figure out
 *      which operation the user wants. Read the operands into 
 *      variables of type double. Implement this for operations called 
 *      "+, -, *, /, plus, minus, mul, and div" with their obvious meaning.
*/

#include<iostream>

int main()
{
        std::string operation = " ";
        double x = 0.0;
        double y = 0.0;
        double result = 0.0;

        std::cout << "Enter an operation symbol: +, -, *, /," 
                << " followed by two operands and press 'enter': ";
        while (std::cin >> operation >> x >> y) {
                if (operation == "+") {
                        result = x+y;
                }
                else if (operation == "-") {
                        result = x-y;
                        std::cout << "Result: " << result << '\n';
                }
                else if (operation == "*") {
                        result = x*y;
                        std::cout << "Result: " << result << '\n';
                }
                else if (operation == "/") {
                        result = x/y;
                        std::cout << "Result: " << result << '\n';
                }
                else {
                        std::cout << "Invalid operation.\n";
                }
                std::cout << "Enter an operation symbol: +, -, *, /," 
                        << " followed by two operands and press 'enter': ";
        }       
}
