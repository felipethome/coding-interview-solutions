/**
 * Floyd Warshall All-Pairs Shortest Path.
 *
 * Time complexity: O(|V|^3), where |V| is the number of vertices.
 *
 * Explanation: the main idea is to check if going from vertex i to j is shorter
 * if we use an intermediary vertex k, intead of the direct path i to j. So, we
 * want dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]). Notice that this
 * algorithm as it is work for Adjacency Matrices and that an edge that does not
 * exist must to be represented as Infinity (and take care because the above
 * equation can overflow if you use INT_MAX).
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> floydWarshall(vector<vector<int>> &g) {
  int numVertices = g.size();
  vector<vector<int>> dist(numVertices, vector<int>(numVertices, 0));

  // Initialize dist matrix. This is unnecessary if the input graph is a matrix
  // where a edge that does not exist is represented with Infinity weight and
  // the distance from a vertex to itself is 0.
  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      if (i == j) continue;
      dist[i][j] = g[i][j] == 0 ? INT_MAX : g[i][j];
    }
  }

  for (int k = 0; k < numVertices; k++) {
    for (int i = 0; i < numVertices; i++) {
      for (int j = 0; j < numVertices; j++) {
        // Avoid overflow.
        if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  return dist;
}

int main() {
  // Adjacency Matrix.
  vector<vector<int>> graph = {
    {0, 4, 0, 0, 0, 0, 0, 8, 0},
    {4, 0, 8, 0, 0, 0, 0, 11, 0},
    {0, 8, 0, 7, 0, 4, 0, 0, 2},
    {0, 0, 7, 0, 9, 14, 0, 0, 0},
    {0, 0, 0, 9, 0, 10, 0, 0, 0},
    {0, 0, 4, 14, 10, 0, 2, 0, 0},
    {0, 0, 0, 0, 0, 2, 0, 1, 6},
    {8, 11, 0, 0, 0, 0, 1, 0, 7},
    {0, 0, 2, 0, 0, 0, 6, 7, 0}
  };

  // Print answer.
  vector<vector<int>> r = floydWarshall(graph);
  for (int i = 0; i < r.size(); i++) {
    for (int j = 0; j < r[i].size(); j++) {
      cout << r[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}