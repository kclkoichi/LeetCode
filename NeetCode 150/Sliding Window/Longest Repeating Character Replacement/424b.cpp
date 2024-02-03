#include <string>
using namespace std;

class Solution {
public:
  int getOddCount(vector<int> characters) {
    int sum = 0;
    int maxOccurenceCount = 0;
    for(int count: characters) {
      sum += count;
      if(count > maxOccurenceCount) maxOccurenceCount = count;
    }
    return sum - maxOccurenceCount;
  }

  int characterReplacement(string s, int k) {
    int l = 0;
    int r = 0;
    int maxSize = 0;
    vector<int> characters(26, 0);
    while(r < s.size()) {
      characters[s[r] - 'A']++;
      int oddCount = getOddCount(characters);
      if(oddCount > k) {
        characters[s[l] - 'A']--;
        l++;
      } else {
        maxSize++;
      }
      r++;
    }
    return maxSize;
  }
};
