#include <string>
using namespace std;

class Solution {
public:
    bool find(string pattern, string word) {
        int index = 0;
        while(index < word.size()) {
            if(index + pattern.size() > word.size()) return false;
            if(pattern != word.substr(index, pattern.size())) return false;
            index += pattern.size();
        }
        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        string originalPattern;
        string pattern;
        string toMatch;
        if(str1.size() < str2.size()) {
            originalPattern = str1;
            pattern = str1;
            toMatch = str2;
        } else {
            originalPattern = str2;
            pattern = str2;
            toMatch = str1;
        }

        while(pattern.size() > 0) {
            if(find(pattern, toMatch) && find(pattern, originalPattern)) {
                return pattern;
            }
            pattern.pop_back();
        }
        return "";
    }
};
