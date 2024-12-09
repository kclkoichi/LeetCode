#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<char> mainStack;
        for(char c: s) {
            if(c == ']') {
                stack<char> reversingStack;
                while(mainStack.top() != '[') {
                    reversingStack.push(mainStack.top());
                    mainStack.pop();
                }

                mainStack.pop(); // pop the '['
                string insideBracketString = "";
                while(!reversingStack.empty()) {
                    insideBracketString += reversingStack.top();
                    reversingStack.pop();
                }

                int mult = 1;
                int times = 0;
                while(!mainStack.empty() && mainStack.top() >= '0' && mainStack.top() <= '9') {
                    times += (int) (mainStack.top() - '0') * mult;
                    mult *= 10;
                    mainStack.pop();
                }
                string unrolled = "";
                for(int i = 1; i <= times; i++) unrolled += insideBracketString;
                for(char uc: unrolled) mainStack.push(uc);
            } else {
                mainStack.push(c);
            }
        }

        stack<char> reversingStack;
        while(!mainStack.empty()) {
            reversingStack.push(mainStack.top());
            mainStack.pop();
        }
        string res;
        while(!reversingStack.empty()) {
            res += reversingStack.top();
            reversingStack.pop();
        }
        return res;
    }
};