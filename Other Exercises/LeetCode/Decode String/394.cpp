#include <string>
#include <stack>
using namespace std;

class Solution {
public:
  string decodeString(string s) {
    string times = "";
    stack<int> multipliers;
    stack<string> word;
    word.push("");

    for(char c : s) {
      if(c >= '0' && c <= '9') {
        times += c;
      } else if(c == '[') {
        multipliers.push(stoi(times));
        times = "";
        word.push("");
      } else if(c == ']') {
        string cur = word.top(); word.pop();
        int mult = multipliers.top(); multipliers.pop();
        string multiplied = "";
        for(int i = 1; i <= mult; i++) multiplied += cur;
        string below = word.top(); word.pop();
        word.push(below + multiplied);
      } else {
        // letter
        string cur = word.top() + c;
        word.pop();
        word.push(cur);
      }
    }

    return word.top();
  }
};