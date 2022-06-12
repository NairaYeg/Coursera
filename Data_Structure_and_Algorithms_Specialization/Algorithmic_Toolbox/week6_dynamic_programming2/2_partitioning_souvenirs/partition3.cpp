#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool search(const vector<int> &A, int index,
            vector<int> &tmp, int target)
{
  if (index >= A.size())
    return true;
  for (int i = 0; i < tmp.size(); i++)
  {
    if (tmp[i] + A.at(index) <= target)
    {
      tmp[i] += A.at(index);
      if (search(A, index + 1, tmp, target))
      {
        return true;
      }
      tmp[i] -= A.at(index);
    }
  }
  return false;
}

bool partition3(vector<int> &A)
{
  long long n = accumulate(A.begin(), A.end(), 0);
  if (n % 3 != 0 or A.size() < 3 or
      *max_element(A.begin(), A.end()) > n / 3)
  {
    return false;
  }

  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  vector<int> partitions(3, 0);
  return search(A, 0, partitions, n / 3);
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (int i = 0; i < A.size(); ++i)
  {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}