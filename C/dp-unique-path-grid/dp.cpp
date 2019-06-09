/**
 * Given a grid of size m * n, lets assume you are starting at (1,1) and your
 * goal is to reach (m,n). At any instance, if you are on (x,y), you can either
 * go to (x, y + 1) or (x + 1, y).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be? An obstacle and empty space is marked as 1 and 0 respectively
 * in the grid.
 * 
 * Example:
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * The total number of unique paths is 2.
 * 
 * Note: m and n will be at most 100.
 *
 * Time complexity: O(M * N), where M is the number of rows and N is the number
 * of columns.
 * Space complexity: O(M * N).
 *
 * Explanation: this is a famous dp problem. We initialize our dp[M][N] variable
 * with zeros and we start to iterate the grid from the bottom right element.
 * When we are at an element that is not an obstacle we add
 * dp[i + 1][j] + dp[i][j + 1]. We return dp[0][0].
 */

#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &a) {
  if (a.size() == 0 || a[0].size() == 0) return 0;

  int m = a.size(), n = a[0].size();
  vector<vector<int>> dp;

  for (int i = 0; i < m; i++) {
    vector<int> t(n, 0);
    dp.push_back(t);
  }

  dp[m - 1][n - 1] = !a[m - 1][n - 1];

  for (int i = m - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (a[i][j] == 0) {
        int r = 0, b = 0;
        if (i + 1 < m) b = dp[i + 1][j];
        if (j + 1 < n) r = dp[i][j + 1];
        if (r != 0 || b!= 0) dp[i][j] = r + b;
      }
    }
  }

  return dp[0][0];
}

int main() {
  vector<int> r1 = {0, 0, 0};
  vector<int> r2 = {0, 1, 0};
  vector<int> r3 = {0, 0, 0};
  vector<vector<int>> matrix;
  matrix.push_back(r1);
  matrix.push_back(r2);
  matrix.push_back(r3);
  
  int n = uniquePathsWithObstacles(matrix);
  cout << "num: " << n << endl;

  return 0;
}