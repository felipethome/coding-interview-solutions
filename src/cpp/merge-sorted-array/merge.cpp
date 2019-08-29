/*
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 * You must modify array A to be the result.
 *
 * Example:
 * Input : A : [1 5 8] B : [6 9]
 * Modified A : [1 5 6 8 9]
 *
 * Time complexity: O(N), where N is the length of array B.
 * Explanation: keep two pointers, one at the beginning of the first array, call
 * it i, another one at the beginning of the second array, call it j. Iterate
 * through the second array with j, if a[i] < b[j] increment i, else (greater
 * or equal) insert the element b[j] at position i and then increment i and j.
 */

#include <iostream>
#include <vector>

void merge(vector<int> &a, vector<int> &b) {
  int i = 0, j = 0;
  
  while (j < b.size()) {
    if (a[i] < b[j] && i < a.size()) i++;
    else {
      a.insert(a.begin() + i, b[j]);
      i++;
      j++;
    }
  }
}

int main() {
  vector<int> v1 = { 1, 2, 3, 3, 4, 5, 6 };
  vector<int> v2 = { 3, 3, 5 };
  merge(v1, v2);

  for (int i = 0; i < v1.size(); i++) {
    cout << v1[i] << ' ';
  }

  return 0;
}