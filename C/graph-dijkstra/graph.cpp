/**
 * Dijkstra Single Source Shortest Path algorithm.
 *
 * Time complexity: O(|E| * log|V|), where |E| is the number of edges and |V|
 * is the number of vertices. This complexity assume you are using a priority
 * queue.
 * Space complexity: O(|V|).
 *
 * Explanation: Dijkstra algorithm calculate the distance from a given vertex
 * to all the other vertices in the graph. It begins assuming that the distance
 * from this source vertex to every other node is Infinity (except for the
 * source node itself where the distance is 0). After, using a priority queue
 * (this queue is initialized with {source, 0}) the algorithm looks for the
 * shortest distance until that moment, get the vertex where we have have this
 * shortest distance, mark it as visited and check all of its edges updating
 * distances and pushing these distances to the priority queue. Since Dijkstra
 * algorithm always get from the priority queue the shortest distance to a
 * vertex it can mark this vertex as visited and never check it again.
 * For example,
 * If we 5 vertices and a distance vector like this:
 * indices: 0 1 2 3 4
 * dist:    5 4 3 2 1
 * It will get the vertex 4 and mark it as visited because if we try to reach
 * vertex 4 with any other path we will have a larger distance since the values
 * 2, 3, 4, and 5 are all larger than 1 already (assuming that we have only
 * positive weights). When the priority queue is empty the algorithm is done.
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Edge {
  int to, weight;
  Edge(int x, int y) : to(x), weight(y) {}
};

// SSSP Dijkstra algorithm for a graph represented with Adjacency List.
// Time complexity: O(|E| * log|V|).
// Space complexity: O(|V|).
vector<int> dijkstra(vector<vector<Edge>> &g, int src) {
  int numVertices = g.size();
  // dist[i] keeps the shortest distance from src to a vertice i.
  vector<int> dist(numVertices, INT_MAX);
  // parents[i] keeps the node we must come from to get to i with the shortest
  // distance.
  vector<int> parents(numVertices, -1);
  // The priority queue. It is better to use a set than the priority_queue
  // from STL because we can delete nodes from set. In the priority_queue
  // we would need to repeat a vertex every time we find a shortest distance.
  // A pair is made as {vertex, distance}.
  set<pair<int, int>> pq;

  // The source has a distance of 0 to itself.
  dist[src] = 0;
  pq.insert({src, 0});

  while (!pq.empty()) {
    // Get the vertex with the shortest distance until now.
    int from = pq.begin()->first;
    // Erase it from the queue marking it as visited. erase(iterator) has
    // time complexity O(1).
    pq.erase(pq.begin());

    // If our queue gave us a node with Infinity weight it means we don't have
    // anymore nodes that we can get to from source.
    if (dist[from] == INT_MAX) break;

    // For each vertex that we can get from vertex "from".
    for (Edge ed : g[from]) {
      // If to get from node u to v has a shortest distance than we had before
      // update our variables.
      if (dist[ed.to] > dist[from] + ed.weight) {
        // Erase the previous pair {vertex, distance} from our queue so we
        // don't have useless entries in our queue. erase(value) has time
        // complexity O(logN).
        pq.erase({ed.to, dist[ed.to]});
        dist[ed.to] = dist[from] + ed.weight;
        pq.insert({ed.to, dist[ed.to]});

        // Update from where we came from to get to this current node with
        // a shortest distance.
        parents[ed.to] = from;
      }
    }
  }

  return parents;
}

int findMinIndex(vector<int> &dist, vector<bool> visited) {
  int minIndex = -1;

  for (int i = 0; i < dist.size(); i++) {
    if (minIndex == -1 && !visited[i]) minIndex = i;
    if (!visited[i] && dist[i] < dist[minIndex]) minIndex = i;
  }

  return minIndex;
}

// SSSP Dijkstra algorithm for a graph represented with Adjacency Matrix and
// not using a priority queue.
// Time complexity: O(|V|^2).
// Space complexity: O(|V|).
vector<int> dijkstraSlow(vector<vector<int>> &g, int src) {
  int numVertices = g.size();
  vector<int> dist(numVertices, INT_MAX);
  vector<int> parents(numVertices, -1);
  vector<bool> visited(numVertices, false);

  dist[src] = 0;

  for (int i = 0; i < numVertices - 1; i++) {
    int u = findMinIndex(dist, visited);
    visited[u] = true;

    for (int v = 0; v < numVertices; v++) {
      if (g[u][v] == 0 || dist[u] == INT_MAX) continue;

      if (!visited[v] && dist[u] + g[u][v] < dist[v]) {
        dist[v] = dist[u] + g[u][v];
        parents[v] = u;
      }
    }
  }

  return parents;
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

  // Create Adjacency List from Adjacency Matrix.
  vector<vector<Edge>> adjList;
  for (int i = 0; i < graph.size(); i++) {
    vector<Edge> temp;
    for (int j = 0; j < graph[i].size(); j++) {
      if (graph[i][j] == 0) continue;
      Edge *ed = new Edge(j, graph[i][j]);
      temp.push_back(*ed);
    }
    adjList.push_back(temp);
  }

  // Print Adjacency List.
  for (int i = 0; i < adjList.size(); i++) {
    for (int j = 0; j < adjList[i].size(); j++) {
      cout << "(" << adjList[i][j].to << "," << adjList[i][j].weight << ")" << " ";
    }
    cout << endl;
  }
  cout << endl << endl;

  // Print answer.
  vector<int> r = dijkstra(adjList, 0);
  for (int i = 0; i < r.size(); i++) {
    cout << r[i] << " ";
  }
  cout << endl;
    
  // // Print answer for slower Dijkstra algorithm using Adjacency Matrix.
  // vector<int> r2 = dijkstraSlow(graph, 0);
  // for (int i = 0; i < r2.size(); i++) {
  //   cout << r2[i] << " ";
  // }
  // cout << endl;

  return 0;
}