#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
        std::vector<double> temps;
        std::cout << "Enter some temperatures: ";
        for (double t; std::cin >> t;) {
                temps.push_back(t);
        }

        double sum = 0;
        for (double x : temps) {
                sum += x;
        }
        std::cout << "Average temperature: " << sum/temps.size() << '\n';

        std::sort(temps.begin(),temps.end());

        if (temps.size()%2 != 0) {
                std::cout << "Median temperature: " << temps[temps.size()/2] << '\n';
        }
        else {
                double second_midnum = temps[temps.size()/2];
                double first_midnum = temps[temps.size()/2]-1;
                double median = (first_midnum + second_midnum) / 2; 
                std::cout << "Median temperature: " << median << '\n';
        }       
}

                
