#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int maxL = 0;
        unordered_set<char> have;
        
        while(r < s.size()) {
            char cur = s[r];
            if(have.find(cur) != have.end()) {
                while(s[l] != cur) {
                    have.erase(s[l]);
                    l++;
                }
                l++; // move once to the right of 1st occurence of repeated char
            } else {
                have.insert(cur);
            }
            maxL = max(maxL, r-l+1);
            r++;
        }
        return maxL;
    }
};
