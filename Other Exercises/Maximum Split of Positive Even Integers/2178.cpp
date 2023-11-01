#include <vector>
using namespace std;

typedef long long ll;

class Solution {
public:
  vector<ll> maximumEvenSplit(ll finalSum) {
    if(finalSum % 2 == 1) return {}; // odd
    vector<ll> v;
    ll sum = 0;
    ll times = 1;
    while(sum < finalSum) {
      sum += 2*times;
      v.push_back(2*times);
      times++;
    }
    // there is no need to delete if sum is already perfect
    if(finalSum < sum) v.erase(find(v.begin(), v.end(), sum - finalSum));
    return v;
  }
};