#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  // Solution using recursion (TLE)
  int recursiveLongestCommonSubsequence(string text1, string text2) {
    // base case
    if(text1.size() == 0 || text2.size() == 0) return 0;
    if(text1[0] == text2[0]) {
      return 1 + recursiveLongestCommonSubsequence(
        text1.substr(1, text1.size()-1),
        text2.substr(1, text2.size()-1)
      );
    } else {
      return max(
        recursiveLongestCommonSubsequence(
          text1.substr(0, text1.size()),
          text2.substr(1, text2.size()-1)
        ),
        recursiveLongestCommonSubsequence(
          text1.substr(1, text1.size()-1),
          text2.substr(0, text2.size())
        )
      );
    }
  }

  // 2D Dynamic Programming
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> grid = vector<vector<int>>(text1.size() + 1, vector<int>(text2.size() + 1));
    for(int i = text1.size() - 1; i >= 0; i--) {
      for(int j = text2.size() - 1; j >= 0; j--) {
        if(text1[i] == text2[j]) {
          grid[i][j] = grid[i+1][j+1] + 1;
        } else {
          grid[i][j] = max(grid[i+1][j], grid[i][j+1]);
        }
      }
    }
    return grid[0][0];
  }
};