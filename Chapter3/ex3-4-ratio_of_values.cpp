// Andrea Cocco 2020
// Chapter 3 Exercise 4

/*
        Write a program that prompts the user to enter two integer values.
        Store these values in "int" variables. Write your program to determine
        the smaller, larger, sum, difference, product, and ratio of these values
        and report them to the user.
*/

#include<iostream>

int main()
{
        int val1 = 0;
        int val2 = 0;
        int smaller = 0;
        int larger = 0;
        int sum = 0;
        int difference = 0;
        int product = 0;
        int ratio = 0;
        int remainder = 0;

        std::cout << "Enter two integer numbers (followed by 'enter'): ";
        std::cin >> val1 >> val2;
        if (val1 > val2) {
                larger = val1;
                smaller = val2;
        }
        else if (val1 < val2) {
                larger = val2;
                smaller = val1;
        }
        else {
                larger = val1;
                smaller = val2;
        }

        sum = val1+val2;
        difference = val1-val2;
        product = val1*val2;
        
        std::cout << "Larger value: " << larger
                <<"\nSmaller value: " << smaller
                <<"\nSum: " << sum
                <<"\nDifference: " << difference
                <<"\nProduct: " << product;
        
        if (val2 == 0) {
                std::cout << "\nRatio: Meaningless";
        }
        else {
                ratio = val1/val2;
                remainder = val1%val2;
                std::cout <<"\nRatio: " << ratio 
                        <<"\nRemainder: " << remainder << '\n';
        }
}

        
