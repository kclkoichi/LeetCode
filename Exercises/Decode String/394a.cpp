#include <string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string cur;

        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c >= 'a' && c <= 'z') {
                cur += c;
            } else if (c >= '1' && c <= '9') {
                string timesString = "";
                while(s[i] >= '0' && s[i] <= '9') {
                    timesString += s[i];
                    i++;
                }
                int times = stoi(timesString);

                i++; // to skip open bracket
                int openCount = 1;
                string rec = "";
                while(openCount != 0) {
                    if(s[i] == ']') {
                        openCount--;
                        if(openCount == 0) break;
                    } else if(s[i] == '[') {
                        openCount++;
                    }
                    rec += s[i];
                    i++;
                }
                string toAdd = decodeString(rec);
                for(int t = 0; t < times; t++) cur += toAdd;
            }
        }

        return cur;
    }
};