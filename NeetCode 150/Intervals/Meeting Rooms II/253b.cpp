#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // time, add(1) or remove(0) room. remove has precedence over add
        vector<pair<int, int>> times;
        for(const vector<int>& interval: intervals) {
            times.push_back(make_pair(interval[0], 1)); // Add room
            times.push_back(make_pair(interval[1], 0)); // Remove room
        }

        sort(times.begin(), times.end());

        int res = 0;
        int count = 0;
        for(const auto& [time, cmd]: times) {
            if(cmd == 1) count++;
            else count--;
            res = max(res, count);
        }
        return res;
    }
};
