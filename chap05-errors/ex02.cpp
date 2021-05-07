#include<iostream>


void error(std::string s)
{
        throw std::runtime_error(s);
}

double ctok(double c)
/*      c is degrees in Celsius. The minimum value is -273.15
 *      which is the absolute zero.
*/
{
        //constexpr double kelvin = 273.15;
        constexpr double kelvin = -273.15;
        if (c < kelvin) {
                error("Value lower than absolute zero");
        }
        double k = c - kelvin;
        return k; 
}

int main()
try {
        std::cout << "Insert temperature value in Celsius: ";
        double c = 0;
        std::cin >> c;
        double k = ctok(c);
        std::cout << c << " degrees Celsius are " << k 
                << " Kelvin" << '\n';
        return 0;
}
catch (std::runtime_error& e) {
        std::cerr << "runtime error: " << e.what() << '\n';
        return 1;
}
