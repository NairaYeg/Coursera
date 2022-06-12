#include <algorithm>
#include <iostream>
#include <vector>

using std::max;
using std::vector;

int lcs2(vector<int> &a, vector<int> &b)
{
  int tmp[a.size() + 1][b.size() + 1];
  int index = 0;
  while (index <= a.size())
  {
    tmp[index][0] = 0;
    index++;
  }
  index = 1;
  while (index <= b.size())
  {
    tmp[0][index] = 0;
    index++;
  }
  for (int i = 1; i <= a.size(); i++)
  {
    for (int j = 1; j <= b.size(); j++)
    {
      if (a.at(i - 1) == b.at(j - 1))
      {
        tmp[i][j] = 1 + tmp[i - 1][j - 1];
      }
      else
      {
        tmp[i][j] = std::max(tmp[i - 1][j], tmp[i][j - 1]);
      }
    }
  }
  return tmp[a.size()][b.size()];
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }

  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++)
  {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
