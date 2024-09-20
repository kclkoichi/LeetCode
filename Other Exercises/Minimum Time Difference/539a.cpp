#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  int findMinDifference(vector<string>& timePoints) {
    sort(timePoints.begin(), timePoints.end());

    vector<string> toPush = vector<string>();
    for(string time: timePoints) toPush.push_back(plusTwentyFourHours(time));
    for(string twentyFour: toPush) timePoints.push_back(twentyFour);

    int res = INT_MAX;
    for(int i = 0; i < timePoints.size() - 1; i++) {
      string before = timePoints[i];
      string after = timePoints[i+1];
      res = min(res, diff(before, after));
    }
    return res;
  }

  string plusTwentyFourHours(string time) {
    int hour = stoi(time.substr(0, 2)) + 24;
    return to_string(hour) + time.substr(2, 3);
  }

  int diff(string before, string after) {
    int timeBefore = stoi(before.substr(0, 2)) * 60 + stoi(before.substr(3, 2));
    int timeAfter = stoi(after.substr(0, 2)) * 60 + stoi(after.substr(3, 2));

    return timeAfter - timeBefore;
  }
};
