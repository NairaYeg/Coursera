#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;



int get_majority_element(vector<int> &a, int left, int right) {
 int idx = 0;
 int count = 1;

  for (int i = 1; i < right; i++) {
    if (a[i] == a[idx]) {
      count += 1;
    }else {
      count -=1;
    };

    if (count == 0) {
      idx = i;
      count = 1;
    };
  };

  
  count = 0;
  for (int i = 0; i < right; i++) {
    if (a[i]==a[idx]) {
      count += 1;
    };

    if (count > right/2) {
      return a[idx];
    };
  };
     return -1;
};

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
