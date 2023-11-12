#include <string>
#include <unordered_map>
using namespace std;

// Instead of remembering cur word to solution
// We can remember cur index to solution!
class Solution {
public:
  // any from 10 to 26
  bool valid(char first, char second) {
    return first == '1' || (first == '2' && second <= '6');
  }

  int dfs(int i, string& s, unordered_map<int, int>& indexToSol) {
    if(indexToSol.find(i) != indexToSol.end()) return indexToSol[i]; // memoised
    if(i == s.size()) return 1; // it is a valid sol!
    int sum = 0;
    // Take one digit
    if(s[i] != '0') {
      sum += dfs(i+1, s, indexToSol);
    }
    // Take 2 digits
    if(i < s.size() - 1 && valid(s[i], s[i+1])) {
      sum += dfs(i+2, s, indexToSol);
    }
    indexToSol[i] = sum;
    return sum;
  }

  int numDecodings(string s) {
    unordered_map<int, int> indexToSol;
    return dfs(0, s, indexToSol);
  }
};

// MLE
class Solution {
public:
  // any from 10 to 26
  bool valid(char first, char second) {
    return first == '1' || (first == '2' && second <= '6');
  }

  // ('A'-1) is to convert digit to char
  int dfs(int i, string& s, unordered_map<string, int>& digitsToSol, string cur) {
    if(digitsToSol.find(cur) != digitsToSol.end()) return digitsToSol[cur];
    if(i == s.size()) return 1; // it is a valid sol!
    int sum = 0;
    // Take one digit
    if(s[i] != '0') {
      string next = cur;
      next += s[i] + ('A'-1);
      sum += dfs(i+1, s, digitsToSol, next);
    }
    // Take 2 digits
    if(i < s.size() - 1 && valid(s[i], s[i+1])) {
      string next = cur;
      next += (10*s[i] + s[i+1]) + ('A'-1);
      sum += dfs(i+2, s, digitsToSol, next);
    }
    digitsToSol[cur] = sum;
    return sum;
  }

  int numDecodings(string s) {
    unordered_map<string, int> digitsToSol; // word in digits to count it is gonna return
    return dfs(0, s, digitsToSol, "");
  }
};
