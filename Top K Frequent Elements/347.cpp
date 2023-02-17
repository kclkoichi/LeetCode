#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      priority_queue< pair<int, int> > pq; // <count, element> because sorted with first
      unordered_map<int, int> counter;
      for(int i : nums) {
        counter[i]++;
      }
      for(auto a : counter) {
        pq.push(pair(a.second, a.first));
      }
      vector<int> sol = vector<int>(k);
      for(int i = 0; i < k; i++) {
        sol[i] = pq.top().second;
        pq.pop();
      }
      return sol;
    }
};