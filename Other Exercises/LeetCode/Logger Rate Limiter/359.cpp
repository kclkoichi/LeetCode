#include <string>
#include <unordered_map>
using namespace std;

class Logger {
public:
  unordered_map<string, int> stringToIndex = unordered_map<string, int>();
  Logger() {}
  
  bool shouldPrintMessage(int timestamp, string message) {
    if(stringToIndex.find(message) == stringToIndex.end()) {
      stringToIndex[message] = timestamp;
      return true;
    } else {
      if(stringToIndex[message] + 10 <= timestamp) {
        stringToIndex[message] = timestamp;
        return true;
      }
    }
    return false;
  }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */