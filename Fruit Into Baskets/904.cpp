#include <vector>
#include <iostream> 
#include <unordered_map> 
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      unordered_map<int, int> positions;
      int prevFruit = -1;
      int max = 0;
      int countFruit = 0;
      int types = 0;
      for(int i = 0; i < fruits.size(); i++) {
        int actFruit = fruits[i];
        if(positions.find(actFruit) == positions.end()) {
          types++;
          countFruit++;
          if(types > 2) {
            auto a = positions.begin();
            auto b = ++positions.begin();
            // Comparing last index of fruit
            if(a->second > b->second) {
              positions.erase(b);
              countFruit = i - a->second + 1;
            } else {
              positions.erase(a);
              countFruit = i - b->second + 1;
            }
            types--;
          }
          positions[actFruit] = i;
        } else {
          countFruit++;
          if(actFruit != prevFruit) positions[actFruit] = i;
        }
        if(countFruit > max) max = countFruit;
        prevFruit = actFruit;
      }

      return max;
    }
};

int main() {
  Solution s;
  vector<int> vect {3,3,3,1,2,1,1,2,3,3,4};
  cout << s.totalFruit(vect) << endl;
  return 0;
}