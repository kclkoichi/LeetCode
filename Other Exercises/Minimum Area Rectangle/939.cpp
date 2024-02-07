#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  // for diagonal, do we have other diagonal?
  bool canFindMatching(int x1, int y1, int x2, int y2, unordered_map<int, unordered_set<int>>& have) {
    return (have.find(x1) != have.end() 
      && have[x1].find(y2) != have[x1].end()
      && have.find(x2) != have.end() 
      && have[x2].find(y1) != have[x2].end());
  }

  int minAreaRect(vector<vector<int>>& points) {
    // <x, y>
    unordered_map<int, unordered_set<int>> have;

    int minArea = INT_MAX;
    // gonna see if can make rectangle from diagonal
    for(vector<int> point: points) {
      int x1 = point[0];
      int y1 = point[1];
      for(auto mapping: have) {
        int x2 = mapping.first;
        for(int y2: mapping.second) {
          if(canFindMatching(x1, y1, x2, y2, have)) {
            minArea = min(minArea, abs(x1 - x2) * abs(y1 - y2));
          }
        }
      }
      have[x1].insert(y1); // inserting after checking so we don't count straight lines as rectangles
    }
    return minArea == INT_MAX ? 0 : minArea;
  }
};