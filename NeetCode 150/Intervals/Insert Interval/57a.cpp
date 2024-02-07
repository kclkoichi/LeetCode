#include <vector>
using namespace std;

class Solution {
public:
  bool overlap(vector<int>& a, vector<int>& b) {
    return a[0] <= b[1] && a[1] >= b[0];
  }

  vector<int> merge(vector<int>& a, vector<int>& b) {
    return {min(a[0], b[0]), max(a[1], b[1])};
  }

  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.push_back(newInterval);
    for(int i = intervals.size() - 1; i > 0; i--) {
      vector<int>& cur = intervals[i];
      vector<int>& prev = intervals[i-1];

      if(cur[0] <= prev[1]) {
        if(overlap(cur, prev)) {
          prev = merge(cur, prev);
          intervals.erase(intervals.begin() + i);
        } else {
          // swap
          vector<int> tmp = prev;
          prev = cur;
          cur = tmp;
        }
      }
    }

    return intervals;
  }
};
