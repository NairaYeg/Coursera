
#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<long long>& numbers) {
    int n = numbers.size();
    int first_max_idx = 0;
    int second_max_idx = 0;
    long long max_product;

    for (int i = 0; i < n; i++) {
        if (numbers[first_max_idx] < numbers[i]) {
            first_max_idx = i;
        };
    };
  
     for (int i = 0; i < n; i++) {
        if ((numbers[second_max_idx] < numbers[i]) && (i != first_max_idx) || 
       (second_max_idx == first_max_idx)) {
            second_max_idx = i;
        };
    }; 

    max_product = numbers[first_max_idx] * numbers[second_max_idx];

   return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    };

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
