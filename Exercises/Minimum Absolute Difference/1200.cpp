#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minAbsDiff = INT_MAX;
        vector<vector<int>> res;

        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size() - 1; i++) {
            int cur = arr[i];
            int next = arr[i+1];
            if(abs(cur - next) < minAbsDiff) {
                minAbsDiff = abs(cur - next);
                res = {};
                res.push_back({cur, next});
            } else if(abs(cur - next) == minAbsDiff) {
                res.push_back({cur, next});
            }
        }

        return res;
    }
};
