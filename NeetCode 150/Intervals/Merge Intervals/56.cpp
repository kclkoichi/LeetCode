#include <vector>
using namespace std;

// [[1,3],[1,6],[8,10],[11,18]]
// previous current
// [1,6],[8,18]
// if no overlap, push previous
// if overlap, modify current

class Solution {
public:
  bool overlap(vector<int>& interval1, vector<int>& interval2) {
    return interval1[1] >= interval2[0];
  }
  
  vector<int> mergeInterval(vector<int> interval1, vector<int> interval2) {
    return {interval1[0], max(interval1[1], interval2[1])};
  }

  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // edge case
    if(intervals.size() == 1) return intervals;

    // compare by start time
    auto cmp = [](vector<int> interval1, vector<int> interval2) {
      return interval1[0] < interval2[0];
    };
    sort(intervals.begin(), intervals.end(), cmp);

    vector<vector<int>> res;
    vector<int> prev = intervals[0];
    for(int i = 1; i < intervals.size(); i++) {
      vector<int>& cur = intervals[i];
      if(overlap(prev, cur)) {
        cur = mergeInterval(prev, cur);
      } else {
        res.push_back(prev);
      }
      prev = cur;
    }
    res.push_back(intervals[intervals.size()-1]);
    return res;
  }
};
