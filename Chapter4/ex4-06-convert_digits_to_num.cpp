// Andrea Cocco 2020 
// Chapter 4 exercise 6 from the book:
// Programming: principles and practice using C++, 2nd edition
// by Bjarne Stroustrup
// https://www.stroustrup.com/programming.html

/*
        Write a program that converts a digit to its corresponding
        spelled-out value; e.g., the input 7 gives the output seven.
        Have the same program,  using the same input loop, convert
        spelled-out numbers into their digit form; e.g., the input
        seven gives the output 7.
*/

#include<iostream>
#include<vector>

std::vector<std::string> values = {"zero", "one", "two", 
        "three", "four", "five", "six", "seven", "eight", "nine"};

std::string spelled(int digit)
        // Convert a digit to its corresponding spelled-out value
{
        if (0<=digit && digit<=9) {
                return values[digit];
        }
        else {
                return "Error: out of range digit";
        }
}

int digit(std::string spelled)
        // Convert spelled-out numbers into their digit form
{
        for (int i=0; i<values.size(); ++i) {
                if (spelled == values[i]) {
                        return i;
                }
        }
        return 0;
}       

int main()
{
        std::cout << "Enter digits or spelled out numbers" 
                << " between 0 and 9. [quit/exit] to quit.\n";
        int val = 0;
        std::string numbers= " "; 
        bool validinput = true;
        while (validinput) {
                if (std::cin >> val) { 
                        std::cout << val << '\t' << spelled(val) << '\n';
                }
                else { 
                        std::cin.clear();
                        std::cin >> numbers;
                        if (numbers == "quit" or numbers == "exit") {
                               validinput = false;
                        }
                        else {
                               std::cout << numbers << '\t' 
                                       << digit(numbers) << '\n';
                        }
                }
        }
}
