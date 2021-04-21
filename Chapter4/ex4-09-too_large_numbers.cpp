//Andrea Cocco 2021
//Chapter 4 exercise 9
/*
        Try to calculate the number of rice grains that the inventor asked for in exercise 8 above. 
        You’ll find that the number is so large that it won’t fit in an int or a double. 
        Observe what happens when the number gets too large to represent exactly as an int and as a double. 
        What is the largest number of squares for which you can calculate the exact number of grains (using an int)? 
        What is the largest number of squares for which you can calculate the approximate number of grains (using a double)?
*/

#include<iostream>

int main()

{
        int max_n_int = 0;
        double max_n_double = 0;
        int n_sq = 1;
        int n_sq_pre = 1;
        double dbl_sq = 1;
        double dbl_sq_pre = 1;
        int squares = 0;

        while (squares <= 63) {
               ++squares;
               n_sq_pre = n_sq;
               n_sq = n_sq_pre*2;
               //max_n_int = n_sq;
               dbl_sq_pre = dbl_sq;
               dbl_sq = dbl_sq_pre*2;
               //max_n_double = dbl_sq;
               std::cout << squares << '\t' << n_sq << '\t' << dbl_sq << '\n';
                        //<< max_sq_dbl << '\t' << max_n_double;
        }
}
