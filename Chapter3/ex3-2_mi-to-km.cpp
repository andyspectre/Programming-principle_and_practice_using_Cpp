// Andrea Cocco 2020
// Chapter 3 Exercise 2

/*
        Write a program that converts from miles to kilometers.
        Your program should have a reasonable prompt for the user
        to enter a number of miles.
*/

#include<iostream>

int main()
{
/*
        First define conversion rate (1 mi == 1.609 km). This is actually 
        a constant, in the next chapter we'll study a better way 
        to define constants.
*/
        double mi_to_km = 1.609;        // constant conversion rate                          
        double mi = 0.0;        // initialize mi with 0

        std::cout << "Enter the number of miles (followed by 'enter'):\n";
        std::cin >> mi;
        std::cout << mi << " miles == " << mi*mi_to_km << " km.\n";
}
