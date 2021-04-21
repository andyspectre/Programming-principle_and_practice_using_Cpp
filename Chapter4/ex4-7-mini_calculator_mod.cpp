//Andrea Cocco 2020
//Chapter 4 Exercise 7
/*
        Modify the "mini calculator" from exercise 5 to accept 
        (just) single-digit numbers written as either digits or spelled out.
*/

#include<iostream>
#include<vector>

std::vector<std::string> values = {"zero", "one", "two",
        "three", "four", "five", "six", "seven", "eight", "nine"};


int read_number()
{
        const int out_of_range = values.size();
        int val = out_of_range;
        // Try to read an integer composed of digits
        if (std::cin >> val) {
                return val;
        }
        // To use cin again after a failed read, we need to use a 
        // function call "cin.clear();" to "clear" it. 
        // This isn't explained in the book until chapter 10. 
        std::cin.clear();        
        std::string spelled = " ";
        std::cin >> spelled;
        for (int i = 0; i < values.size(); ++i) {
                if (values[i] == spelled) {
                        val = i;
                }
        }
        return val;
}

int main()
{
        std::cout << "Enter two numbers separated by an operator.\n"
                << "The operator can be + - * / % : ";

        while (true) {        // that is until we give an unacceptable input 
                              // or make a computations error
                int val1 = read_number();
                char op = 0;
                std::cin >> op;
                int val2 = read_number();
                std::string oper = " ";
                double result = 0;
                
                switch (op) {
                case '+':
                        oper = "sum of ";
                        result = val1+val2;
                        break;
                case '-':
                        oper = "difference between ";
                        result = val1-val2;
                        break;
                case '*':
                        oper = "product of ";
                        result = val1*val2;
                        break;
                case '/':
                        oper = "ratio of ";
                        if (val2==0) {
                                std::cout << "Impossible:"
                                        << " trying to divide by zero... ";
                        }
                        else {
                                result = val1/val2;
                        }
                        break;
                case '%':
                        oper = "remainder of ";
                        if (val2==0) {
                                std::cout << "Impossible:"
                                        << " trying to divide by zero... ";
                        }
                        else {
                                result = val1%val2;
                        }
                        break;
                default:
                        std::cout << "Bad operator... ";
                }
                std::cout << oper << val1 << " and " << val2
                        << " is " << result << '\n';
                std::cout << "Try again: ";
        }
}
