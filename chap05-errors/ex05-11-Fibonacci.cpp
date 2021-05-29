// Andrea Cocco 2020 
// Chapter 5 exercise 11 from the book:
// Programming: principles and practice using C++, 2nd edition
// by Bjarne Stroustrup
// https://www.stroustrup.com/programming.html

/*
 *      Write a program that writes out the first so many values of the 
 *      Fibonacci series. Find the largest Fibonacci number that fits in an int.
 *      I decided to compute the Fibonacci series implementing a recursive 
 *      function. This can get very slow and can be improved by "memoizing" 
 *      the already computed values.
*/

#include<iostream>

void error(std::string s)
{
        throw std::runtime_error(s);
}

int fib(int n)
{
        if (n == 0) {
                return 0;
        }
        else if (n == 1) {
                return 1;
        }
        else {
                return fib(n-1) + fib(n-2);
        }
}

int main()
try{
        int n = 0;
        std::cout << "Enter a number n to compute the first n numbers of "
                << "the Fibonacci series: ";
        std::cin >> n;
                
        if (!n || n<0) {
                error("Invalid input");
        }

        for (int i = 0; i < n; ++i) {
                std::cout << fib(i) << " ";
        }
        return 0;
}
catch (std::runtime_error& e) {
        std::cerr << "runtime error: " << e.what() << '\n';
        return 1;
}
