/**
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by
 * 'X'. A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 *
 * Note:
 * 1. The board can have different x and y dimensions.
 * 
 * Example:
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 *
 * After running your function, the board should be:
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 *
 * Time complexity: O(N^2), where N is the number of places in the board.
 * Space complexity: O(N).
 *
 * Explanation: use BFS or DFS to find connected components of O's. When
 * performing the BFS keep all the vertices you visited because you may need
 * to switch them back to its original value when the connected component you
 * traversed is not completely surrounded by X's. A connected component will
 * not be completely surrounded when one of its O's is in one of the borders of
 * the board (i = 0, j = 0, i = N - 1, j = N - 1). Also notice that if you
 * switch a not valid connected component back to O's in the BFS function you
 * will end up investigating the same component more than once. For example,
 * O O X 
 * X X X
 * X X X
 * If you don't mark in some way that the vertex (0, 1) was already visited you
 * will cal BFS for it again. For that you can use a intermediary symbol or a
 * "visited" variable. I used an intermediary symbol 'F' to save some extra
 * memory, so in the end of my algorithm I need to switch back the F's to O's.
 */

#include <iostream>
#include <queue>

using namespace std;

void bfs(vector<vector<char>> &a, int i, int j) {
  int n = a.size(), m = a[0].size();
  bool valid = true;
  vector<pair<int, int>> visited;
  
  queue<pair<int, int>> q;
  q.push({i, j});
  a[i][j] = 'X';


  while (!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();
    int r = curr.first, c = curr.second;

    if (r == 0 || r == n - 1 || c == 0 || c == m - 1) valid = false;

    if (r - 1 >= 0 && a[r - 1][c] == 'O') {
      q.push({r - 1, c});
      a[r - 1][c] = 'X';
    }
    if (c - 1 >= 0 && a[r][c - 1] == 'O') {
      q.push({r, c - 1});
      a[r][c - 1] = 'X';
    }
    if (r + 1 < n && a[r + 1][c] == 'O') {
      q.push({r + 1, c});
      a[r + 1][c] = 'X';
    }
    if (c + 1 < m && a[r][c + 1] == 'O') {
      q.push({r, c + 1});
      a[r][c + 1] = 'X';
    }

    visited.push_back({r, c});
  }

  if (!valid) {
    for (pair<int, int> p : visited) a[p.first][p.second] = 'F';
  }
}

void solve(vector<vector<char>> &a) {
  if (a.size() == 0 || a[0].size() == 0) return;

  int n = a.size(), m = a[0].size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'X' || a[i][j] == 'F') continue;
      bfs(a, i, j);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'F') a[i][j] = 'O';
    }
  }
}

int main() {
  // vector<vector<char>> board = {
  //   "XXXX",
  //   "XOXX",
  //   "XXOX",
  //   "XXXX"
  // };
  
  // vector<vector<char>> board = {
  //   "OXXX",
  //   "XOXX",
  //   "XXOX",
  //   "XXXX"
  // };

  // vector<vector<char>> board = {
  //   { 'X', 'X', 'X', 'X' },
  //   { 'X', 'O', 'O', 'X' },
  //   { 'X', 'X', 'O', 'X' },
  //   { 'X', 'O', 'X', 'X' }
  // };

  // vector<vector<char>> board = {
  //   { 'X', 'O', 'O', 'O', 'X', 'O', 'X', 'X', 'X', 'X' },
  //   { 'X', 'O', 'X', 'O', 'X', 'O', 'O', 'X', 'X', 'X' },
  //   { 'X', 'X', 'X', 'O', 'O', 'O', 'X', 'O', 'X', 'O' },
  //   { 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'O', 'X' }
  // };
  
  vector<vector<char>> board = {
    { 'O', 'X', 'X' },
    { 'O', 'O', 'X' },
    { 'X', 'X', 'O' },
    { 'X', 'O', 'X' },
    { 'O', 'O', 'X' },
    { 'O', 'X', 'X' }
  };

  solve(board);

  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}