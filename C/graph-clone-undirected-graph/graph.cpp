/**
 * Clone an undirected graph. Each node in the graph contains a label and a list
 * of its neighbors. The graph node is defined as:
 * struct UndirectedGraphNode {
 *  int label;
 *  vector<UndirectedGraphNode *> neighbors;
 *  UndirectedGraphNode(int x) : label(x) {}
 * };
 *
 * Time complexity: O(|V| + |E|), where |V| is the number of vertices and |E| is
 * the number of edges.
 * Space complexity: O(|V|).
 *
 * Explanation: you need to perform BFS. The trick here is that you need to keep
 * a map of the nodes you are creating because you will need to retrieve them
 * eventually when checking the neighbors of the vertices. For example, given
 * the graph:
 *
 * 1---2
 * |   |
 * 4---3
 *
 * Suppose you start from vertex 1, you will need to create vertex 2 and 4.
 * Later, when checking vertex 2 you will need to retrieve it, and when checking
 * its neighbors you will need to retrieve vertices 1 and 4. So, instead of
 * using a visited variable in your BFS use a map<key, UndirectedGraphNode*>.
 * You start inserting in this map the source node, after for each vertex that
 * your current vertex is connected you check if it exists in the map, if not,
 * you create it and add to the map.
 * Notice, the key must be the address of the node and not its label, because
 * the exercise didn't say the label would be unique, but we know the address
 * is.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {}
};

UndirectedGraphNode* cloneGraph(UndirectedGraphNode *src) {
  unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> nodeMap;
  queue<UndirectedGraphNode *> q;

  q.push(src);
  nodeMap[src] = new UndirectedGraphNode(src->label);

  while (!q.empty()) {
    UndirectedGraphNode *u = q.front();
    q.pop();

    for (UndirectedGraphNode *v : (u->neighbors)) {
      if (nodeMap.find(v) == nodeMap.end()) {
        nodeMap[v] = new UndirectedGraphNode(v->label);
        q.push(v);
      }

      (nodeMap[u]->neighbors).push_back(nodeMap[v]);
    }
  }

  return nodeMap[src];
}

int main() {
  UndirectedGraphNode *n1 = new UndirectedGraphNode(1);
  UndirectedGraphNode *n2 = new UndirectedGraphNode(2);
  UndirectedGraphNode *n3 = new UndirectedGraphNode(3);
  UndirectedGraphNode *n4 = new UndirectedGraphNode(4);

  vector<UndirectedGraphNode *> v;
  v.push_back(n2);
  v.push_back(n4);
  n1->neighbors = v;

  v.clear();
  v.push_back(n1);
  v.push_back(n3);
  n2->neighbors = v;

  v.clear();
  v.push_back(n2);
  v.push_back(n4);
  n3->neighbors = v;

  v.clear();
  v.push_back(n3);
  v.push_back(n1);
  n4->neighbors = v;

  UndirectedGraphNode *clone = cloneGraph(n1);

  return 0;
}