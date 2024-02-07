#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Logger {
public:
  unordered_map<string, int> timer;
  unordered_map<int, vector<string>> timeToStrings;
  queue<int> timeline;
  Logger() {}
  
  bool shouldPrintMessage(int timestamp, string message) {
    if(timer.find(message) != timer.end()) {
      if(timestamp - timer[message] < 10) {
        return false;
      }
    }

    // Clear older than 10s
    while(!timeline.empty() && timestamp - timeline.front() >= 10) {
      int oldTime = timeline.front(); 
      timeline.pop();
      for(string old: timeToStrings[oldTime]) timer.erase(old);
      timeToStrings.erase(oldTime);
    }

    timer[message] = timestamp;
    timeToStrings[timestamp].push_back(message);
    timeline.push(timestamp);

    return true;
  }
};