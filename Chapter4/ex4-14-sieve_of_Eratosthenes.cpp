// Andrea Cocco 2020 
// Chapter 4 exercise 14 from the book:
// Programming: principles and practice using C++, 2nd edition
// by Bjarne Stroustrup
// https://www.stroustrup.com/programming.html

/*
        Write a program that takes an input value "max" and then
        find all prime numbers from 1 to max.
*/

#include<iostream>
#include<vector>

void sieve(int n)
/*
        To solve this problem I am using an algorithm called: 
        Sieve of Eratosthenes. I am using a boolean vector in which
        prime numbers are true and composite numbers are false.
*/
{
        // First initialize vector with all true values
        std::vector<bool> is_prime(n+1, true);

        // Start from the first prime number: 2
        for (int i = 2; i <= n; ++i) {
                if (is_prime[i]) {
                        std::cout << i << " ";
                        // make every multiple of a prime number false, 
                        // starting from the square of that number.
                        for (int k = i*i; k <= n; k += i) {
                                is_prime[k] = false;
                        }
                }
        }
}

int main()
{
        int n = 0;
        std::cout << "Enter a number n to check the prime numbers from 1 to n: ";
        std::cin >> n;
        sieve(n);
}
