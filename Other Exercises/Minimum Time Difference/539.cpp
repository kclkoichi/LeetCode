#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  int findMinDifference(vector<string>& timePoints) {
    vector<int> times; // times are in minutes
    for(string timePoint: timePoints) {
      int hours = (timePoint[0] - '0')*10 + (timePoint[1] - '0');
      int minutes = (timePoint[3] - '0')*10 + (timePoint[4] - '0');
      times.push_back(hours*60 + minutes);
    }

    sort(times.begin(), times.end());

    // 24*60 = 1440 minutes per day
    int minDiff = 1440;
    for(int i = 0; i < times.size() - 1; i++) {
      int time1 = times[i];
      int time2 = times[i+1];
      minDiff = min(time2-time1, minDiff);
    }

    // Last case, let's say the first time point +24 hours - last time point
    return min(minDiff, times[0] + 1440 - times[times.size()-1]);
  }
};