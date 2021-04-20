// Andrea Cocco 2020 
// Chapter 3 exercise 5 from the book:
// Programming: principles and practice using C++, 2nd edition
// by Bjarne Stroustrup
// https://www.stroustrup.com/programming.html

/*
 *      Modify the program above to ask the user to enter a floating-point values
 *      and store them in "double" variables. Compare the outputs of the two programs
 *      for some inputs of your choice.
*/

#include<iostream>

int main()
{
        double val1 = 0;
        double val2 = 0;
        double smaller = 0;
        double larger = 0;
        double sum = 0;
        double difference = 0;
        double product = 0;
        double ratio = 0;
        double remainder = 0;

        std::cout << "Enter two numbers (followed by 'enter'): ";
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
                std::cout <<"\nRatio: " << ratio << '\n';
        }
}
