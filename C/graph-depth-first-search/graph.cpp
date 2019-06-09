/**
 * Depth First Search for a graph represented as Adjacency List.
 *
 * Time complexity: O(|V|), where |V| is the number of ans.
 * Space complexity: O(log|V|)
 *
 * Explanation: use a stack. The easiest ways is to use recursion.
 */

#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int to;
  Edge(int x): to(x) {}
};

void dfsUtil(
  vector<vector<Edge>> &g, int v, vector<bool> &visited, vector<int> &ans
) {
  visited[v] = true;
  ans.push_back(v);

  for (int i = 0; i < g[v].size(); i++) {
    int u = g[v][i].to;
    if (!visited[u]) dfsUtil(g, u, visited, ans);
  }
}

vector<int> depthFirstSearch(vector<vector<Edge>> &g, int v) {
  int numVertices = g.size();
  vector<int> ans;
  vector<bool> visited(numVertices, false);

  dfsUtil(g, v, visited, ans);

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

  vector<int> r = depthFirstSearch(graph, 0);

  for (int i = 0; i < r.size(); i++) {
    cout << r[i] << " ";
  }
  cout << endl;

  return 0;
}