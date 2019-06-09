/**
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 *
 * Example:
 * Input, 
 *     [  1 3 2
 *        4 3 1
 *        5 6 1
 *     ]
 * 
 * Output 8, representing 1 -> 3 -> 2 -> 1 -> 1
 *
 * Time complexity: O(M * N), where M is the number of rows and N the number of
 * columns.
 * Space complexity: O(M * N).
 *
 * Explanation: we gonna need a matrix of the same size of our input matrix.
 * We initialize this matrix with infinite. Now, at each element of this matrix
 * we check min(dp[i + 1][j], dp[i][j + 1]) + a[i][j], since we can just go
 * right or down at each iteration.
 */

#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int> > &a) {
  if (a.size() == 0 || a[0].size() == 0) return 0;

  vector<vector<int>> dp;
  int m = a.size();
  int n = a[0].size();

  for (int i = 0; i < m; i++) {
    vector<int> t;
    for (int j = 0; j < n; j++) t.push_back(INT_MAX);
    dp.push_back(t);
  }
  dp[m - 1][n - 1] = a[m - 1][n - 1];

  for (int i = m - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (i + 1 < m) dp[i][j] = min(dp[i][j], a[i][j] + dp[i + 1][j]);
      if (j + 1 < n) dp[i][j] = min(dp[i][j], a[i][j] + dp[i][j + 1]);
    }
  }

  return dp[0][0];
}

int main() {

  // vector<int> r1 = {1};
  // vector<vector<int>> matrix;
  // matrix.push_back(r1);

  // vector<int> r1 = {1};
  // vector<int> r2 = {2};
  // vector<vector<int>> matrix;
  // matrix.push_back(r1);
  // matrix.push_back(r2);

  // vector<int> r1 = {1, 3, 2};
  // vector<int> r2 = {4, 3, 1};
  // vector<int> r3 = {5, 6, 1};
  // vector<vector<int>> matrix;
  // matrix.push_back(r1);
  // matrix.push_back(r2);
  // matrix.push_back(r3);
  
  vector<int> r1 = {1, 3};
  vector<int> r2 = {4, 3};
  vector<int> r3 = {5, 6};
  vector<vector<int>> matrix;
  matrix.push_back(r1);
  matrix.push_back(r2);
  matrix.push_back(r3);
  
  int m = minPathSum(matrix);
  cout << "min: " << m << endl;

  return 0;
}