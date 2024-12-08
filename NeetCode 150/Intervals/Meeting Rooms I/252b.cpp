#include <vector>
#include <algorithm>
using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

class Solution {
public:
    bool overlap(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[1] && a[1] > b[0];
    }

    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return true;

        sort(intervals.begin(), intervals.end(), compare);
        for(int i = 0; i < intervals.size() - 1; i++) {
            if(overlap(intervals[i], intervals[i+1])) return false;
        }
        return true;
    }
};
