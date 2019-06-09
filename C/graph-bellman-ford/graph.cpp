/**
 * Single Source Shortest Path Bellman-Ford algorithm.
 *
 * Time complexity: O(|V| * |E|), where |V| is the number of vertices and |E| is
 * the number of edges.
 * Space complexity: O(|V|).
 *
 * Explanation: similar to Dijkstra Algorithm we start our distance array with 0
 * distance from the source to itself and everything else is Infinity. Then,
 * we visit all edges |V| - 1 times and update the distance array with
 * dist[v] = min(dist[v], dist[u] + weight(u, v)).
 * Bellman-Ford has two advantages over Dijkstra (though it is slower):
 * 1. It can calculate shortest paths in graphs with negative weights.
 * 2. It can detect negative cycles.
 * The algorithm is executed |V| - 1 times, that is the maximum number of edges
 * between a vertex and another one (assuming there is no self loops).
 * Lets see why we need to execute |V| - 1 times. Suppose you have the graph:
 *
 *     2      4       1
 * 0 ----> 1 ----> 2 ----> 3
 *
 * And the order we gonna visit the edges is: 2->3, 1->2, 0->1. At the beginning
 * our distance array is dist = [0, INF, INF, INF]. So, when we check the edge
 * 2->3 we will not update anything because we didn't discover yet a path to
 * 2. So, in the first iteration we just update the edge 0->1 and we get
 * dist = [0, 2, INF, INF]. Continuing the process you can see that you will
 * need more 2 iterations, that is the total is |V| - 1 = 3, to get the shortest
 * paths.
 */

#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int from, to, weight;
  Edge(int x, int y, int z): from(x), to(y), weight(z) {}
};

vector<int> bellmanFord(vector<Edge> &g, int src, int numVertices) {
  vector<int> parents(numVertices, -1);
  vector<int> dist(numVertices, INT_MAX);

  dist[src] = 0;

  for (int i = 0; i < numVertices - 1; i++) {
    for (int j = 0; j < g.size(); j++) {
      int u = g[j].from, v = g[j].to, w = g[j].weight;
      if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        parents[v] = u;
      }
    }
  }

  for (int j = 0; j < g.size(); j++) {
    int u = g[j].from, v = g[j].to, w = g[j].weight;
    if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
      cout << "Negative cycle found." << endl;
      return vector<int>(numVertices, -1);
    }
  }

  return parents;
}

int main() {
  vector<Edge> graph;
  graph.push_back(*(new Edge(0, 3, 8)));
  graph.push_back(*(new Edge(3, 4, 2)));
  graph.push_back(*(new Edge(2, 4, 4)));
  graph.push_back(*(new Edge(1, 2, -3)));
  graph.push_back(*(new Edge(0, 1, 4)));
  graph.push_back(*(new Edge(4, 3, 1)));
  graph.push_back(*(new Edge(0, 2, 5)));

  vector<int> r = bellmanFord(graph, 0, 5);

  for (int i = 0; i < r.size(); i++) {
    cout << r[i] << " ";
  }
  cout << endl;

  return 0;
}