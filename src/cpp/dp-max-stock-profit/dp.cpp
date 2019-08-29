/**
 * Say you have an array for which the ith element is the price of a given stock
 * on day i.
 * If you were only permitted to complete at most one transaction (ie, buy one
 * and sell one share of the stock), design an algorithm to find the maximum
 * profit.
 *
 * Example:
 * Given [1 2]
 * Return 1
 *
 * Time complexity: O(N), where N is the number of elements in the array.
 * Space complexity: O(1).
 *
 * Explanation: we want max(a[j] - a[i]), where j is bigger than i. The maximum
 * profit will be the biggest value - smallest value. So, we can initialize a
 * variable (call it "smallest") with the first element and we update the value
 * every time we find an a[i] smaller than this variable. When the element is
 * not smaller than this variable we store in another variable:
 * maxProfit = max(maxProfit, a[i] - smallest).
 */

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &a) {
  if (a.size() <= 1) return 0;

  int sml = a[0], mp = 0;

  for (int i = 0; i < a.size(); i++) {
    if (a[i] < sml) {
      sml = a[i];
    }
    else {
      mp = max(mp, a[i] - sml);
    }
  }

  return mp;
}

int main() {
  vector<int> a = {1, 2};

  int mp = maxProfit(a);

  cout << "max profit: " << mp << endl;

  return 0;
}