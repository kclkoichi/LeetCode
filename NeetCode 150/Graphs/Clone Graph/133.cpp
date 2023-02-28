#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Node {
public:
  int val;
  vector<Node*> neighbors;
  Node() {
      val = 0;
      neighbors = vector<Node*>();
  }
  Node(int _val) {
      val = _val;
      neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
      val = _val;
      neighbors = _neighbors;
  }
};

class Solution {
public:
  Node* cloneGraph(Node* node) {
    if(node == nullptr) return nullptr;
    unordered_map<Node*, Node*> visited;
    Node* copy = new Node(node->val);
    visited[node] = copy;
    vector<Node*> neighbors;
    for(Node* neighbor : node->neighbors) {
      if(visited.find(neighbor) == visited.end()) {
        neighbors.push_back(cloneNeighbor(neighbor, visited));
      } else {
        neighbors.push_back(visited.find(neighbor)->second);
      }
    }
    copy->neighbors = neighbors;
    return copy;
  }

  Node* cloneNeighbor(Node* node, unordered_map<Node*, Node*>& visited) {
    Node* copy = new Node(node->val);
    visited[node] = copy;
    vector<Node*> neighbors;
    for(Node* neighbor : node->neighbors) {
      if(visited.find(neighbor) == visited.end()) {
        neighbors.push_back(cloneNeighbor(neighbor, visited));
      } else {
        neighbors.push_back(visited.find(neighbor)->second);
      }
    }
    copy->neighbors = neighbors;
    return copy;
  }
};

int main() {
  Solution s;
  Node* n = new Node(1);
  Node* m = new Node(2);
  Node* l = new Node(3);
  n->neighbors.push_back(m);
  n->neighbors.push_back(l);
  s.cloneGraph(n);
  return 0;
}