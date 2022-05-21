#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops, int location=0, int count = 0) {
 int lastStop; 
  
 if (location + tank >= dist) {
   return count;
 };   

 if (stops.size() == 0 || stops[0] - location > tank || (stops[0] - location > tank && location < dist)) {
   return -1;
 };
 
 lastStop = location;

  while (stops.size() !=0 && stops[0] - location <= tank) {
    lastStop = stops[0];
    stops.erase(stops.begin());
  };

  return  compute_min_refills(dist, tank, stops, lastStop, count += 1);
};


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);
   
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
