#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> s;
        for(int i = 0; i < nums.size(); i++) {
            if(s.find(target - nums[i]) != s.end()) {
                return vector<int>{s.find(target - nums[i])->second, i};
            }
            s[nums[i]] = i;
        }
        return vector<int>{0,0}; // cannot happen
    }
};

int main(int argc, char const *argv[])
{
  Solution s;
  vector<int> vect{3,2,4};
  s.twoSum(vect, 6);
  return 0;
}
