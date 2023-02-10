#include <queue>
#include <vector>
using namespace std;

// Custom comparator to make a min heap
// does same as comparator greater<int>
class Compare {
  public:
    bool operator() (int a, int b) {
        return a > b;
    }
};

class KthLargest {
public:
    // PQ using custom comparator
    priority_queue<int, vector<int>, Compare> pq;
    int kthlargest;

    KthLargest(int k, vector<int>& nums) {
        kthlargest = k;
        for(int i : nums) pq.push(i);
        while(pq.size() > kthlargest) pq.pop(); // Pop all smaller than kth largest
    }
    
    int add(int val) {
      pq.push(val);
      if(pq.size() > kthlargest) pq.pop(); // pop k+1 e.g 4th largest if want 3rd largest
      return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */