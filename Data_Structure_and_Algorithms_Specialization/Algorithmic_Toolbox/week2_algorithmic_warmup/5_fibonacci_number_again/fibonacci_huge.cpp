#include <iostream>
#include <vector>

long long get_pisano_period(long long m)
{
    long prev = 0;
    long curr = 1;
    long res = 0;

    for (int i = 0; i < m * m; i++)
    {
        long temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;

        if (prev == 0 && curr == 1)
        {
            res = i + 1;
        }
    }
    return res;
};

long long get_fibonacci_huge_naive(long long n, long long m)
{
    long period = get_pisano_period(m);

    n = n % period;

    long prev = 0;
    long curr = 1;

    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        long tmp = 0;
        tmp = curr;
        curr = (prev + curr) % m;
        prev = tmp;
    }
    return curr % m;
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
