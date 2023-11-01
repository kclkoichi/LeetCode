#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> wanted;
    for(char c: s1) wanted[c]++;
    int wantedCharCount = s1.size();

    int left = 0;
    int right = 0;
    while(right < s1.size()) {
      if(right == s2.size()) return false; // s2 is smaller than s1, cannot contain permutation

      char cur = s2[right];
      if(wanted.find(cur) != wanted.end()) {
        wanted[cur]--;
        if(wanted[cur] >= 0) {
          wantedCharCount--;
        }
      }
      right++;
    }
    right--; // to get left and right inclusive of window extremities

    while(right < s2.size() - 1) {
      // check
      if(wantedCharCount == 0) return true;

      // move
      char remove = s2[left];
      left++;
      if(wanted.find(remove) != wanted.end()) {
        wanted[remove]++;
        if(wanted[remove] > 0) {
          wantedCharCount++;
        }
      }
      right++;
      char add = s2[right];
      if(wanted.find(add) != wanted.end()) {
        wanted[add]--;
        if(wanted[add] >= 0) {
          wantedCharCount--;
        }
      }
    }
    // last substring check
    if(wantedCharCount == 0) return true;

    return false;
  }
};