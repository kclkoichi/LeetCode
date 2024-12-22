#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char lastOp = '?';
        string prevNum = "";
        for(char c: s) {
            if(c == '+' || c == '-' || c == '*' || c == '/') {
                st.push(stoi(prevNum));
                if(lastOp == '-') {
                    st.pop();
                    st.push(-1 * stoi(prevNum));
                }
                prevNum = "";

                if(lastOp == '*' || lastOp == '/') {
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    if(lastOp == '*') st.push(a * b);
                    if(lastOp == '/') st.push(a / b);
                }

                lastOp = c;
            } else if(isdigit(c)) {
                prevNum += c;
            }
        }

        // Last element is a number, don't forget it
        st.push(stoi(prevNum));
        if(lastOp == '-') {
            st.pop();
            st.push(-1 * stoi(prevNum));
        } else if(lastOp == '*' || lastOp == '/') {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if(lastOp == '*') st.push(a * b);
            if(lastOp == '/') st.push(a / b);
        }

        // Second iteration to deal with all additions
        while(st.size() > 1) {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            st.push(a + b);
        }

        return st.top();
    }
};

int main() {
    string op = "1-1";
    Solution s;
    cout << s.calculate(op) << endl;

    return 0;
}
