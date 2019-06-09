/**
 * Given a read only array of n + 1 integers between 1 and n, find one number
 * that repeats in linear time using less than O(n) space and traversing the
 * stream sequentially O(1) times.
 *
 * Example:
 * Given [3 4 1 4 1]
 * Return 1
 * 
 * If there are multiple possible answers (like in the sample case above),
 * output any one.
 * If there is no duplicate, output -1
 *
 * Time complexity: O(N), where N is the size of the array.
 * Space complexity: O(1).
 *
 * Explanation: Floyd Cycle Algorithm. Since the size of the array is N + 1 and
 * the numbers in the array are between 1 .. N, we can treat the array
 * as a graph where each node is one if the indices of the array and the edges
 * are given by the values in each one of these indices. Now, when there is
 * a repeated number there will be two edges of our graph arriving at a
 * node/indice. In other words there will be a cycle in our graph. So if we
 * apply the Floyd Cycle Algorithm we can find the starting node of the cycle
 * and this starting node is one of the repeated number in the array.
 */

#include <iostream>
#include <vector>

using namespace std;

int repeatedNumber(const vector<int> &a) {
  if (a.size() <= 1) return -1;

  int n = a.size(), count = 0, turt = 0, hare = 0, i = 0;

  do {
    turt = a[turt];
    hare = a[a[hare]];
    count++;
  }
  while (turt != hare && count < n);

  if (count < n) {
    while (i != turt) {
      turt = a[turt];
      i = a[i];
    }

    return i;
  }

  return -1;
}

int main() {
  // vector<int> a = {1, 1};
  // vector<int> a = {3, 4, 1, 4, 1};
  // vector<int> a = {1, 2, 3, 2, 4};
  // vector<int> a = {1, 2, 3, 1, 4};
  // vector<int> a = {1, 2, 3, 4, 4};
  vector<int> a = {3, 4, 5, 5, 4, 6, 3};

  int r = repeatedNumber(a);

  cout << "duplicate: " << r << endl;

  return 0;
}