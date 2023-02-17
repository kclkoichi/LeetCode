#include <cstdint>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // return __builtin_popcount(n); // Counts number of 1s in bit

        // Brian Kernighan’s Algorithm
        // int count = 0;
        // while(n > 0) {
        //   n = n & (n-1);
        //   count++;
        // }
        // return count;

        // Other technique
        int count = 0;
        while(n > 0){
          if(n&1 == 1) count++;
          n = n>>1;
        }
        return count;
    }
};