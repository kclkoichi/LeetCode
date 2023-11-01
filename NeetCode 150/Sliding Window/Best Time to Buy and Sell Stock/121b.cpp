#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  // dp: at every point in time, you want to know which max stock price will appear in the future
  int maxProfit(vector<int>& prices) {
    int maxSoFar = prices[prices.size() - 1];
    vector<int> fromRight = vector<int>(prices.size());
    for(int i = prices.size() - 1; i >= 0; i--) {
      maxSoFar = max(maxSoFar, prices[i]);
      fromRight[i] = maxSoFar;
    }

    int maxProf = 0;
    for(int i = 0; i < prices.size(); i++) {
      int maxStockPriceInFuture = fromRight[i];
      maxProf = max(maxProf, maxStockPriceInFuture - prices[i]);
    }
    return maxProf;
  }

  // two pointer: l is current min, difference with r is profit
  // As soon as r is smaller than l, can update l to r 
  // Because you'll make more profit by buying at the lowest price time in the future (if you remember the max potential profit so far)
  int maxProfit(vector<int>& prices) {
    int minPriceIndex = 0;
    int minPrice = prices[0];

    int maxProf = 0;
    int r = 1;
    while(r < prices.size()) {
      if(prices[r] < minPrice) {
        minPriceIndex = r;
        minPrice = prices[r];
      } else {
        maxProf = max(maxProf, prices[r] - prices[minPriceIndex]);
      }
      r++;
    }
    return maxProf;
  }
};