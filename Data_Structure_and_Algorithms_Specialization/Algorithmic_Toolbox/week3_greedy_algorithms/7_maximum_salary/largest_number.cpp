#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>


using std::vector;
using std::string;

bool myCmp(string s1, string s2)
{
    if ((s1+s2).compare((s2+s1)) < 0) {
        return s1 > s2;
    };

    if ((s1+s2).compare((s2+s1)) > 0) {
        return s1 < s2;
    };
    
    return 0;
}


string largest_number(vector<string> a) {

  sort(a.begin(), a.end(), myCmp);

  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
};

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
