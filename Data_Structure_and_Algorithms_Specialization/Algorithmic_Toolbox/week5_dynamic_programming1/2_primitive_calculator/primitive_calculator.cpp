#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
	std::vector<int> sequence;
	std::vector<int>  tmp(n+1);
	for(int i =1; i< tmp.size(); i++){
		tmp[i] = tmp[i-1] + 1;
		if (i%2 == 0) 
			tmp[i] = std::min(1 + tmp[i/2], tmp[i]);
		if (i%3 == 0) 
			tmp[i] = std::min(1 + tmp[i/3], tmp[i]);
	}
	int i = n;
  
	while (i>1) {
		sequence.push_back(i);
		if (tmp[i-1] == tmp[i]-1)
			i = i-1;
		else if (i%2 == 0 && (tmp[i/2] == tmp[i]-1))
			i = i/2;
		else if (i%3 == 0 && (tmp[i/3] == tmp[i]-1))
			i = i/3;
	}
	sequence.push_back(1);
	reverse(sequence.begin(), sequence.end());
	return sequence;
};


int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
