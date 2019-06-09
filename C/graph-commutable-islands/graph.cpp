/**
 * There are n islands and there are many bridges connecting them. Each bridge
 * has some cost attached to it. We need to find bridges with minimal cost such
 * that all islands are connected.
 * It is guaranteed that input data will contain at least one possible scenario
 * in which all islands are connected with each other.
 *
 * Time complexity: O(|E|log|E|), where |E| is the number of edges and this
 * complexity comes from the sorting.
 * Space complexity: O(|E| + |V|), where |V| is the number of vertices.
 *
 * Explanation: apply Kruskal's algorithm.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* --- Disjoint Sets --- */
struct Node {
  int rank, val;
  Node *parent;
  Node(int x, int y, Node *z) : rank(x), val(y), parent(z) {}
};

unordered_map<int, Node*> nodeMap;

Node *makeSet(int val) {
  Node *n = new Node(0, val, NULL);
  n->parent = n;
  nodeMap[val] = n;
  return n;
}

Node *findSetUtil(Node *n) {
  if (n == n->parent) return n;
  n->parent = findSetUtil(n->parent);
  return n->parent;
}

Node *findSet(int val) {
  if (nodeMap.find(val) != nodeMap.end()) {
    return findSetUtil(nodeMap[val]);
  }
  return NULL;
}

void join(int val1, int val2) {
  Node *n1 = findSet(val1);
  Node *n2 = findSet(val2);

  if (n1 == n2 || !n1 || !n2) return;

  if (n1->rank >= n2->rank) {
    if (n1->rank == n2->rank) (n1->rank)++;
    n2->parent = n1;
  }
  else {
    n1->parent = n2;
  }
}

/* --- Kruskal's Algorithm --- */
struct Edge {
  int from, to, weight;
  Edge(int x, int y, int z) : from(x), to(y), weight(z) {}
};

bool cmp(Edge ed1, Edge ed2) {
  return ed1.weight <= ed2.weight;
}

vector<Edge> kruskal(vector<Edge> &edges, vector<int> &vertices) {
  vector<Edge> ans;

  sort(edges.begin(), edges.end(), cmp);

  for (int v : vertices) makeSet(vertices[v]);

  for (Edge ed : edges) {
    Node *n1 = findSet(ed.from);
    Node *n2 = findSet(ed.to);

    if (n1 != n2) {
      join(ed.from, ed.to);
      ans.push_back(ed);
    }
  }

  return ans;
}

int main() {
  vector<Edge> edges;
  edges.push_back(*(new Edge(1, 2, 1)));
  edges.push_back(*(new Edge(2, 3, 4)));
  edges.push_back(*(new Edge(1, 4, 3)));
  edges.push_back(*(new Edge(4, 3, 2)));
  edges.push_back(*(new Edge(1, 3, 10)));

  vector<int> vertices;
  vertices.push_back(0);
  vertices.push_back(1);
  vertices.push_back(2);
  vertices.push_back(3);
  vertices.push_back(4);
  vertices.push_back(5);

  vector<Edge> r = kruskal(edges, vertices);

  for (int i = 0; i < r.size(); i++) {
    cout << "from: " << r[i].from << " to: " << r[i].to << endl;
  }
  cout << endl;

  return 0;
}