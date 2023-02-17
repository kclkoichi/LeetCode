#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int sumSquare(int n) {
      int result = 0;
      string number = to_string(n);
      for(char c : number) {
        result += (c - '0') * (c - '0');
      }
      return result;
    }

    bool isHappy(int n) {
        unordered_set<int> visited;
        int actual = n;
        visited.insert(actual);
        bool isOne = n == 1;
        while(!isOne) {
          actual = sumSquare(actual);
          if(visited.find(actual) != visited.end()) return false;
          if(actual == 1) return true;
          visited.insert(actual);
        }
        return isOne; // only happen when n is 1
    }
};