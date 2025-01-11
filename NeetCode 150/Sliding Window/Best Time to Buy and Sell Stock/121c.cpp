#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int best = -1;
        for(int i = prices.size() - 1; i >= 0; i--) {
            best = max(best, prices[i]);
            res = max(res, best - prices[i]);
        }
        return res;
    }
};
