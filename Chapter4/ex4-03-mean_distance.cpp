#include<iostream>
#include<vector>

int main()
{
        std::vector<double> dist;
        std::cout << "Enter a some distances: ";
        for(double d; std::cin >> d;) {
                dist.push_back(d);
        }

        double sum = 0;
        for(double x : dist) {
                sum += x;
        }
        
        double gre_dist = 0;
        double sma_dist = 0;
        for (int i = 0; i<dist.size(); ++i) {
                if (i == 0) {
                        gre_dist = dist[i];
                        sma_dist = dist[i];
                }
                else if (dist[i] > gre_dist) {
                        gre_dist = dist[i];
                }
                else {
                        sma_dist = dist[i];
                }
        }       
        std::cout << "Smallest distance: " << sma_dist 
                << "\nGreatest distance: " << gre_dist 
                << "\nSum of distances: " << sum
                << "\nMean distance is :" << sum/dist.size() << '\n';
}
