#include <vector>
using namespace std;

class Solution {
public:
  bool overlap(vector<int> a, vector<int> b) {
    return a[0] < b[1] && a[1] > b[0];
  }

  bool canAttendMeetings(vector<vector<int>>& intervals) {
    if(intervals.size() == 0) return true;
    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
      return a[0] < b[0]; // asc, compare by start time 
    });

    for(int i = 0; i < (intervals.size() - 1); i++) {
      if(overlap(intervals[i], intervals[i+1])) return false;
    }
    return true;
  }
};