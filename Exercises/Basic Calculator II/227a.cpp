#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int lastNumber = 0;
        int currentNumber = 0;
        char lastOp = '+';
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(isdigit(c)) {
                currentNumber *= 10;
                currentNumber += (c - '0');
            }
            
            if(i == s.size() - 1 || c == '+' || c == '-' || c == '*' || c == '/') {
                if(lastOp == '+') {
                    res += lastNumber;
                    lastNumber = currentNumber;
                }
                if(lastOp == '-') {
                    res += lastNumber;
                    lastNumber = -1 * currentNumber;
                }
                if(lastOp == '*') {
                    lastNumber *= currentNumber;
                }
                if(lastOp == '/') {
                    lastNumber /= currentNumber;
                }
                currentNumber = 0;
                lastOp = c;
            }
        }
        res += lastNumber;
        return res;
    }
};
