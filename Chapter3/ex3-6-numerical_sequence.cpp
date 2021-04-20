// Andrea Cocco 2020
// Chapter 3 Exercise 6
/* 
 *      Write a program that prompt the user to enter
 *      three integer values, and then outputs the values
 *      in numerical sequence separated by commas. If two
 *      values are the same, they should just be ordered together.
*/

#include<iostream>

int main()
{
        int val1 = 0;
        int val2 = 0;
        int val3 = 0;
        int smallest = 0;
        int middle = 0;
        int largest = 0;

        std::cout << "Enter three random integers (followed by 'enter'): "; 
        std::cin >> val1 >> val2 >> val3;
        if (val1 <= val2 && val2 <= val3) {
                smallest = val1;
                if (val2 <= val3) {
                        middle = val2;
                        largest = val3;
                }
                else {
                        middle = val3;
                        largest = val2;
                }
        }
        else if (val2 <= val1 && val2 <= val3) {
                smallest = val2;
                if (val1 <= val3) {
                        middle = val1;
                        largest = val3; 
                }
                else {
                        middle = val3;
                        largest = val1;
                }
        }
        else { 
                smallest = val3;
                if (val1 <= val2) {
                        middle = val1;
                        largest = val2;
                }
                else {
                        middle = val2;
                        largest = val1;
                }
        }
        std::cout << "Sorted values: " << smallest << ", " << middle
                << ", " << largest << '\n';
}       

        
