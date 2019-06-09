/**
 * Topological Sort for a graph represented as Adjacency List.
 *
 * Time complexity: O(N), where N is the number of nodes.
 * Space complexity: O(N).
 *
 * Explanation: for each every u->v u must be placed before v. Topological
 * sort is commonly used in build systems where v has a dependecy of u so u
 * must be built before v. Topological Sort uses Depth First Search to get to
 * a node with no edges so we can insert it into a stack (this stack is our
 * answer).
 */

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

struct Edge {
  int to;
  Edge(int x): to(x) {}
};

void topologicalSortUtil(
  int v, vector<vector<Edge>> &g, unordered_set<int> &visited, stack<int> &stk
) {
  visited.insert(v);

  for (int i = 0; i < g[v].size(); i++) {
    int u = g[v][i].to;
    if (visited.find(u) != visited.end()) continue;
    topologicalSortUtil(u, g, visited, stk);
  }

  stk.push(v);
}

vector<int> topologicalSort(vector<vector<Edge>> &g) {
  int numVertices = g.size();
  stack<int> stk;
  unordered_set<int> visited;
  vector<int> ans(numVertices, -1);

  for (int i = 0; i < numVertices; i++) {
    if (visited.find(i) != visited.end()) continue;
    topologicalSortUtil(i, g, visited, stk);
  }

  for (int i = 0; i < numVertices; i++) {
    ans[i] = stk.top();
    stk.pop();
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

  vector<int> r = topologicalSort(graph);

  for (int i = 0; i < r.size(); i++) {
    cout << r[i] << " ";
  }
  cout << endl;

  return 0;
}