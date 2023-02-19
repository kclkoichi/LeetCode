#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool check(string s) {
    int st; // using int instead of stack because only one type of parenthesis ()
    for(char c : s) {
      if(c == '(') st++;
      if(c == ')') st--;
      if(st < 0) return false;
    }
    return st == 0;
  }

  vector<string> generateCombinations(vector<string> v, int n) {
    if(n == 0) return v;
    for(int i = 0; i < v.size() / 2; i++) {
      v[i] += ")";
    }
    for(int i = v.size() / 2; i < v.size(); i++) {
      v[i] += "(";
    }
    return generateCombinations(v, n-1);
  }
    
  vector<string> generateParenthesis(int n) {
    vector<string> v = vector<string>(n*2);
    for(int i = 0; i < n*2; i++){

    }
  }
};