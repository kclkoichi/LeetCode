#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
  vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    unordered_map<string, int> counter; // recipe to remaining ingredients needed count
    unordered_map<string, vector<string>> mapper; // ingredient to recipes
    for(int i = 0; i < recipes.size(); i++) {
      string recipe = recipes[i];
      counter[recipe] = ingredients[i].size();
      for(string ingredient : ingredients[i]) {
        mapper[ingredient].push_back(recipe);
      }
    }

    vector<string> res;
    for(int i = 0; i < supplies.size(); i++) {
      string supply = supplies[i];
      if(mapper.find(supply) != mapper.end()) {
        for(string recipe: mapper[supply]) {
          counter[recipe]--;
          if(counter[recipe] == 0) {
            res.push_back(recipe);
            supplies.push_back(recipe);
          }
        }
      }
    }
    return res;
  }
};