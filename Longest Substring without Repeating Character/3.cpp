#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> indexer;
        int count = 0;
        int longestSScount = 0;
        int indexOfRepeated = 0;

        for(int i = 0; i < s.size(); i++) {
          char act = s[i];
          if(indexer.find(act) == indexer.end()) {
            indexer[act] = i;
            count++;
          } else {
            indexOfRepeated = max(indexOfRepeated, indexer.find(act)->second);
            count = i - indexOfRepeated;
            indexer[act] = i;
          }
          if(longestSScount < count) longestSScount = count;
        }
        return longestSScount;
    }
};

int main() {
  Solution s;
  cout << s.lengthOfLongestSubstring("abba") << endl;
  return 0;
}