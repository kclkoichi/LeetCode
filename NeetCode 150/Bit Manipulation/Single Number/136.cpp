#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int i : nums) {
            ret = ret ^ i;
        }
        return ret;
    }
};