#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;
    while(left != right) {
      int num1 = numbers[left];
      int num2 = numbers[right];
      if(num1+num2 == target) {
        return {left+1, right+1}; // 1-index based........
      } else if (num1+num2 < target) {
        left++;
      } else {
        right--;
      }
    }

    // As there is always a solution, this should never happen
    return {-1, -1}; 
  }
};