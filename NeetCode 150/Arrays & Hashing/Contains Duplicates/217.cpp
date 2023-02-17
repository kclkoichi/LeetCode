#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool ret = false;
        unordered_set<int> s;
        for(int n : nums) {
            if(s.find(n) == s.end()) {
                s.insert(n);
            } else {
                ret = true;
            }
        }
        return ret;
    }
};