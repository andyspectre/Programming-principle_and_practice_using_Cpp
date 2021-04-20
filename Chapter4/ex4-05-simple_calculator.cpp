//Andrea Cocco 2020
//Chapter 4 Exercise 5
/*
 *      Write a program that performs as a very simple calculator. Your calculator
 *      should be able to handle the four basic math operations -add, subtract, 
 *      multiply, divide - on two input values. Your program should prompt the user to
 *      enter three arguments: two double values and a character to represent an operation.
 *      If the entry arguments are 35.6, 24.1, and '+', the program output should be 
 *      "The sum of 35.6 and 24.1 is 59.7." In chapter 6 we look at a much more sophisticated
 *      simple calculator.
*/

#include<iostream>

int main()
{
        double a = 0;
        double b = 0;
        char op = ' ';

        std::cout << "Enter two numbers separated by an operator [+, -, *, /].\n";

        while (std::cin >> a >> op >> b) {
                double result = 0;
                std::string operation = "";
                switch (op) {
                case '+':
                        operation = "sum of ";
                        result = a+b;
                        break;
                case '-':
                        operation = "difference between ";
                        result = a-b;
                        break;
                case '*':
                        operation = "product of ";
                        result = a*b;
                        break;
                case '/':
                        operation = "ratio of ";
                        if (b == 0) {
                                std::cout << "Impossible\n";
                        }
                        else {
                                result = a/b;
                        }
                        break;
                default: 
                        std::cout << "Bad operator\n";
                        break;
                }
                std::cout << operation << a << " and " << b << " is " << result << '\n';
                std::cout << "Try again\n";
        }       
}       
