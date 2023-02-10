#include <vector>
#include <algorithm>
using namespace std;

class KthLargest {
public:
    vector<int> vect;
    int kthlargest;

    KthLargest(int k, vector<int>& nums) {
        kthlargest = k;
        sort(nums.begin(), nums.end());
        vect = nums;
    }
    
    int add(int val) {
      vect.emplace_back(val);
      int next = vect.size() - 1;
      while(next >= 1 && vect[next - 1] > vect[next]) {
          int temp = vect[next];
          vect[next] = vect[next - 1];
          vect[next - 1] = temp; 
          next--;
      }
      return vect[vect.size() - kthlargest];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */