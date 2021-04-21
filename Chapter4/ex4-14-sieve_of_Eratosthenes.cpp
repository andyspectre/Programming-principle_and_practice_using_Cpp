#include<iostream>
#include<vector>

void sieve(int n)
{
        std::vector<bool> is_prime(n+1, true);

        for (int i = 2; i <= n; ++i) {
                if (is_prime[i]) {
                        std::cout << i << " ";
                        for (int k = i*i; k <= n; k += i) {
                                is_prime[k] = false;
                        }
                }
        }
}

int main()
{
        int n = 0;
        std::cout << "Enter a number n to check the prime numbers from 1 to n: ";
        std::cin >> n;
        sieve(n);
}
