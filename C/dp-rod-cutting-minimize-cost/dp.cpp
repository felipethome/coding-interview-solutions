/**
 * There is a rod of length N lying on x-axis with its left end at x = 0 and
 * right end at x = N. Now, there are M weak points on this rod denoted by
 * positive integer values(all less than N) A1, A2, …, AM. You have to cut rod
 * at all these weak points. You can perform these cuts in any order. After a
 * cut, rod gets divided into two smaller sub-rods. Cost of making a cut is the
 * length of the sub-rod in which you are making a cut.
 * 
 * Your aim is to minimise this cost. Return an array denoting the sequence in
 * which you will make cuts. If two different sequences of cuts give same cost,
 * return the lexicographically smallest.
 * 
 * Notes: 
 * 1. Sequence a1, a2 ,…, an is lexicographically smaller than b1, b2 ,…, bm, if
 * and only if at the first i where ai and bi differ, ai < bi, or if no such i
 * found, then n < m.
 * 2. N can be upto 109.
 * 
 * Example:
 * N = 6
 * A = [1, 2, 5]
 * 
 * If we make cuts in order [1, 2, 5], let us see what total cost would be.
 * For first cut, the length of rod is 6.
 * For second cut, the length of sub-rod in which we are making cut is 5
 * (since we already have made a cut at 1).
 * For third cut, the length of sub-rod in which we are making cut is 4
 * (since we already have made a cut at 2).
 * So, total cost is 6 + 5 + 4.
 * 
 * Cut order          | Sum of cost
 * (lexicographically | of each cut
 *  sorted)           |
 * ___________________|_______________
 * [1, 2, 5]          | 6 + 5 + 4 = 15
 * [1, 5, 2]          | 6 + 5 + 4 = 15
 * [2, 1, 5]          | 6 + 2 + 4 = 12
 * [2, 5, 1]          | 6 + 4 + 2 = 12
 * [5, 1, 2]          | 6 + 5 + 4 = 15
 * [5, 2, 1]          | 6 + 5 + 2 = 13
 * 
 * So, we return [2, 1, 5].
 *
 * Time complexity: O(M^3), where M is the number of points we have to cut.
 * Space complexity: O(M^2).
 *
 * Explanation: This is a dynamic programming problem and since the exercise
 * asks for the lexicographically smallest solution it is better if we use
 * memoization.
 * The main idea is that at each point "i" where we cut, will be created to
 * rods with length 0 .. i and i .. N. For these two rods we can check their
 * minimum costs independent from each other, in other words, the cuts that
 * will be performed in rod 0 .. i don't depend from the cuts that will be
 * performed in rod i .. N.
 * Notice, that  you can never cut a rod with length <= 1. Also, we need to
 * insert points 0 and N in our cuts array (rods can, of course, start at 0 and
 * end at N).
 * So, we want our dp(i, j) to be the minimum cost for rod i .. j. When a rod
 * is defined to be i .. j we are not interested in the points i and j because
 * we are supposing that already exists a rod from i .. j (like in the
 * beginning case where we have the rod that goes from 0 .. N, but we do not
 * manipulate 0 and N because it doesn't make sense since we can't perform
 * cuts in these points). And, if we have a rod from i .. j its cost will be
 * the sum of minimum costs of inside rods, but if there is only on point we
 * can't define a rod so we always need to add the cost of j - i. For example,
 * we want to know the minimum cost for rod 2 .. 6, and we can perform according
 * to our "cuts array" a cut at point 3, but point 3 alone doesn't make a rod,
 * but we know that a cut at 3 will have cost 6 - 2 = 4.
 *
 * Now, with the above facts we can define our recursion to be:
 * dp[l][r] = min(dp[l][k] + dp[k][r] + (cuts[r] - cuts[l])), for every cut
 * point k inside this rod l .. r.
 *
 * Our dp variable contains the minimum costs for rods i .. j, but we need to
 * know here the cuts happened. For that, we store which index k in the above
 * recursion gave us the minimum cost for rod i .. j. Since we are using
 * memoization once we store the index k, we do not store any other k that is
 * able to give a cost equal to the minimum cost and then we can guarantee
 * the lexicographically smallest solution.
 *
 * Notice that if the exercise was asking just for the minimum cost it would be
 * possible to implement in O(M^2) time because we would need to calculate
 * the minimium cost just for the rod 0 .. N (because we don't need to know
 * where the cuts happend there is no need to calculate costs for intermediary
 * rods i .. j, where i is greater than 0 so we just calculate a matrix with
 * minimum costs for rods 0 .. i, with i being all the cut points, including N).
 * In this case dp[i][j] means the minimum cost for a rod starting at 0 and
 * ending at i, with possible cuts being the range 0 .. j from the "cuts array".
 *
 * Solution with the cut points based on:
 * http://qa.geeksforgeeks.org/4063/minimize-the-cutting-cost-latest-google-question
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;
vector<vector<int>> parent;
 
// Solve for dp(l, r).
int rec(int l, int r, vector<int> &b) {
  if (l + 1 >= r) return 0;

  if (dp[l][r] != -1) return dp[l][r];

  dp[l][r] = INT_MAX;
  int minCutIndex;

  for(int i = l + 1; i < r; i++) {
    // Recurrence.
    int possibleCost = rec(l, i, b) + rec(i, r, b) + (int)b[r] - (int)b[l];

    // Update index. Notice that we choose lexicographically smallest index
    // if multiple solutions give the same cost.
    if(possibleCost < dp[l][r]) {
      dp[l][r] = possibleCost;
      minCutIndex = i;
    }
  }

  // Store parent of (l, r).
  parent[l][r] = minCutIndex;

  return dp[l][r];
}
 
// Function for building solution.
void buildSolution(int l, int r, vector<int> &b, vector<int> &ans){
  if(l + 1 >= r) return;

  // First choose parent of (l, r).
  ans.push_back(b[parent[l][r]]);

  // Call recursively for two new segments. Calling left segment first
  // because we want lexicographically smallest.
  buildSolution(l, parent[l][r], b, ans);
  buildSolution(parent[l][r], r, b, ans);
}
 
vector<int> solve(int a, vector<int> &b) {
  vector<int> ans;

  // Insert A and 0.
  b.push_back(a);
  b.insert(b.begin(), 0);
  int n = b.size();
  
  // (Re)Initialise dp array.
  dp.resize(n);
  parent.resize(n);
  for (int i = 0; i < n; i++){
    dp[i].resize(n);
    parent[i].resize(n);
    for (int j = 0; j < n; j++) dp[i][j] = -1;
  }
   
  int best = rec(0, n - 1, b);
  buildSolution(0, n - 1, b, ans);

  return ans;
}

// If we just wanted the minimum cost a O(M^2) solution is possible.
// int minCost(int a, vector<int> &b) {
//   int n = b.size() + 1;
//   vector<vector<int>> dp(n, vector<int>(n, 0));

//   vector<int> m = b;
//   m.push_back(a);

//   for (int i = 1; i < n; i++) dp[i][0] = m[i];

//   for (int i = 1; i < n; i++) {
//     for (int j = 1; j < i; j++) {
//       dp[i][j] = min(dp[i][j - 1] + (m[i] - m[j - 1]), m[i] + dp[j][j - 1]);
//     }
//   }

//   return dp[n - 1][n - 2];
// } 

int main() {
  int a = 20;
  vector<int> b = {2, 4, 5, 8, 12, 15, 17};
  
  vector<int> r = solve(a, b);
   
  for(int i = 0; i < r.size(); i++) {
    cout << r[i] << " ";
  }
  cout << endl;

  return 0;
}