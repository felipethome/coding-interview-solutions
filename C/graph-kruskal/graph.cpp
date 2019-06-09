/**
 * Kruskal's algorithm for a graph represented as Edges List.
 *
 * Time complexity: O(|E|log|E|), where |E| is the number of edges and this
 * complexity comes from the sorting.
 * Space complexity: O(|E| + |V|), where |V| is the number of vertices.
 *
 * Explanation: sort the edges in ascending order and iterate through them.
 * Using the Disjoint Sets to know if two vertices are already connected or
 * not. For that, at each edge check if the "from" and "to" nodes belongs
 * to the same set with findSet() and if they do ignore, otherwise joing the
 * sets and add this edge to the answer.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

#include "disjointsets.h"

using namespace std;

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

/* --- Disjoint Sets --- */
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

int main() {
  vector<Edge> edges;
  edges.push_back(*(new Edge(0, 1, 3)));
  edges.push_back(*(new Edge(0, 3, 1)));
  edges.push_back(*(new Edge(1, 2, 1)));
  edges.push_back(*(new Edge(1, 3, 3)));
  edges.push_back(*(new Edge(2, 3, 1)));
  edges.push_back(*(new Edge(2, 4, 5)));
  edges.push_back(*(new Edge(2, 5, 4)));
  edges.push_back(*(new Edge(3, 4, 6)));
  edges.push_back(*(new Edge(4, 5, 2)));

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