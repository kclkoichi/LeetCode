#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r]) {
                string withoutL = s;
                withoutL.erase(l, 1);
                string withoutR = s;
                withoutR.erase(r, 1);
                return isPalindrome(withoutL) || isPalindrome(withoutR);
            }
            l++;
            r--;
        }
        return true;
    }
};
