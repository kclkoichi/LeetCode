#include <vector>
using namespace std;

class Solution {
public:
    int countOnes(int n) {
        int count = 0;
        while(n) {
          count++;
          n = n&(n-1);
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> sol = vector<int> { 0 };
        for(int i = 1; i <= n; i++) {
          sol.push_back(countOnes(i));
        }
        return sol;
    }
};