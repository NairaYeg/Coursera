#include <iostream>

int gcd_naive(int a, int b)
{
  int current_gcd = 1;
  int remainder = (a % b);

  if (remainder == 0)
  {
    return b;
  };

  return gcd_naive(b, remainder);
}

int main()
{
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(a, b) << std::endl;
  return 0;
}
