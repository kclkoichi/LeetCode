#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
      unordered_map<char, int> frequencyMap;
      int start = 0; int end = -1; int maxSubstr = 0;
      int maxFrequency = 0;
      while(end < (int) s.size() - 1) {
        // Compare signed int with signed int, otherwise always false
        end++;
        char cur = s[end]; 
        frequencyMap[cur]++;
        // Max Frequency of same char in a window of all time, not current window
        if(frequencyMap[cur] > maxFrequency) maxFrequency = frequencyMap[cur];
        if(end - start + 1 - maxFrequency <= k) {
          // It is valid, we can keep expanding
          maxSubstr++; // only increment when window can become longer (to the right)
        } else {
          // Too many weirdo chars
          char del = s[start];
          frequencyMap[del]--;
          start++; // shift window to the right
        }
      }

      return maxSubstr;
    }
};

// LeetCode
int main() {
  Solution s;
  s.characterReplacement("EOEMQLLQTRQDDCOERARHGAAARRBKCCMFTDAQOLOKARBIJBISTGNKBQGKKTALSQNFSABASNOPBMMGDIOETPTDICRBOMBAAHINTFLH", 7);
  return 0;
}