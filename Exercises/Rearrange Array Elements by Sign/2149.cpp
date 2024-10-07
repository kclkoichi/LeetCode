#include <vector>
using namespace std;

class Solution {
public:
  vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> res;
    
    bool posTurn = true;
    int posI = 0;
    int negI = 0;
    while(posI < nums.size() || negI < nums.size()) {
      if(posTurn) {
        while(posI < nums.size() && nums[posI] < 1) posI++;
        if(posI < nums.size()) res.push_back(nums[posI]);
        posI++;
      } else {
        while(negI < nums.size() && nums[negI] > -1) negI++;
        if(negI < nums.size()) res.push_back(nums[negI]);
        negI++;
      }
      posTurn = !posTurn;
    }
    
    return res;
  }
};
