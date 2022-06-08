
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using std::string;
using namespace std;

int edit_distance(const string &str1, const string &str2) {
  int m = str1.size();
  int n = str2.size();
	vector<vector<int> > tmp(m+1, std::vector<int>(n+1));

	for(int i = 0; i<= m; i++) {
		for(int j = 0; j<= n; j++){

			if( i == 0 ) {   
				tmp[i][j] = j;
      } else if(j == 0) {    
				tmp[i][j] = i;
      } else if(str1[i] == str2[j]) {
        
        int insertion  = tmp[i][j-1] + 1;
        int deletion = tmp[i-1][j] + 1;
        int match = tmp[j-1][i-1];
        
        tmp[i][j] = min(insertion, deletion, match);
        
      } else {
        int insertion  = tmp[i][j-1] + 1;
        int deletion = tmp[i-1][j] + 1;
        int mismatch = tmp[i-1][j-1] + 1;
        
        tmp[i][j] = min(mismatch, deletion, insertion);
			};
	};
};
	return tmp[m][n];
};

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2)  << std::endl;
  return 0;
}
