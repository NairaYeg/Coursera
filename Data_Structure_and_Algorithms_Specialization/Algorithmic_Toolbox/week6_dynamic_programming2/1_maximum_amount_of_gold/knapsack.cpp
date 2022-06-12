#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int W, const vector<int> &w)
{
  vector<vector<int>> tmp(w.size() + 1, vector<int>(W + 1));
  for (int i = 0; i <= W; i++)
  {
    tmp[0][i] = 0;
  }
  for (int i = 0; i <= w.size(); i++)
  {
    tmp[i][0] = 0;
  }

  for (int i = 1; i <= w.size(); i++)
  {
    for (int j = 1; j <= W; j++)
    {
      if (j >= w[i - 1])
      {
        tmp[i][j] = max(w[i - 1] + tmp[i - 1][j - w[i - 1]],
                        tmp[i - 1][j]);
      }
      else
      {
        tmp[i][j] = tmp[i - 1][j];
      }
    }
  }

  return tmp[w.size()][W];
}

int main()
{
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}