#include <vector>
#include <list>
using namespace std;

class MyCalendar {
public:
  // Use set (binary tree)!!
  list<vector<int>> intervals = list<vector<int>>();
  MyCalendar() {}
  
  bool book(int start, int end) {
    auto it = intervals.begin();
    while(it != intervals.end()) {
      // overlap check
      if(start < (*it)[1] && end > (*it)[0]) {
        return false;
      }
      if(end <= (*it)[0]) {
        break;
      }
      it++;
    }
    intervals.insert(it, { start, end }); 
    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */