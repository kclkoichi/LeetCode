#include <string>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int d = 0;
        for(char c: s) {
            if(c == '(') d++;
            if(c == ')') d--;
            res = max(res, d);
        }
        return res;
    }
};
