#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    priority_queue<tuple<int, int, char>> min_pq; // Comparison: 1st int biggest then 2nd int biggest then 3rd char
    unordered_map<char, int> counter;
    for(char c : tasks) counter[c]++;
    for(auto a : counter) min_pq.push(make_tuple(a.second, 0, a.first)); // how many tasks of this type, time of last execution, task name

    int i = 0;
    while(!min_pq.empty()) {
      i++;
      bool foundExecutable = false;
      vector<tuple<int, int, char>> temp;
      tuple<int, int, char> curTask = min_pq.top();
      int lastCount = INT_MAX;
      int lastTimeNotExec = INT_MAX;
      while(!foundExecutable && !min_pq.empty()) {
        curTask = min_pq.top();
        // cout << to_string(get<0>(curTask)) << to_string(get<1>(curTask)) << get<2>(curTask) << endl;
        // 1st execution || time elapsed since last execution > n
        if(get<1>(curTask) == 0 || i - (get<1>(curTask) * -1) > n) {
          // can execute task
          min_pq.pop();
          counter[get<2>(curTask)]--;
          if(counter[get<2>(curTask)] > 0) min_pq.push(make_tuple(counter[get<2>(curTask)], i*-1, get<2>(curTask)));
          foundExecutable = true;
        } else {
          // Last time something was not executed, its (not) execution time was smaller AND it had more tasks
          if(get<1>(curTask)*-1 > lastTimeNotExec && get<0>(curTask) < lastCount) break;
          // if(get<0>(curTask) < lastCount) break;
          lastTimeNotExec = min(lastTimeNotExec, get<1>(curTask)*-1);
          lastCount = min(lastCount, get<0>(curTask));
          temp.push_back(curTask);
          min_pq.pop();
        }
      }
      for(auto a : temp) min_pq.push(a);
      temp.clear();
    }

    return i;
  }
};

int main() {
  Solution s;
  vector<char> v { 'A','A','A','B','B','B','C','D','E','F','G','H','I','J','K' };
  s.leastInterval(v, 7);
  return 0;
}