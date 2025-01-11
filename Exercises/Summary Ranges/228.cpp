#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()) return {};

        vector<string> res;
        int start = nums[0];
        int prev = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int cur = nums[i];
            // End of sequence
            if(cur != prev + 1) {
                if(start == prev) {
                    res.push_back(to_string(start));
                } else {
                    res.push_back(to_string(start) + "->" + to_string(prev));
                }
                start = cur;
            }
            prev = cur;
        }

        if(start == nums[nums.size() - 1]) {
            res.push_back(to_string(start));
        } else {
            res.push_back(to_string(start) + "->" + to_string(nums[nums.size() - 1]));
        }

        return res;
    }
};
