#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int min = 2e9;
      int maxProfit = 0;
      for(int i = 0; i < prices.size(); i++) {
        if(prices[i] - min > maxProfit) maxProfit = prices[i] - min;
        if(prices[i] < min) min = prices[i];
      }
      return maxProfit;
    }
};

int main() {
  Solution s;
  vector<int> vect {3,4,5,6,4,3,2,4};
  cout << s.maxProfit(vect) << endl;

  return 0;
}