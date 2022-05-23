#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  if (n == 0) {
  summands.push_back(0);
    return summands;
  };

  if (n == 2) {
  summands.push_back(2);
    return summands;
  };
  
  int sum = 1;
  summands.push_back(1);
  int next;

  
  while (sum < n) {
    int last = summands[summands.size() - 1];
    next = last + 1;
    summands.push_back(next);
    sum += next;

    if (sum + (summands[summands.size() - 1] + 1) > n) {

      sum -= next;
      next = n - sum;
      summands[summands.size()-1] = next;
      sum += next;
      break;
 
      }
  };
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
