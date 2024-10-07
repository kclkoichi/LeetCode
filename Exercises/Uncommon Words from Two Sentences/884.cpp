#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<string> uncommonFromSentences(string s1, string s2) {
    unordered_map<string, int> words1;
    for(string s: getWords(s1)) {
      if(words1.find(s) != words1.end()) {
        words1[s]++;
      } else {
        words1[s] = 1;
      }
    }

    unordered_map<string, int> words2;
    for(string s: getWords(s2)) {
      if(words2.find(s) != words2.end()) {
        words2[s]++;
      } else {
        words2[s] = 1;
      }
    }

    vector<string> res;
    for(auto [word, count]: words1) {
      if(count == 1 && words2.find(word) == words2.end()) {
        res.push_back(word);
      }
    }
    for(auto [word, count]: words2) {
      if(count == 1 && words1.find(word) == words1.end()) {
        res.push_back(word);
      }
    }
    return res;
  }

  vector<string> getWords(string s) {
    vector<string> res;
    string cur;
    for(char c: s) {
      if(c == ' ') {
        res.push_back(cur);
        cur = "";
      } else {
        cur += c;
      }
    }
    res.push_back(cur); // last word
    return res;
  }
};
