#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; // max PQ
        for(int i : stones) pq.push(i);

        while(pq.size() > 1) {
          int stone1 = pq.top();
          pq.pop();
          int stone2 = pq.top();
          pq.pop();
          int newStone = stone1 - stone2;
          if(newStone > 0) pq.push(newStone);
        }

        return pq.size() > 0 ? pq.top() : 0;
    }
};