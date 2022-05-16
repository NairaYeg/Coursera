#include <iostream>
#include <vector>
#include <cstdlib>

int get_fibonacci_last_digit_naive(int n)
{
    std::vector<long long> sequanc(n + 1);
    sequanc[0] = 0;
    sequanc[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        sequanc[i] = (sequanc[i - 1] + sequanc[i - 2]) % 10;
    };

    return sequanc[n];
}

int main()
{
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
}
