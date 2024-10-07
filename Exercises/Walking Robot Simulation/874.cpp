#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // Get direction after turning right
  char turnRight(char direction) {
    switch(direction) {
      case 'N':
        return 'E';
      case 'E':
        return 'S';
      case 'S':
        return 'W';
      case 'W':
        return 'N';
    }
    return '?'; // Should never happen
  }

  // Get direction after turning left
  char turnLeft(char direction) {
    switch(direction) {
      case 'N':
        return 'W';
      case 'W':
        return 'S';
      case 'S':
        return 'E';
      case 'E':
        return 'N';
    }
    return '?'; // Should never happen
  }

  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    // Maintain obstacle info
    unordered_map<int, unordered_set<int>> obstaclesMap; // x, y == E, N
    for(vector<int> obstacle: obstacles) {
      obstaclesMap[obstacle[0]].insert(obstacle[1]);
    }

    // Maintain position and direction info of robot
    int north = 0;
    int east = 0;
    char direction = 'N';
    int maxDist = 0;

    // Execute commands
    for(int command: commands) {
      if(command == -1) {
        direction = turnRight(direction);
      } else if(command == -2) {
        direction = turnLeft(direction);
      } else {
        // Move steps steps
        int steps = command;
        switch(direction) {
          case 'N':
            for(int i = 1; i <= steps; i++) {
              if(obstaclesMap[east].find(north+1) != obstaclesMap[east].end()) {
                // We need to check next cell in our direction, so north+1
              } else {
                north++;
              }
            }
            break;
          case 'E':
            for(int i = 1; i <= steps; i++) {
              if(obstaclesMap[east+1].find(north) != obstaclesMap[east].end()) {
                // next cell to go is obstacle!
              } else {
                east++;
              }
            }
            break;
          case 'S':
            for(int i = 1; i <= steps; i++) {
              if(obstaclesMap[east].find(north-1) != obstaclesMap[east].end()) {
                // next cell to go is obstacle!
              } else {
                north--; // south is opposite of north
              }
            }
            break;
          case 'W':
            for(int i = 1; i <= steps; i++) {
              if(obstaclesMap[east-1].find(north) != obstaclesMap[east].end()) {
                // next cell to go is obstacle!
              } else {
                east--; // west is opposite of east
              }
            }
            break;
        }
        // Update max distance so far, it might be higher after we move
        maxDist = max(maxDist, north*north + east*east);
      }
    }

    return maxDist;
  }
};