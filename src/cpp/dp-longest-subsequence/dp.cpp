/**
 * Find the longest increasing subsequence of a given sequence / array.
 * 
 * In other words, find a subsequence of array in which the subsequence’s
 * elements are in strictly increasing order, and in which the subsequence is
 * as long as possible. This subsequence is not necessarily contiguous, or
 * unique. In this case, we only care about the length of the longest increasing
 * subsequence.
 *
 * Time complexity: O(N), where N is the number of elements in the array.
 * Space complexity: O(N).
 *
 * Explanation: start at the end of the array. The last element is our base
 * case and has subsequence size of 1. The element next to it will have
 * subsequence size 1 or 2, 2 if it is smaller than the last element. We,
 * continue this process and at each element we are we can not just check the
 * element at its right, but all the elements to its right to the end of the
 * array. For that particular element the longest subsequence will be 1 plus
 * the largest size already calculated for elements at its right that are bigger
 * than it.
 */

#include <iostream>
#include <vector>

using namespace std;

int lis(const vector<int> &a) {
  if (a.size() == 0) return 0;

  int m = 1;
  vector<int> ans(a.size(), 0);
  ans[ans.size() - 1] = 1;

  for (int i = a.size() - 2; i >= 0; i--) {
    int t = 1;
    for (int j = i + 1; j < ans.size(); j++) {
      if (a[j] > a[i]) t = max(t, ans[j] + 1);
    }
    ans[i] = t;
    m = max(m, t);
  }

  return m;
}

int main() {
  // vector<int> a = {8};
  // vector<int> a = {8, 0};
  // vector<int> a = {0, 8};
  // vector<int> a = {0, 8, 4, 12, 2, 10};
  vector<int> a = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

  int m = lis(a);

  cout << "max: " << m << endl;

  return 0;
}