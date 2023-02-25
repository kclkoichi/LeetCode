#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> counter;
    for(char c : tasks) counter[c]++;
    int count = 0; // Max Frequency of any character
    for(auto a : counter) count = max(count, a.second);
    // At least: maxfreq char + n breaks + maxfreq char + n breaks + ... 
    int sol = (count-1)*(1+n);
    // Add the last occurence of that char (or these, if multiple chars had same frequency)
    for(auto a : counter) if(count == a.second) sol++;
    // Maybe the total breaks were not enough to do every tasks (use every chars)...
    // In that case it's tasks.size()
    return max(sol, (int)tasks.size());
  }
};

int main() {
  Solution s;
  vector<char> v { 'A','A','A','B','B','B','C','D','E','F','G','H','I','J','K' };
  s.leastInterval(v, 7);
  return 0;
}