#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
      vector<string> sol = vector<string>(n);
      for(int i = 1; i <= n; i++) {
        string s = "";
        if(i % 3 == 0) s+="Fizz";
        if(i % 5 == 0) s+="Buzz";
        if(s.length() == 0) s = to_string(i);
        sol[i-1] = s;
      }
      return sol;
    }
};