
#include <limits.h>
#include <iostream>
#include <vector>

int get_change(int m)
{
  std::vector<int> coins = {1, 3, 4};
  
	int a[m+1];

	a[0] = 0;

	for (int i=1; i<=m; i++)
		a[i] = INT_MAX;

	for (int i=1; i<=m; i++)
	{
		for (int j=0; j<coins.size(); j++)
		if (coins[j] <= i)
		{
			int numCoins= a[i-coins[j]];
			if (numCoins != INT_MAX && numCoins + 1 < a[i])
				a[i] = numCoins + 1;
		}
	}

	if(a[m]==INT_MAX)
		return -1;

	return a[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

