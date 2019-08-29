/**
 * Say you have an array for which the ith element is the price of a given stock
 * on day i. Design an algorithm to find the maximum profit. You may complete
 * at most two transactions.
 * 
 * Note: you may not engage in multiple transactions at the same time (ie,
 * you must sell the stock before you buy again).
 * 
 * Example:
 * Given [1 2 1 2]
 * Output 2
 *
 * Day 1: Buy 
 * Day 2: Sell
 * Day 3: Buy
 * Day 4: Sell
 *
 * Time complexity: O(N), where N is the number of elements in the array.
 * Space complexity: O(N).
 *
 * Explanation: I solved this exercise in a different way from the editorial.
 * I realized that at each day "i" that you are looking at you have a
 * transaction that can happen until this day, and another one that can happen
 * after this day (since you are allowed to make just two transactions). So the
 * brute force way would be to look at each day and check what would be the
 * maximum transaction at its left and at its right. The maximum profit would
 * be max(current, left + right). So we need to speed up this process and for
 * that we calculate an array for all the maximum profits to the left of day
 * "i" in O(N) time. After we calculate an array starting at the end of our
 * input that has the maximum profit at the right of day "i", also in O(N) time.
 * Finally, iterate over these arrays looking for max(current, left + right).
 */

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(const vector<int> &a) {
  if (a.size() <= 1) return 0;

  int ans = 0, bst = INT_MIN, sml = INT_MAX, m = 0;
  int left[a.size()], right[a.size()];

  for (int i = 0; i < a.size(); i++) {
    if (a[i] < sml) sml = a[i];
    else m = max(m, a[i] - sml);
    left[i] = m;
  }

  m = 0;

  for (int i = a.size() - 1; i >= 0; i--) {
    if (a[i] > bst) bst = a[i];
    else m = max(m, bst - a[i]);
    right[i] = m;
  }

  for (int i = 0; i < a.size(); i++) {
    ans = max(ans, left[i] + right[i]);
  }

  return ans;
}

// int maxSingleTransactionProfit(const vector<int> &a, int s, int e) {
//   if (a.size() <= 1) return 0;

//   int sml = a[s], mp = 0;

//   for (int i = s; i < e; i++) {
//     if (a[i] < sml) {
//       sml = a[i];
//     }
//     else {
//       mp = max(mp, a[i] - sml);
//     }
//   }

//   return mp;
// }

// int maxProfit(const vector<int> &a) {
//   if (a.size() <= 1) return 0;

//   int ans = 0;

//   for (int i = 0; i < a.size(); i++) {
//     int l = maxSingleTransactionProfit(a, i, a.size());
//     int r = maxSingleTransactionProfit(a, 0, i + 1);
//     ans = max(ans, l + r);
//   }

//   return ans;
// }

int main() {
  // vector<int> a = {1, 2}; // 1
  // vector<int> a = {1, 2, 3}; // 2
  vector<int> a = {1, 2, 3, 2, 5, 1, 7, 4, 7, 5, 10, 13, 2, 5, 45, 2}; // 55
  // vector<int> a = {8, 10, 1, 3, 30, 2, 50}; // 77

  int mp = maxProfit(a);

  cout << "max profit: " << mp << endl;

  return 0;
}