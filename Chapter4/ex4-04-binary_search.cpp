// Andrea Cocco 2020 
// Chapter 4 exercise 4 from the book:
// Programming: principles and practice using C++, 2nd edition
// by Bjarne Stroustrup
// https://www.stroustrup.com/programming.html

/*
        Write a program to play a numbers guessing game. The user thinks 
        of a number between 1 and 100 and your program asks questions to 
        figure out what the number is (e.g., "Is the number you are thinking
        of less than 50?"). Your program should be able to identify the number 
        after asking no more than seven questions.
*/

#include<iostream>

int main()
{
/*
 *      The problem is to guess the number after asking no more than seven
 *      questions. To do that, we need to use the binary search algorithm.
*/
        int min = 1;
        int max = 100;
        
        std::cout << "Think of a number between 1 and 100" 
                << " and I will try to guess what number that is"
                << " after asking no more than seven questions...\n";
        while (min <= max) {
                int guess = (max+min)/2;
                std::cout << "Is it less than " << guess << "?\n";
                std::string answer = "";
                std::cin >> answer;
                if (answer == "n") {
                        min = guess+1;
                }
                else {
                        max = guess-1;
                }
        }
        std::cout << "Then " << max << " is your number." << '\n'; 
}
