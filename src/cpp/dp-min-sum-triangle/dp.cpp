/**
 * Given a triangle, find the minimum path sum from top to bottom. Each step you
 * may move to adjacent numbers on the row below (with adjacent they mean
 * one number to the right of the current number).
 * Bonus point if you are able to do this using only O(N) extra space, where
 * N is the number of rows in the given triangle.
 *
 * Time complexity: O(N * M), where N is the number of rows and M is the average
 * length of rows.
 * Space complexity: O(N).
 * 
 * Example:
 * Given,
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Explanation: we are asked to use O(N) space, where N is the number of rows.
 * This N is also the number of elements in the last row since this is a
 * triangle. So we initialize our dp variable with the last row and then iterate
 * from the row before the last to the first row. At each row i, at each column
 * j store in dp[j] = a[i][j] + min(dp[j], dp[j + 1]). Return dp[0] (since it
 * is a triangle the first minimum path from the first row, that has just one
 * element, is at dp[0]).
 */

#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int> > &a) {
  if (a.size() == 0 || a[a.size() - 1].size() == 0) return 0;

  int nr = a.size();
  vector<int> dp(a[nr - 1]);

  for (int i = nr - 2; i >= 0; i--) {
    for (int j = 0; j < a[i].size(); j++) {
      dp[j] = a[i][j] + min(dp[j], dp[j + 1]);
    }
  }

  return dp[0];
}

int main() {
  // vector<int> r1 = {2};
  // vector<vector<int>> triangle;
  // triangle.push_back(r1);

  // vector<int> r1 = {2};
  // vector<int> r2 = {3, 4};
  // vector<vector<int>> triangle;
  // triangle.push_back(r1);
  // triangle.push_back(r2);

  // vector<int> r1 = {2};
  // vector<int> r2 = {3, 4};
  // vector<int> r3 = {6, 5, 7};
  // vector<int> r4 = {4, 1, 8, 3};
  // vector<vector<int>> triangle;
  // triangle.push_back(r1);
  // triangle.push_back(r2);
  // triangle.push_back(r3);
  // triangle.push_back(r4);
  
  vector<int> r1 = {3};
  vector<int> r2 = {7, 0};
  vector<int> r3 = {1, 3, 4};
  vector<int> r4 = {3, 7, 7, 5};
  vector<int> r5 = {1, 2, 6, 6, 5};
  vector<vector<int>> triangle;
  triangle.push_back(r1);
  triangle.push_back(r2);
  triangle.push_back(r3);
  triangle.push_back(r4);
  triangle.push_back(r5);
  
  int m = minimumTotal(triangle);
  cout << "min: " << m << endl;

  return 0;
}