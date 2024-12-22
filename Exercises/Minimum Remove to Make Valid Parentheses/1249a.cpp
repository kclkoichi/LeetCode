#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int> toRemove;
        int open = 0;
        // Remove too many ')'
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') open++;
            if(s[i] == ')') {
                if(open == 0) {
                    toRemove.insert(i);
                } else {
                    open--;
                }
            }
        }

        // When too many '('
        for(int i = s.size() - 1; i >= 0 && open > 0; i--) {
            if(s[i] == '(') {
                toRemove.insert(i);
                open--;
            }
        }

        string res;
        for(int i = 0; i < s.size(); i++) {
            if(toRemove.find(i) == toRemove.end()) {
                res.push_back(s[i]);
            }
        }

        return res;
    }
};
