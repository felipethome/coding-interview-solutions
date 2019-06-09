/**
 * Prim's Algorithm for a graph represented as Adjacency List.
 *
 * Time complexity: O(|E| * log|V|), where |E| is the number of edges and |V|
 * is the number of vertices.
 * Space complexity: O(|E| + |V|).
 *
 * Explanation: you will need a Min Heap with Decrease operation and the
 * C++ standard library doesn't support this operation, so you need to implement
 * your own or use a set (personally in a competition I would go with the set).
 * Prim's Algorithm, different from Kruskal's Algorithm, has a source node for
 * the MST. The idea is to check from which of the vertices already visited
 * we have the edge with the smallest weight.
 * We initialize our Heap with 0 cost for the source vertex and Infinity for
 * every other vertex in the graph. Then, We start from the source and
 * check its edges, after we pick the edge with smallest weight (notice, we
 * don't have another choice and an edge needs to be picked because we need to
 * start our MST from the source vertex). In the next iteration we look at the
 * edges that comes from the "to" vertex of the just picked edge and do the
 * same thing. After this second check we need, again, to get the edge with the
 * smallest weight (as before an edge needs to be picked so we can continue to
 * build our MST). We keep doing this until there are no more nodes in Heap.
 * For example:
 *
 * Given,
 *       1
 *   a ---- c
 *   |     /
 * 2 |   / 3
 *   | /
 *   b
 *
 * Source: a
 *
 * #1 Iteration
 * Heap:       Map Vertex->Edge:    Result:
 * a - 0
 * b - Inf
 * c - Inf
 *
 * #2 Iteration
 * Heap:       Map Vertex->Edge:    Result:
 * c - 1       c -> (a, c)          (a, c)
 * b - 2       b -> (a, b)
 *
 * #3 Iteration
 * Heap:       Map Vertex->Edge:    Result:
 *             c -> (a, c)          (a, c)
 * b - 2       b -> (a, b)
 * In this iteration "c" just has one edge to b and it is not smaller than the
 * already visited (a, b) so we don't do anything.    
 *
 * Heap:       Map Vertex->Edge:    Result:
 *             c -> (a, c)          (a, c), (a, b)
 *             b -> (a, b)
 *
 * Notice, the map Vertex->Edge is used to identify the edge that gives the
 * weight we currently have in the heap for that vertex. So, every time we
 * remove a vertex from the heap because it has the smallest edge with
 * extractMin() we go to this map to get the edge that we need to add to our
 * result.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

#include "../binary-min-heap-with-decrease/heap.h"

using namespace std;

struct Edge {
  int to, weight;
  Edge(int x, int y) : to(x), weight(y) {}
};

vector<pair<int, int>> prim(vector<vector<Edge>> &g, int src) {
  int numVertices = g.size();
  // MinHeap with decrease operations and vertices identified by integers.
  MinHeap<int> heap;
  // Map of vertex to Edge, so we know which edge has the smallest weight to
  // this vertex.
  vector<pair<int, int>> edges(numVertices);
  // The edges in the MST.
  vector<pair<int, int>> ans;

  // Initialize heap with 0 cost to the source vertex and Infinity to every
  // other vertex.
  for (int i = 0; i < numVertices; i++) {
    if (i == src) heap.push(i, 0);
    else heap.push(i, INT_MAX);
  }

  while (!heap.empty()) {
    // First integer is the vertex, second is the weight. Extract the node with
    // the smallest weight.
    pair<int, int> node = heap.extractMin();
    int v = node.first;

    // Add edge that goes to the current vertex with smallest weight. 
    if (v != src) ans.push_back(edges[v]);

    // Iterate through all the edges of a given vertex v.
    for (int i = 0; i < g[v].size(); i++) {
      int u = g[v][i].to, w = g[v][i].weight;
      // If the vertex is in the heap AND the weight to get to it is greater
      // than the weight of the current edge.
      if (heap.contains(u) && heap.getWeight(u) > w) {
        heap.decreaseKey(u, w);
        edges[u] = {v, g[v][i].to};
      }
    }
  }

  return ans;
}

int main() {
  vector<vector<Edge>> graph(6, vector<Edge>());

  graph[0].push_back(*(new Edge(1, 3)));
  graph[0].push_back(*(new Edge(3, 1)));

  graph[1].push_back(*(new Edge(0, 3)));
  graph[1].push_back(*(new Edge(2, 1)));
  graph[1].push_back(*(new Edge(3, 3)));

  graph[2].push_back(*(new Edge(1, 1)));
  graph[2].push_back(*(new Edge(3, 1)));
  graph[2].push_back(*(new Edge(4, 5)));
  graph[2].push_back(*(new Edge(5, 4)));

  graph[3].push_back(*(new Edge(0, 1)));
  graph[3].push_back(*(new Edge(1, 3)));
  graph[3].push_back(*(new Edge(2, 1)));
  graph[3].push_back(*(new Edge(4, 6)));

  graph[4].push_back(*(new Edge(2, 5)));
  graph[4].push_back(*(new Edge(3, 6)));
  graph[4].push_back(*(new Edge(5, 2)));
  
  graph[5].push_back(*(new Edge(2, 4)));
  graph[5].push_back(*(new Edge(4, 2)));

  vector<pair<int, int>> r = prim(graph, 0);

  for (int i = 0; i < r.size(); i++) {
    cout << "from: " << r[i].first << " to: " << r[i].second << endl;
  }
  cout << endl;

  return 0;
}