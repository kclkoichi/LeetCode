#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  int findKthPositive(vector<int>& arr, int k) {
    vector<int> ideal = vector<int>(3000);
    for(int i = 1; i <= 3000; i++) ideal[i-1] = i;
    int missing = 0;
    int i = 0, idealIndex = 0;
    while(i < arr.size()) {
      if(arr[i] == ideal[idealIndex]) {
        i++; idealIndex++;
      } else {
        missing++;
        if(missing == k) return ideal[idealIndex];
        idealIndex++;
      }
    }
    // out of bounds of arr
    missing++;
    while(missing != k) {
      idealIndex++;
      missing++;
    }
    return ideal[idealIndex];
  }
};