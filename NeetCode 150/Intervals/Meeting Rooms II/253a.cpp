#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    // Sort by start time
    auto cmp = [](vector<int> meeting1, vector<int> meeting2) {
      return meeting1[0] < meeting2[0];
    };
    sort(intervals.begin(), intervals.end(), cmp);

    // Sort by start time (default MAX heap, so reverse for MIN heap)
    auto cmpPQ = [](int endTime1, int endTime2) {
      return endTime1 > endTime2;
    };
    // Pushing end times
    priority_queue<int, vector<int>, decltype(cmpPQ)> pq(cmpPQ);
    pq.push(intervals[0][1]);

    for(int i = 1; i < intervals.size(); i++) {
      int startTime = intervals[i][0];
      int endTime = intervals[i][1];

      int minEndTime = pq.top();
      // If we have overlap
      if(startTime < minEndTime) {
        pq.push(endTime);
      } else {
        pq.pop();
        pq.push(endTime);
      }
    }

    return pq.size();
  }
};