#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int L = 0;
      int R = numbers.size() - 1;
      while(L != R) {
        if(numbers[L]+numbers[R] == target) return vector<int> { L+1, R+1 };
        if(numbers[L]+numbers[R] < target) {
          L++;
        } else {
          R--;
        }
      }
      return vector<int> {-1,-1}; // should never happen
    }
};