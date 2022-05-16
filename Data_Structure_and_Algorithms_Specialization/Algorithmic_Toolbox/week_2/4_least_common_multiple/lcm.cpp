#include <iostream>

int gcd(int a, int b)
{
  int current_gcd = 1;
  int remainder = (a % b);

  if (remainder == 0)
  {
    return b;
  };

  return gcd(b, remainder);
}

long long lcm_naive(long a, long b)
{
  if (a > b)
  {
    return (a / gcd(a, b)) * b;
  };

  return (b / gcd(a, b)) * a;
}

int main()
{
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
