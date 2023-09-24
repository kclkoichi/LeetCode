#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res = vector<vector<int>>();
    for(int i = 0; i < intervals.size(); i++) {
      // if there is no overlap, can add safely to the result
      if(intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i]);
      } else if (newInterval[1] < intervals[i][0]) {
        res.push_back(newInterval);
        res.insert(res.end(), intervals.begin() + i, intervals.end());
        return res;
      } else {
        // there is some overlap between new interval and current interval
        // we can merge them!
        newInterval = vector<int> {
          min(newInterval[0], intervals[i][0]),
          max(newInterval[1], intervals[i][1])
        };
      }
    }
    
    // in case merge was last interval
    res.push_back(newInterval);

    return res;
  }
};

int main() {
  Solution s;
  vector<vector<int>> v { {1,3}, {6,9} };
  vector<int> v2 {2,5};
  s.insert(v, v2);
}