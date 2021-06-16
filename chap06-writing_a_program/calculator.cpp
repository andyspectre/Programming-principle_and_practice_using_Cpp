// Andrea Cocco 2020 
// Chapter 6 
// Programming: principles and practice using C++, 2nd edition
// by Bjarne Stroustrup
// https://www.stroustrup.com/programming.html

/* The program is a calculator that computes arithmetic expressions like:
 *
 * 5+3*2-(9/3+3)
 * It accepts addition, subtraction, multiplication, division and parenthesis
 * for grouping.
 *
 * Grammar defining the syntax of the input. Tokens are in double quotes.
 * Alternatives are put on separate lines:
 *
 * Expression:
 *      Term
 *      Expression "+" Term     // addition
 *      Expression "-" Term     // subtraction
 * Term:
 *      Primary
 *      Term "*" Primary        // multiplication
 *      Term "/" Primary        // division
 * Primary:
 *      Number
 *      "(" Expression ")"      // grouping
 * Number:
 *      floating-point-literal
