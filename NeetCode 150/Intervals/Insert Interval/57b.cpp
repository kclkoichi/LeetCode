#include <vector>
using namespace std;

class Solution {
public:
    bool overlap(vector<int> a, vector<int> b) {
        return (a[1] >= b[0] && b[1] >= a[0]);
    }

    vector<int> merge(vector<int> a, vector<int> b) {
        return { min(a[0], b[0]), max(a[1], b[1]) };
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> tmp;
        tmp = intervals;
        tmp.push_back(newInterval);

        // Edge cases: No overlap in extremity
        if(intervals.size() == 0) return { newInterval };
        if(newInterval[0] > intervals[intervals.size() - 1][1]) {
            intervals.push_back(newInterval);
            return intervals;
        } 
        if(newInterval[1] < intervals[0][0]) {
            intervals.push_back(newInterval);
            return intervals;
        }

        vector<vector<int>> res;
        res.push_back(tmp[0]);
        // Make merged intervals
        for(int i = 1; i < tmp.size(); i++) {
            if(overlap(res[res.size() - 1], tmp[i])) {
                res[res.size() - 1] = merge(res[res.size() - 1], tmp[i]);
            } else {
                res.push_back(tmp[i]);
            }
        }

        return res;
    }
};