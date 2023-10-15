#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int countWords(vector<string>& words1, vector<string>& words2) {
    unordered_map<string, int> map1;
    for(string word: words1) map1[word]++;
    unordered_map<string, int> map2;
    for(string word: words2) map2[word]++;

    int count = 0;
    for(auto [word, wordCount]: map1) {
      if(wordCount == 1 && map2[word] == 1) count++;
    }
    return count;
  }
};