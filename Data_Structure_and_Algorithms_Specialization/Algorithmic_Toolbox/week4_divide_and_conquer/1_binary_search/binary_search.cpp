#include <iostream>
#include <cassert>
#include <vector>

using std::vector;


int binary_search(const vector<int> &a, int x,  int left, int right)  {
  if (right >= left) {
        int mid = (right + left) / 2;
    
        if (a[mid] == x) {
                return mid;
        };
      

        if (a[mid] > x) {
              return binary_search(a,  x, left, mid - 1);
        };
        

        return binary_search(a, x, mid + 1, right);
    }
  return -1;
};

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);

  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  };
   int right = a.size();
  for (int i = 0; i < m; ++i) {
    // replace with the call to binary_search when implemented
    std::cout <<binary_search(a, b[i], 0, right-1) << ' ';
  }
};
