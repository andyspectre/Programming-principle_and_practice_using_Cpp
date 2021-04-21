#include<iostream>
#include<vector>

std::vector<std::string> values = {"zero", "one", "two", 
        "three", "four", "five", "six", "seven", "eight", "nine"};

std::string spelled(int digit)
{
        if (0<=digit && digit<=9) {
                return values[digit];
        }
        else {
                return "Error: out of range digit";
        }
}

int digit(std::string spelled)
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
