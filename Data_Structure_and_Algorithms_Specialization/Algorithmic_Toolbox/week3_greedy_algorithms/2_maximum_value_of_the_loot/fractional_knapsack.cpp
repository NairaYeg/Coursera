#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using std::vector;

double roundoff(double value, unsigned char prec)
{
  double pow_10 = pow(10.0f, (double)prec);
  return round(value * pow_10) / pow_10;
}

int getMostExpensiveItem(vector<int> weights, vector<int> values)
{
  int maxIdx;
  int price = 0;

  for (
      int i = 0; i < values.size(); i++)
  {
    if (values[i] / weights[i] > price)
    {
      price = values[i] / weights[i];
      maxIdx = i;
    };
  };

  return maxIdx;
};

double findminval(double num1, int num2)
{
  return num1 < num2 ? num1 : num2;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
  double value = 0.0;
  double weight;
  double amount;

  if (capacity == 0 || weights.size() == 0)
  {
    return 0;
  };
  int maxIdx = getMostExpensiveItem(weights, values);

  weight = weights[maxIdx];

  amount = findminval(weight, capacity);

  value = (values[maxIdx] * amount) / weight;

  values.erase(values.begin() + maxIdx);
  weights.erase(weights.begin() + maxIdx);

  double rounded = roundoff(value, 3);

  return rounded + get_optimal_value(capacity - amount, weights, values);
};

int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);

  for (int i = 0; i < n; i++)
  {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
