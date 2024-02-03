#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool canMake(string tryingToMake, unordered_map<string, vector<string>>& AL, unordered_set<string>& have, unordered_set<string>& visited) {
    if(have.find(tryingToMake) != have.end()) return true;
    if(AL[tryingToMake].empty()) return false; // Can't make it if we don't have it and there s no way to create it
    if(visited.find(tryingToMake) != visited.end()) return false; // there's a cycle
    visited.insert(tryingToMake);
    for(string needed: AL[tryingToMake]) {
      if(!canMake(needed, AL, have, visited)) return false;
    }
    have.insert(tryingToMake);
    return true;
  }

  vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    unordered_map<string, vector<string>> AL;
    for(int i = 0; i < recipes.size(); i++) {
      AL[recipes[i]] = ingredients[i];
    }

    unordered_set<string> have;
    for(string supply: supplies) have.insert(supply);

    vector<string> res;
    unordered_set<string> visited;
    for(string recipe: recipes) {
      if(canMake(recipe, AL, have, visited)) res.push_back(recipe);
    }
    return res;
  }
};
