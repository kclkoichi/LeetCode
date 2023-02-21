#include <vector>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int lRow = 0;
    int rRow = matrix.size();
    // Binary search of matching row
    while(lRow+1 != rRow) {
      int index = (lRow + rRow) / 2;
      if(matrix[index][0] == target) return true;
      if(target < matrix[index][0]) rRow = index;
      if(target > matrix[index][0]) lRow = index;
    }
    int row = lRow; // because it is in between smallest of lRow and smallest of Rrow(exclusive)
    // Binary Search inside the row
    int lCol = 0;
    int rCol = matrix[row].size();
    while(lCol+1 != rCol) {
      int index = (lCol + rCol) / 2;
      if(matrix[row][index] == target) return true;
      if(target < matrix[row][index]) rCol = index;
      if(target > matrix[row][index]) lCol = index;
    }
    return matrix[0][0] == target;
    }
};

// LeetCode
int main() {
  Solution s;
  vector<vector<int>> vv {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
  s.searchMatrix(vv, 13);
  return 0;
}