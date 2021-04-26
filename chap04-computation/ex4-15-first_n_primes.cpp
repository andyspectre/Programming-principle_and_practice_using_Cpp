// Andrea Cocco 2020 
// Chapter 4 exercise 15 from the book:
// Programming: principles and practice using C++, 2nd edition
// by Bjarne Stroustrup
// https://www.stroustrup.com/programming.html

/*
        Write a program that takes an input value n 
        and then finds the first n primes.
*/

#include<iostream>
#include<vector>
#include<cmath>

std::vector<int> trial_div(int n)
/*
        Trial division algorithm, optimized by first checking for 
        divisibility by 2 and then starting trial division from 3, 
        checking only odd numbers.
*/
{
        bool is_prime = true;
        int x = 3;        // numbers that will be tested for primality
        std::vector<int> primes;

        if (n >= 1) {
                primes.push_back(2);        // 2 is always the first prime :)
        }

        if (n > 1) {
                for (int i = 2; i <= n;) {        // find n prime numbers
                        // if x is divisible by 2 is not prime
                        if (x%2 == 0) {        
                                is_prime = false;
                        }
                        /*
                                Since we already checked if x is divisible by 2,
                                we only need to check for odd numbers, 
                                up to the sqrt of x. 
                                If x is divisible (by an odd number), 
                                then x is not prime
                        */
                        for (int k = 3; k <= sqrt(x); k+=2) { 
                                if (x%k == 0) {               
                                        is_prime = false;     
                                        break;
                                }
                        }
                        if (is_prime) { // x is prime
                                primes.push_back(x);
                                ++i;
                        }
                        is_prime = true;
                        ++x;
                }
        }
        return primes;
}
                                
        
int main()
{
        int n = 0;
        std::cout << "Enter a number n to check first n prime numbers: ";
        std::cin >> n;
        std::vector<int> first_primes = trial_div(n);
        for (int i : first_primes) {
                std::cout << i << " ";
        }
}
