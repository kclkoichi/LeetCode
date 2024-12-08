#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

class Solution {
public:
    bool overlap(vector<int> a, tuple<int, int> b) {
        return a[0] <= get<1>(b) && get<0>(b) <= a[1];
    }

    vector<int> merge(vector<int> a, tuple<int, int> b) {
        return { min(a[0], get<0>(b)), max(a[1], get<1>(b)) };
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort intervals by start time
        vector<tuple<int, int>> sorted;
        for(vector<int> interval: intervals) {
            sorted.push_back(make_tuple(interval[0], interval[1]));
        }
        sort(sorted.begin(), sorted.end());

        vector<vector<int>> res;
        res.push_back({get<0>(sorted[0]), get<1>(sorted[0])});

        for(int i = 1; i < sorted.size(); i++) {
            if(overlap(res[res.size()-1], sorted[i])) {
                res[res.size()-1] = merge(res[res.size()-1], sorted[i]);
            } else {
                res.push_back({get<0>(sorted[i]), get<1>(sorted[i])});
            }
        }

        return res;
    }
};
