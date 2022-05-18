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

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
  double value = 0.0;
  int weight;

  if (capacity == 0 || weights.size() == 0)
  {
    return 0;
  };

  int maxIdx = std::max_element(values.begin(), values.end()) - values.begin();
  weight = weights[maxIdx];
  value = values[maxIdx];

  if (weight <= capacity)
  {

    values.erase(values.begin() + maxIdx);
    weights.erase(weights.begin() + maxIdx);

    double rounded = roundoff(value, 3);

    return rounded + get_optimal_value(capacity - weights[maxIdx], weights, values);
  };

  if (weights.size() == 1)
  {
    value = (capacity * value) / weight;
    values.erase(values.begin() + maxIdx);
    weights.erase(weights.begin() + maxIdx);

    double rounded = roundoff(value, 3);

    return rounded + get_optimal_value(capacity, weights, values);
  };

  if (weight > capacity)
  {
    values.erase(values.begin() + maxIdx);
    weights.erase(weights.begin() + maxIdx);
    return get_optimal_value(capacity, weights, values);
  };
}

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
