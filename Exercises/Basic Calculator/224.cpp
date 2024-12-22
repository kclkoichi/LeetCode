#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    // For when no parentheses
    int evaluate(stack<string>& reverseSt) {
        int res = 0;
        string op = "+";
        while(!reverseSt.empty()) {
            if(reverseSt.top() == "+" || reverseSt.top() == "-") {
                op = reverseSt.top();
            } else {
                if(op == "+") res += stoi(reverseSt.top());
                if(op == "-") res -= stoi(reverseSt.top());
            }
            reverseSt.pop();
        }
        return res;
    }

    int calculate(string s) {
        stack<string> st;
        string curNum = "";
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(isdigit(c)) {
                curNum += c;
            } else {
                if(!curNum.empty()) st.push(curNum);
                curNum = "";
                if(c == ' ') continue;
                st.push(string(1, c)); // +, -, (, )
            }
            if(i == s.size() - 1 && !curNum.empty()) st.push(curNum);

            if(!st.empty() && st.top() == ")") {
                st.pop(); // (
                stack<string> reverseSt;
                while(st.top() != "(") {
                    reverseSt.push(st.top());
                    st.pop();
                }
                st.pop(); // )
                st.push(to_string(evaluate(reverseSt)));
            }
        }

        // Remaining expression
        stack<string> reverseSt;
        while(!st.empty()) {
            reverseSt.push(st.top());
            st.pop();
        }
        return evaluate(reverseSt);
    }
};
