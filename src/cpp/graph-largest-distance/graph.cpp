/**
 * Find largest distance. Given an arbitrary unweighted rooted tree which
 * consists of N (2 <= N <= 40000) nodes. The goal of the problem is to find
 * largest distance between two nodes in a tree. Distance between two nodes is
 * a number of edges on a path between the nodes (there will be a unique path
 * between any pair of nodes since it is a tree). The nodes will be numbered 0
 * through N - 1.
 * 
 * The tree is given as an array P, there is an edge between nodes P[i] and
 * i (0 <= i < N). Exactly one of the i’s will have P[i] equal to -1, it will
 * be root node.
 * 
 * Example:
 * 
 * If given P is [-1, 0, 0, 0, 3], then node 0 is the root and the whole tree
 * looks like this: 
 *           0
 *        /  |  \
 *       1   2   3
 *                \
 *                 4  
 * One of the longest path is 1 -> 0 -> 3 -> 4 and its length is 3.
 *
 * Time complexity: O(N), where N is the maximum number of nodes in the tree.
 * In other words, N is the array length.
 * Space complexity: O(N).
 *
 * Explanation: to get linear time complexity we need to rebuild the graph
 * using a Adjacency List. Now, we perform Depth First Search to get the
 * distance of a pair of nodes. The maximum distance will always be made of
 * two parts p1 and p2. These parts are the maximum distance and the second
 * maximum distance from a node to another node.
 * In my code, I get the distance (or in other words, the height of that node)
 * from bottom-up returning maxCurrDistance + 1 of each node. And I keep two
 * variables at each function call (notice that each function call is
 * responsible for a single node) to store p1 and p2. Also, at each function
 * call after the "for" loop that investigates the edges of each vertex, I check
 * for the maximum p1 and p2 if the current answer is smaller than p1 + p2 and
 * then update answer.
 */

#include <iostream>
#include <vector>

using namespace std;

int dfsUtil(vector<vector<int>> &a, int v, vector<bool> &visited, int &ans) {
  visited[v] = true;
  int count = 0, p1 = 0, p2 = 0;

  for (int i = 0; i < a[v].size(); i++) {
    int u = a[v][i];
    if (!visited[u]) {
      int currDist = dfsUtil(a, u, visited, ans);

      if (currDist > p1 || currDist > p2) {
        p1 = max(p1, p2);
        p2 = currDist;
      }
    }
  }

  ans = max(ans, p1 + p2);

  return max(p1, p2) + 1;
}

int solve(vector<int> &a) {
  int src, ans = 0;
  vector<bool> visited(a.size(), false);
  vector<vector<int>> graph(a.size(), vector<int>());

  for (int i = 0; i < a.size(); i++) {
    if (a[i] != -1) graph[a[i]].push_back(i);
    else src = i;
  }

  dfsUtil(graph, src, visited, ans);

  return ans;
}

// The solution below doesn't rebuild the graph. Instead it uses the edge
// list the exercise gives, so the space complexity would be logN, but the
// time complexity would be N^2.
// int dfsUtil(vector<int> &a, int v, vector<bool> &visited, int &ans) {
//   visited[v] = true;
//   int count = 0, p1 = 0, p2 = 0;

//   for (int i = 0; i < a.size(); i++) {
//     if (a[i] == v && !visited[i]) {
//       int currDist = dfsUtil(a, i, visited, ans);
      
//       if (currDist > p1 || currDist > p2) {
//         p1 = max(p1, p2);
//         p2 = currDist;
//       }
//     }
//   }

//   ans = max(ans, p1 + p2);

//   return max(p1, p2) + 1;
// }

// int solve(vector<int> &a) {
//   int src, ans = 0;
//   vector<bool> visited(a.size(), false);

//   for (int i = 0; i < a.size(); i++) {
//     if (a[i] == -1) {
//       src = i;
//       break;
//     }
//   }

//   dfsUtil(a, src, visited, ans);

//   return ans;
// }

int main() {
  // vector<int> a = {-1, 0};
  // vector<int> a = {-1, 0, 1, 2, 3};
  // vector<int> a = {-1, 0, 0, 0, 3};
  vector<int> a = {-1, 0, 1, 1, 2, 0, 5, 0, 3, 0, 0, 2, 3, 1, 12};

  int r = solve(a);

  cout << r << endl;

  return 0;
}