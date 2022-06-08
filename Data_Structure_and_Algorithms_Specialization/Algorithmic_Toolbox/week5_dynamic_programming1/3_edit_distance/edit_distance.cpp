#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

using std::string;
int getMinValue(int x,int y,int z){
    if(min(x,y)>z)
        return z;
    else 
        return min(x,y);
};

int edit_distance(const string &str1, const string &str2) {

  int n = str1.size(),m=str2.size();
  int tmp[n+1][m+1];
  int insertion,mismatch,match,deletion;
  
  for(int i=0;i<n+1;i++)
    tmp[i][0]=i;
  
  for(int j=0;j<m+1;j++)
    tmp[0][j]=j;
    
  for(int i=1;i<n+1;i++){
      for(int j=1;j<m+1;j++){
            insertion =tmp[i][j-1]+1;
            deletion = tmp[i-1][j]+1;
            match = tmp[i-1][j-1];
            mismatch = tmp[i-1][j-1]+1;
          if(str1[i-1]==str2[j-1])
            tmp[i][j]=getMinValue(insertion,deletion,match);
        else
            tmp[i][j]= getMinValue(insertion,deletion,mismatch);
      }
  }
  
  return tmp[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}