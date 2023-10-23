#include <vector>
#include <map>
using namespace std;

class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    map<int, int> loserMap;
    for(vector<int> match: matches) {
      int winner = match[0];
      int loser = match[1];
      if(loserMap.find(winner) == loserMap.end()) loserMap[winner] = 0;
      loserMap[loser]++;
    }

    vector<int> noLoseTeams;
    vector<int> lostOneTeams;

    for(auto [team, loseCount]: loserMap) {
      if(loseCount == 0) noLoseTeams.push_back(team);
      if(loseCount == 1) lostOneTeams.push_back(team);
    }

    return {noLoseTeams, lostOneTeams};
  }
};