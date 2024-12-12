#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return; // nothing to merge

        int index = m+n-1;
        int l = m-1;
        int r = n-1;
        while(l >= 0 && r >= 0) {
            if(nums1[l] > nums2[r]) {
                nums1[index] = nums1[l];
                l--;
            } else {
                nums1[index] = nums2[r];
                r--;
            }
            index--;
        }

        // Only one of them will be used
        while(l >= 0) {
            nums1[index] = nums1[l];
            l--;
            index--;
        }
        while(r >= 0) {
            nums1[index] = nums2[r];
            r--;
            index--;
        }
    }
};
