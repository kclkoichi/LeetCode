#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;

        for(int i = 0; i <= nums.size() - k; i++) {
            int max = nums[i];
            bool can = true;
            for(int j = i + 1; j < i + k; j++) {
                if(nums[j] == max + 1) {
                    max = nums[j];
                } else {
                    can = false; // It was not sorted ascending or consecutive
                    break;
                }
            }
            res.push_back(can ? max : -1);
        }

        return res;
    }
};
