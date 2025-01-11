#include <string>
using namespace std;

class Solution {
public:
    void swapChar(string& n, int a, int b) {
        char tmp = n[a];
        n[a] = n[b];
        n[b] = tmp;
    }

    int maximumSwap(int num) {
        string n = to_string(num);
        int res = num;
        int biggestDigitIndex = n.size() - 1;
        for(int i = n.size() - 1; i >= 0; i--) {
            if(n[i] - '0' > n[biggestDigitIndex] - '0') biggestDigitIndex = i;
            // If better to swap
            if(n[biggestDigitIndex] - '0' > n[i] - '0') {
                swapChar(n, i, biggestDigitIndex);
                res = max(res, stoi(n));
                swapChar(n, i, biggestDigitIndex);
            }
        }

        return res;
    }
};
