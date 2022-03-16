/*
 * 133. Clone Graph
 * Given a reference of a node in a connected undirected graph.
 * Return a deep copy (clone) of the graph.
 * Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
 * class Node {
 *  public int val;
 *  public List<Node> neighbors;
 * }
 * Test case format:
 * For simplicity, each node's value is the same as the node's index (1-indexed).
 * For example, the first node with val == 1, the second node with val == 2, and so on.
 * The graph is represented in the test case using an adjacency list.
 * An adjacency list is a collection of unordered lists used to represent a finite graph.
 * Each list describes the set of neighbors of a node in the graph.
 * The given node will always be the first node with val = 1.
 * You must return the copy of the given node as a reference to the cloned graph.
 * */

#include <vector>
#include <memory>
#include <unordered_map>

// Definition for a Node.
class Node {
public:
  int val;
  std::vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node*>();
  }
  Node(int _val, std::vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

#define umap std::unordered_map<Node*, Node*>

class Solution {
private:
  void dfs(umap &map, Node* node) {
    if (map.find(node) != map.end())  // node already exist in map
      return;
    map[node] = new Node(node->val);
    for (auto &nbr : node->neighbors)
      dfs(map, nbr);
  }
public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr)
      return nullptr;
    umap map;
    Node* root = new Node(node->val);
    map[node] = root;
    for (auto &neighbor: node->neighbors)
      dfs(map, neighbor);
    for (auto &n: map) {
      Node* src = n.first;
      Node* dst = n.second;
      for (auto& neighbour : src->neighbors)
        dst->neighbors.push_back(map[neighbour]);
    }
    return root;
  }
};

int main() {
  {
    std::unique_ptr<Node> node1 = std::make_unique<Node>(1);
    std::unique_ptr<Node> node2 = std::make_unique<Node>(2);
    std::unique_ptr<Node> node3 = std::make_unique<Node>(3);
    std::unique_ptr<Node> node4 = std::make_unique<Node>(4);

    node1->neighbors = { node2.get(), node3.get(), node4.get() };
    node2->neighbors = { node1.get(), node3.get(), node4.get() };
    node3->neighbors = { node2.get(), node1.get(), node4.get() };
    node4->neighbors = { node2.get(), node3.get(), node1.get() };

    Solution s;
    Node* res = s.cloneGraph(node1.get());
  }
  
  {
    std::unique_ptr<Node> node1 = std::make_unique<Node>(1);
    std::unique_ptr<Node> node2 = std::make_unique<Node>(2);
    std::unique_ptr<Node> node3 = std::make_unique<Node>(3);

    node1->neighbors = { node2.get(), node3.get()};
    node2->neighbors = { node1.get()};
    node3->neighbors = { node1.get()};

    Solution s;
    Node* res = s.cloneGraph(node1.get());
  }
  
  return 0;
}