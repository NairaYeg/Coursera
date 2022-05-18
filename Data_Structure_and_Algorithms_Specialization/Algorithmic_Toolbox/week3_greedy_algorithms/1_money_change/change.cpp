#include <iostream>

int get_change(int m)
{
  if (m == 0)
  {
    return 0;
  };

  if (m >= 10)
  {
    return 1 + get_change(m - 10);
  };

  if (m >= 5 && m <= 10)
  {
    return 1 + get_change(m - 5);
  };

  if (m >= 1 && m <= 5)
  {
    return 1 + get_change(m - 1);
  };
};

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
