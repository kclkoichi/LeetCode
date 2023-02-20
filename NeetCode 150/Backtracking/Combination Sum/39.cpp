#include <vector>
#include <iostream>
#include <unordered_set>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int evaluateSum(vector<int> v) {
      int sum = 0;
      for(int i : v) sum+=i;
      return sum;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> result;
      vector<vector<int>> searching;
      for(int i : candidates) {
        searching.push_back(vector<int> { i }); // in case a candidate is a solution
        if(i == target) result.push_back(vector<int> { i });
      }
      return bfs(candidates, target, searching, result);
    }

    vector<vector<int>> bfs(vector<int>& candidates, int target, vector<vector<int>>&searching, vector<vector<int>>&result) {
      unordered_set<string> alreadyTried;
      vector<vector<int>> nextSearch;
      while(searching.size() != 0) {
        for(int i = 0; i < searching.size(); i++) {
          for(int j = 0; j < candidates.size(); j++) {
            vector<int> newPotential = searching[i];
            newPotential.push_back(candidates[j]);
            // Check if we already checked this combination, if yes give up
            map<int, int> mapping;
            for(int i : newPotential) mapping[i]++;
            string s = "";
            // Map this combination of numbers and their count to a string
            for(auto a = mapping.begin(); a != mapping.end(); a++) s+=to_string(a->first)+"->"+to_string(a->second) + ",";
            if(alreadyTried.find(s) == alreadyTried.end()) {
              alreadyTried.insert(s);
              int sum = evaluateSum(newPotential);
              if(sum < target) {
                nextSearch.push_back(newPotential);
              } else if(sum == target) {
                result.push_back(newPotential);
              }
              // Give up if sum > target
            }
          }
        }
        searching = nextSearch;
        nextSearch.clear();
      }
      return result;
    }
};

// LeetCode
int main() {
  Solution s;
  vector<int> v { 2,3,5 };
  for(vector<int> v : s.combinationSum(v, 8)) {
    for(int i : v) {
      cout << to_string(i) << " ";
    }
    cout << "\n";
  }
  return 0;
}