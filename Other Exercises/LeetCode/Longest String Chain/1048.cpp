#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int longestStrChain(vector<string>& words) {
    unordered_map<string, int> memo;
    memo[""] = 0;
    auto cmp = [](string a, string b) {
      return a.length() < b.length();
    };
    sort(words.begin(), words.end(), cmp);
    int maxCount = 1;
    for(string word: words) {
      memo[word] = 1;
      for(int i = 0; i < word.length(); i++) {
         string cur = word;
         cur.erase(i, 1);

         if(memo.find(cur) != memo.end()) {
          memo[word] = max(memo[word], memo[cur] + 1);
          maxCount = max(maxCount, memo[word]);
         }
      }
    }
    return maxCount;
  }
};