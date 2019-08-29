/**
 * Given N * M field of O's and X's, where O = white, X = black. Return the
 * number of black shapes. A black shape consists of one or more adjacent X's
 * (diagonals not included).
 * 
 * Notes:
 * 1. We are looking for connected shapes.
 * 
 * Example:
 * 
 * OOOXOOO
 * OOXXOXO
 * OXOOOXO
 * 
 * Answer is 3 shapes are:
 * (i)    X
 *      X X
 * (ii)
 *       X
 *  (iii)
 *       X
 *       X
 *
 *
 * Time complexity: O(N * M).
 *
 * Explanation: At each time we find a X we increment our count and then we
 * apply BFS or DFS to eliminate the connected component.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<string> &a, int i, int j) {
  int n = a.size(), m = a[0].size();
  queue<pair<int, int>> q;
  q.push({i, j});
  a[i][j] = 'O';

  while (!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();

    int r = curr.first, c = curr.second;

    if (r + 1 < n && a[r + 1][c] == 'X') {
      q.push({r + 1, c});
      a[r + 1][c] = 'O';
    }
    if (c + 1 < m && a[r][c + 1] == 'X') {
      q.push({r, c + 1});
      a[r][c + 1] = 'O';
    }
    if (r - 1 >= 0 && a[r - 1][c] == 'X') {
      q.push({r - 1, c});
      a[r - 1][c] = 'O';
    }
    if (c - 1 >= 0 && a[r][c - 1] == 'X') {
      q.push({r, c - 1});
      a[r][c - 1] = 'O';
    }
  }
}

int black(vector<string> &a) {
  if (a.size() == 0 || a[0].size() == 0) return 0;

  int n = a.size(), m = a[0].size(), ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'O') continue;
      bfs(a, i, j);
      ans++;
    }
  }

  return ans;
}

int main() {
  vector<string> graph = {
    "OOOXOOO",
    "OOXXOXO",
    "OXOOOXO"
  };

  int r = black(graph);

  cout << "shapes: " << r << endl;

  return 0;
}