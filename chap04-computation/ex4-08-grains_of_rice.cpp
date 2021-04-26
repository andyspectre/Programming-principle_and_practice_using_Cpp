// Andrea Cocco 2020 
// Chapter 4 exercise 8 from the book:
// Programming: principles and practice using C++, 2nd edition
// by Bjarne Stroustrup
// https://www.stroustrup.com/programming.html

/*
        There is an old story that the emperor wanted to thank the inventor 
        of the game of chess and asked the inventor to name his reward. 
        The inventor asked for one grain of rice for the first square, 
        2 for the second, 4 for the third, and so on, doubling for each of the 64 squares. 
        That may sound modest, but there wasn’t that much rice in the empire! 
        Write a program to calculate how many squares are required to give 
        the inventor at least 1000 grains of rice, at least 1.000.000 grains,
        and at least 1.000.000.000 grains. 
        You’ll need a loop, of course, and probably an int to keep track 
        of which square you are at, an int to keep the number of grains on the 
        current square, and an int to keep track of the grains on all previous squares. 
        We suggest that you write out the value of all your variables for 
        each iteration of the loop so that you can see what’s going on.
*/

#include<iostream>

int main()
{
        int square = 0;
        int n_grains = 1;
        int n_grains_pre = 1;

        while (square <= 63) {
                ++square;
                n_grains_pre = n_grains;
                n_grains = n_grains_pre*2;

                if (n_grains >= 1000 && n_grains_pre < 1000) {
                        std::cout << "You need " << square << " squares to get at least 1000 grains\n";
                }
                else if (n_grains >= 1000000 && n_grains_pre < 1000000) {
                        std::cout << "You need " << square << " squares to get at least 1.000.000 grains\n";
                }
                else if (n_grains >= 1000000000 && n_grains_pre < 1000000000) {
                        std::cout << "You need " << square << " squares to get at least 1.000.000.000 grains\n";
                }
        }
}       
