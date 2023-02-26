#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

long getMaxOrSum(vector<int> arr, int k) {
  vector<int> mapper = vector<int>(7); // arr[i] is max 10^6
  for(int i = 0; i < arr.size(); i++) {
    int cur = arr[i];
    int j = 0;
    while(cur) {
      if((cur & 1) == 1) mapper[j]++;
      cur >>= 1;
      j++;
    }
  }
  vector<long> orSums = vector<long>(arr.size()); // Vector of total or sum except itself
  for(int i = 0; i < orSums.size(); i++) {
    vector<int> copy = mapper;
    int cur = arr[i];
    int j = 0;
    while(cur) {
      if((cur & 1) == 1) copy[j]--;
      cur >>= 1;
      j++;
    }
    long sum = 0;
    for(int k = copy.size() - 1; k >= 0; k--) {
      if(copy[k]) sum += pow(2, k);
    }
    orSums[i] = sum;
  }
  vector<long> allKs = vector<long>(arr.size()); // Vector of every element multiplied k times
  for(int i = 0; i < allKs.size(); i++) {
    allKs[i] = arr[i];
    for(int j = 1; j <= k; j++) {
      allKs[i] <<= 1;
    }
  }

  long maxOrSum = 0;
  for(int i = 0; i < arr.size(); i++) {
    if((orSums[i] | allKs[i]) > maxOrSum) maxOrSum = orSums[i] | allKs[i];
  }
  return maxOrSum;
}

int main() {
  cout << to_string(getMaxOrSum(vector<int> {12, 9}, 2)) << endl;
  return 0;
}