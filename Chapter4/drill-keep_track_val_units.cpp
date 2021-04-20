#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
        constexpr double cm_to_m = 0.01;
        constexpr double in_to_m = 0.0254;
        constexpr double ft_to_m = 0.3048;
        std::vector<double> myval;
        double largest = 0;
        double smallest = 0;
        double x = 0;
        double sum = 0;
        int numofvalues = 0;    
        bool okvalue = true;
        bool first = true; 
        std::string unit = "";
        
        std::cout << "Enter a few value/unit pairs, for example: "
                << "100 m 10 cm 0.5 in 1000 ft.\nAllowed units: "
                << "(m, cm, in, ft). Enter '|' to print the result.\n";

        while (std::cin >> x >> unit) {
                //convert allowed units to meters 
                if (unit == "m") {
                        okvalue = true;
                }
                else if (unit == "cm") {
                        x = x*cm_to_m;
                        okvalue = true;
                }
                else if (unit == "in") {
                        x = x*in_to_m;
                        okvalue = true;
                }                       
                else if (unit == "ft") {
                        x = x*ft_to_m;
                        okvalue = true;
                }
                else {
                        okvalue = false;
                }
                        //If are allowed values, put them into 
                        //vector myval and add them
                        if (okvalue == true) {
                                myval.push_back(x);
                                sum += x;
                                        
                                //Keep track of largest and smallest values
                                if (first == true) {
                                        largest = x;
                                        smallest = x;
                                        first = false;
                                }
                                else if (x > largest) {
                                        largest = x;
                                }
                                else if (x < smallest) {
                                        smallest = x;
                                }
                        }
        }
        std::cout << "\nlargest: " << largest << " meters" << '\n';
        std::cout << "smallest: " << smallest << " meters" << '\n';
        std::cout << "number of values: " << myval.size() << '\n';
        std::cout << "sum: " << sum << " meters" << '\n';
        std::cout << "\nThese are the values that you entered (in meters)" 
                << " from the smallest to the largest:" << '\n';
        
        std::sort(myval.begin(),myval.end());
        for (int i = 0; i<myval.size(); ++i) {
                std::cout << myval[i] << '\n';
        }
        
}
