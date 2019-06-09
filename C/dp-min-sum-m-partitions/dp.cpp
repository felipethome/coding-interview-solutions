/**
 * Given an array with N integers and an integer M, find the minimum sum of the
 * maximum elements of M contiguous partitions of the array.
 *
 * Example:
 *
 * Given [1, 2, 3, 4] and M = 2 (the array is not necessarily sorted)
 * Output 5, because possible partitions are
 * [1] [2, 3, 4] => 1 + 4 = 5
 * [1, 2] [3, 4] => 2 + 4 = 6
 * [1, 2, 3] [4] => 3 + 4 = 7
 *
 * Time complexity: O(N^2 * M), were N is the size of the given array and M
 * is the number of partitions.
 * Space complexity: O(N * M).
 *
 * Explanation: to solve this problem we can use dynamic programming. The brute
 * force solution would be to try all possible combinations which would be
 * O(N^M). Lets see some important notes to get our DP solution supposing we
 * start our algorithm from the end of the array to the beginning:
 *
 * 1. We want to find DP(i, j), where DP(i, j) is the the minimum sum of the
 * array with "i" partitions and starting at element A[j].
 *
 * 2. If we decide that we want to partition the array at point "j" and we
 * current have to perform "i" partitions, then the minimum sum will be A[j]
 * (that is the maximum element because this partition has just one element)
 * plus DP(i - 1, j + 1). Notice that when i = 0 we have just one partition
 * because we are using zero based indexes and we need to consider the entire
 * array, so the minimum sum will be the maximum element found so far. In other
 * words, DP(0, j) will be the maximum element we found from A[A.size() - 1] to
 * A[j].
 *
 * 3. The item 2 is half of our logic, the other half is that we need to figure
 * out point j. For that we iterate from j to A.size() - i (we need to subtract
 * "i" because one partition can use all elements in the array, but two
 * partitions can use at most A.size() - 1, three, A.size() - 2, and so on).
 * In each iteration we keep the maximum element we have so far for this
 * partition that starts at j and we get:
 * min(DP(i, j), currMax + DP(i - 1, j + 1)).
 *
 * For example,
 *
 * Given A = [1, 3, 5, 2, 4, 8, 6, 1, 0, 2, 9, 1] and M = 3, our result DP
 * table would be:
 *
 * i/j |  0   1   2   3   4   5   6   7   8   9   10  11
 * ------------------------------------------------------
 *  0  |  9   9   9   9   9   9   9   9   9   9   9   1
 *  1  |  10  10  10  10  10  10  10  10  9   10  10  INF
 *  2  |  11  13  15  12  14  17  15  10  10  12  INF INF
 *
 * And our answer would be DP[M - 1][0] = DP[2][0] = 11.
 *
 * This table give us information like this: if our array starts at index 8 and
 * we need to perform 2 partitions what is the minimum sum? It is DP[1][8] = 9.
 * If we need to find DP[2][6], so we want to find the minimum sum if our
 * array starts at index 6 and we need to have 3 partitions, then we check
 * every element from indexes 6 to 9 keeping the maximum and for each of them
 * we check DP[i - 1][j + 1] which are:
 *
 * DP[1][7] = 10, DP[1][8] = 9, DP[1][9] = 10, DP[1][10] = 10,
 *
 * So we get the minimum as currMax + DP[1][8] = 15 (where currMax = A[6] = 6).
 * In other words, our minimum sum starting at 6 happens when we make the third
 * partition at element 7:
 *
 * [6, 1], [0], [2, 9, 1]
 */

#include <iostream>
#include <vector>

using namespace std;

int minSum(vector<int> &a, int b) {
  int n = a.size();
  vector<vector<int>> dp(b, vector<int>(n, INT_MAX));

  dp[0][n - 1] = a.back();
  for (int i = n - 2; i >= 0; i--) dp[0][i] = max(a[i], dp[0][i + 1]);

  for (int i = 1; i < b; i++) {
    for (int j = n - i - 1; j >= 0; j--) {
      int currMax = INT_MIN;
      for (int k = j; k < n - i; k++) {
        currMax = max(currMax, a[k]);
        dp[i][j] = min(dp[i][j], currMax + dp[i - 1][k + 1]);
      }
    }
  }

  return dp[b - 1][0];
}

int main() {
  // vector<int> a = {1, 2, 3, 4};
  // int b = 2;

  vector<int> a = {1, 3, 5, 2, 4, 8, 6, 1, 0, 2, 9, 1};
  int b = 3;

  int r = minSum(a, b);

  cout << r << endl;

  return 0;
}