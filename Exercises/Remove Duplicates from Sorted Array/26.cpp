#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    vector<int> have(201);
    for(int num: nums) have[num + 100] = 1;
    int index = 0;
    int count = 0;
    for(int i = 0; i < have.size(); i++) {
      if(have[i] == 1) {
        nums[index] = i - 100;
        index++;
        count++;
      }
    }
    return count;
  }
};
