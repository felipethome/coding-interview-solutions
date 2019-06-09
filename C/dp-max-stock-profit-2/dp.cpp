/**
 * Say you have an array for which the ith element is the price of a given stock
 * on day i.
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times). However, you may not engage in multiple transactions at
 * the same time (ie, you must sell the stock before you buy again).
 *
 * Example:
 * Given [1 2]
 * Return 1
 *
 * Time complexity: O(N), where N is the number of elements in the array.
 * Space complexity: O(1).
 *
 * Explanation: we start at the last index and start to look for the element
 * that has a neighbor that is smaller than it. For example, consider the array
 * [4, 1, 3, 2]. In this array we would find the element 3 because it is the
 * largest element from the end of the array that we could get until we find
 * an element that is smaller (in this case, element 1). Now, we continue our
 * loop until we find an element where its left neightbor is larger than it. So,
 * in our example we would find 1, because it is smaller than 4. Now, we add the
 * difference 3 - 1 to our answer. We continue the process until the loop is
 * finished.
 *
 * I will try to explain better the process described above. Look at:
 * [1, 3, 2, 10]
 * The answer here is (10 - 2) + (3 - 1) = 10, because it is better than
 * 10 - 1 = 9. The process described above works because we are looking for
 * big elements that can give us profit, so we first select 10 because we know
 * that its left neighbor is smaller than it so we can get profit using 10,
 * then when we find an element like 2 that has a neighbor 3 that is bigger than
 * it, is when we can complete the transaction to get our profit. We can do this
 * because even if we could have more profit looking for a smaller element
 * than 2 we can recover and even get more money using our 3 element (think
 * about it, if you would get more money using 10 would be with a number smaller
 * than 2 like 1, so you would get 1 unit more of profit, but if you complete
 * the transation at 2 and use 3 for a new transaction you have 2 units more
 * than 1).
 *
 * The official answer for this problem, kinda use the fact I descibed above,
 * but in a more simple way:
 * Note 1: I will never buy a stock and sell it in loss.
 * Note 2: If A[i] < A[i+1], I will always buy a stock on i and sell it on i+1. 
 *
 * int maxProfit(vector<int> &prices) {
 *   int total = 0, sz = prices.size();
 *   for (int i = 0; i < sz - 1; i++) {
 *     if (prices[i+1] > prices[i]) total += prices[i+1] - prices[i];
 *   }
 *   return total;
 * }
 */

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(const vector<int> &a) {
  if (a.size() <= 1) return 0;

  int bst = -1, mp = 0;

  for (int i = a.size() - 1; i >= 0; i--) {
    if (a[i] >= bst) {
      bst = a[i];
    }
    else {
      if (i == 0 || (i > 0 && a[i - 1] >= a[i])) {
        mp = mp + (bst - a[i]);
        bst = -1;
      }
    }
  }

  return mp;
}

int main() {
  // vector<int> a = {1, 2, 3};
  // vector<int> a = {1, 5, 2, 10};
  // vector<int> a = {1, 5, 6, 10};
  // vector<int> a = {6, 5, 4, 10};
  vector<int> a = {1, 2, 3, 1, 5, 3, 7, 4, 7, 5, 10, 13, 2, 20, 45, 2};

  int mp = maxProfit(a);

  cout << "max profit: " << mp << endl;

  return 0;
}