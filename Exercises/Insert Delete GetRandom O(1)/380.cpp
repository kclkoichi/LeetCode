#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
public:
    vector<int> vals;
    unordered_map<int, int> valToIndex;

    RandomizedSet() {}
    
    bool insert(int val) {
        if(valToIndex.find(val) == valToIndex.end()) {
            vals.push_back(val);
            valToIndex[val] = vals.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(valToIndex.find(val) != valToIndex.end()) {
            int index = valToIndex[val]; // index of val
            vals[index] = vals[vals.size()-1]; // swap last element with val
            vals.pop_back(); // remove val (now last element)
            valToIndex[vals[index]] = index; // update prev. last element's index
            valToIndex.erase(val); // remove val from map
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return vals[rand() % vals.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */