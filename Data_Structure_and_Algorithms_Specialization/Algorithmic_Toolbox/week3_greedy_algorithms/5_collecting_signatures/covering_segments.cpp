#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool my_cmp(const Segment& a, const Segment& b)
{
    return a.start < b.start;
};

int min(int x, int y)
{
  return (x < y) ? x : y;
};

int max(int x, int y)
{
  return (x < y) ? y : x;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  std::sort(segments.begin(), segments.end(), my_cmp);
  
  Segment currSeg = segments[0];

  for (int i = 0; i < segments.size(); i++) {
    if (currSeg.end >= segments[i].start) {
       currSeg.start = max(segments[i].start, currSeg.start);
      currSeg.end = min(segments[i].end, currSeg.end);
    } else {
      points.push_back(currSeg.start);
      currSeg =  segments[i];
    };
  }; 

    points.push_back(currSeg.start);

  return points;
}

int main() {
  int n = 3;
  // std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
