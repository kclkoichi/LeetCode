#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mapping;
        for(char c : s) {
          mapping[c]++;
        }
        for(char c : t) {
          mapping[c]--;
          if(mapping[c] < 0) return false;
        }
        for(char c : s) {
          if(mapping[c] > 0) return false;
        }
        return true;
    }
};