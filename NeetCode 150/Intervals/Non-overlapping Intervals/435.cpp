#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Must be outside of Solution class!!
bool compare(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

class Solution {
public:
    bool overlap(const vector<int>& a, const vector<int>& b) const {
        return a[0] < b[1] && a[1] > b[0];
    }

    // Greedy
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort the intervals on start time, end time
        sort(intervals.begin(), intervals.end(), compare);

        // If overlap:
        // "Remove" the most annoying interval: 
        //   - The one going the most to the right, more risk of clashing with further intervals
        //     - Not necessarily cur, can be prev! As in [-100, 100], [1, 5], [5, 7]
        // Because it's removed, keep prev as the interval kept
        int count = 0;
        vector<int> prev = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
            if(overlap(prev, intervals[i])) {
                count++;
                prev = (prev[1] > intervals[i][1]) ? intervals[i] : prev;
            } else {
                prev = intervals[i];
            }
        }

        return count;
    }
};

// int main() {
//     vector<int> a = { -100, 100 };
//     vector<int> b = { 1, 5 };
//     vector<int> c = { 5, 9 };
//     vector<vector<int>> v = { a, b, c };
//     Solution s;
//     // compare must be outside of Solution class
//     // It must be declared globally, because sort doesn't have access to functions inside Solution
//     cout << s.eraseOverlapIntervals(v) << endl;
//     return 0;
// }
