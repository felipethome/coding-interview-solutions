/**
 * Breadth First Search for a graph represented as Adjacency List.
 *
 * Time complexity: O(|V| + |E|), where |V| is the number of vertices and |E| is
 * the number of edges.
 * Space complexity: O(|V|).
 *
 * Explanation: use a queue. Breadth First Search can use much more memory
 * than Depth First Search (in trees), but BFS can give the optimal solution
 * when you are looking if a vertex has a path to another and you want the
 * shortest path (and the graph is unweighted), while DFS, though it also can
 * find a path it is not guaranteed it will be the shortest.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
  int to;
  Edge(int x): to(x) {}
};

vector<int> breadthFirstSearch(vector<vector<Edge>> &g, int v) {
  int numVertices = g.size();
  vector<int> ans;
  vector<bool> visited(numVertices, false);
  queue<int> q;

  q.push(v);
  visited[v] = true;

  while (!q.empty()) {
    int first = q.front();
    q.pop();
    ans.push_back(first);
    for (int i = 0; i < g[first].size(); i++) {
      int u = g[first][i].to;
      if (!visited[u]) {
        // It is better to mark as visited here to avoid unnecessary work,
        // though I believe the answer would be the same if we mark the node
        // as visited in the beginning of the while loop. Marking it here we
        // don't add the same vertex multiple times to the queue saving memory
        // and increasing performance.
        visited[u] = true;
        q.push(u);
      }
    }
  }

  return ans;
}

int main() {
  vector<vector<Edge>> graph(7, vector<Edge>());

  graph[0].push_back(*(new Edge(2)));
  graph[1].push_back(*(new Edge(2)));
  graph[1].push_back(*(new Edge(4)));
  graph[2].push_back(*(new Edge(3)));
  graph[3].push_back(*(new Edge(5)));
  graph[4].push_back(*(new Edge(5)));
  graph[5].push_back(*(new Edge(6)));

  vector<int> r = breadthFirstSearch(graph, 0);

  for (int i = 0; i < r.size(); i++) {
    cout << r[i] << " ";
  }
  cout << endl;

  return 0;
}