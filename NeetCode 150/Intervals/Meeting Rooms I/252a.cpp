#include <vector>
using namespace std;

class Solution {
public:
  bool canAttendMeetings(vector<vector<int>>& intervals) {
    auto cmp = [](vector<int> meeting1, vector<int> meeting2) {
      return meeting1[0] < meeting2[0];
    };
    sort(intervals.begin(), intervals.end(), cmp);

    // size is unsigned int
    // 0 -1 in unsigned int is very big so be careful!!!
    for(int i = 0; i < (int) intervals.size() - 1; i++) {
      vector<int> meeting1 = intervals[i];
      vector<int> meeting2 = intervals[i+1];
      if(meeting1[1] > meeting2[0]) return false; // overlap if end of cur meeting is after beginning of next meeting
    }

    return true; // no overlap
  }
};
