#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // O(26) == O(1)
  pair<int, char> getMostFrequent(unordered_map<char, int>& counter) {
    int maxCount = 0;
    char maxCountChar = '?';
    for(char c = 'A'; c <= 'Z'; c++) {
      if(counter[c] > maxCount) {
        maxCount = counter[c];
        maxCountChar = c;
      }
    }
    return make_pair(maxCount, maxCountChar);
  }

  int characterReplacement(string s, int k) {
    unordered_map<char, int> counter; // max size 26 (alphabet size)
    for(char c = 'A'; c <= 'Z'; c++) counter[c] = 0;

    int size = 0;
    int maxSize = 0;
    int left = 0;
    int right = 0;
    while(right < s.size()) {
      size++;
      char cur = s[right];
      counter[cur]++;

      auto [mostFrequentCount, mostFrequentChar] = getMostFrequent(counter);

      int alienCount = size - mostFrequentCount;
      if(alienCount > k) {
        // move left till we get rid of enough aliens
        // be careful, while we remove, most frequent char may become alien // eg: AAABBBB with k = 2, should return 6
        while(alienCount > k) {
          int leftChar = s[left];
          counter[leftChar]--;
          left++;
          size--;
          // maybe most common changed
          mostFrequentCount = getMostFrequent(counter).first;
          mostFrequentChar = getMostFrequent(counter).second;
          alienCount = size - mostFrequentCount;
        }
      }

      right++;
      maxSize = max(size, maxSize);
    }
    return maxSize;
  }
};