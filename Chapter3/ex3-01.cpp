// Andrea Cocco 2020 
// Chapter 3 exercise 1 from the book:
// Programming: principles and practice using C++, 2nd edition
// by Bjarne Stroustrup
// https://www.stroustrup.com/programming.html

/*
        Do the "Try this" exercises from this chapter.
        Try this 1: Write out the age in months: read the input in years and multiply by 12
        Try this 2: Simple program to exercise operators
        Try this 3: Detect repeated words
        Try this 4: Testing unsafe ("narrowing") conversions
*/

#include<iostream>
#include<cmath>

int main()
{
        std::string first_name = "???";
        double age = 0.0;

        std::cout << "Enter your first name and age\n";
        std::cin >> first_name >> age;
        std::cout << "Hello, " << first_name << "! (age: "<< age*12 << " months)\n"; //write out age in months
        std::cout << "------------------------------------------\n";
        
/*
        ----------------- 
        Second "Try this"
        -----------------
*/
        std::cout << "Please enter a floating-point value: ";
        double n = 0.0;
        std::cin >> n;
        std::cout << "n == " << n
                << "\nn+1 == " << n+1
                << "\nthree times n == " << 3*n
                << "\ntwice n == " << n+n
                << "\nn squared == " << n*n
                << "\nhalf of n == " << n/2
                << "\nsquare root of n == " << sqrt(n)
                << '\n';
        std::cout << "------------------------------------------\n";
/*
        ----------------- 
        Third "Try this"
        -----------------
*/
        std::string previous = " ";
        std::string current = " ";
        int number_of_words = 0;
        std::cout << "Enter some words (at the end press 'enter'):\n";
        while (std::cin >> current) {
                ++number_of_words;
                if (previous == current) {
                        std::cout << "Word number: " << number_of_words
                                << "\nRepeated word: " << current << '\n';
                }
                previous = current;
        }
        std::cout << "------------------------------------------\n";
        
/*
        ----------------- 
        Fourth "Try this"
        -----------------
*/
        double d = 0;
        std::cout << "Enter a floating point number (followed by 'enter'):\n";
        while (std::cin >> d) {
                int i = d;
                char c = i;
                int i2 = c;
                std::cout << "d == " << d
                        << "i == " << i 
                        << "i2 == " << i2
                        << "char (" << c << ")\n";
        }
}       
