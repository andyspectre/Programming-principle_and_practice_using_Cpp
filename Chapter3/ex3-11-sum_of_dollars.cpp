// Andrea Cocco 2020
// Chapter 3 Exercise 11

/*
 *      Write a program that prompts the user to enter some number of 
 *      pennies (1-cent coins), nickels (5-cent coins), dimes (10-cent coins), 
 *      quarters (25-cent coins), half dollars (50-cent coins), 
 *      and one-dollar coins (100-cent coins). Query the user separately for the 
 *      number of each size coin. e.g., "How many pennies do you have?"
 *      Make some improvements: if only one of a coin is reported, make the 
 *      output grammatically correct. Also report the sum in dollars and cents, 
 *      i.e., $5.73 instead of 573 cents.
*/

#include<iostream>

int main()
{
        int pennies = 0;
        int nickels = 0;
        int dimes = 0;
        int quarters = 0;
        int half_dollars = 0;
        int one_dollars = 0;    
        int total_cents = 0;

        std::cout << "How many pennies do you have? ";
        std::cin >> pennies;
        std::cout << "How many nickels do you have? ";
        std::cin >> nickels;
        std::cout << "How many dimes do you have? ";
        std::cin >> dimes;
        std::cout << "How many quarters do you have? ";
        std::cin >> quarters;
        std::cout << "How many half-dollars do you have? ";
        std::cin >> half_dollars;
        std::cout << "How many one-dollars do you have? ";
        std::cin >> one_dollars;

        total_cents = pennies*1+nickels*5+dimes*10+quarters
                *25+half_dollars*50+one_dollars*100;
        double cents_to_dollars = total_cents;
        
        if (pennies == 1) {
                std::cout << "\nYou have: " << pennies << " penny.";
        }
        else {
                std::cout << "\nYou have: " << pennies << " pennies.";
        }
        if (nickels == 1) {
                std::cout << "\nYou have: " << nickels << " nickel.";
        }
        else {
                std::cout << "\nYou have: " << nickels << " nickels.";
        }
        if (dimes == 1) {
                std::cout << "\nYou have: " << dimes << " dime.";
        }
        else {
                std::cout << "\nYou have: " << dimes << " dimes.";
        }
        if (quarters == 1) {
                std::cout << "\nYou have: " << quarters << " quarter.";
        }
        else {
                std::cout << "\nYou have: " << quarters << " quarters.";
        }
        if (half_dollars == 1) {
                std::cout << "\nYou have: " << half_dollars << " half_dollar.";
        }
        else {
                std::cout << "\nYou have: " << half_dollars << " half_dollars.";
        }
        if (one_dollars == 1) {
                std::cout << "\nYou have: " << one_dollars << " one_dollar.";
        }
        else {
                std::cout << "\nYou have: " << one_dollars << " one_dollars.";
        }

        std::cout << "\nThe value of all of your coins is $ " 
                << cents_to_dollars/100 << '\n';
        
}
