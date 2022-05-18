#include <iostream>
#include <vector>
#include <numeric>

long long fibonacci_sum_naive(long long n)
{
    if (n <= 1)
        return n;

    long long sum = 1;

    std::vector<long long> sequanc(n + 1);
    sequanc[0] = 0;
    sequanc[1] = 1;

    for (long long i = 2; i <= n; i++)
    {
        sequanc[i] = sequanc[i - 1] + sequanc[i - 2];
        sum = sum + sequanc[i];
    };

    return labs(sum % 10);
}

int main()
{
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}
