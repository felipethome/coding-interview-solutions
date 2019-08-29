/*
 * Find the intersection of two sorted arrays. Assume that elements that appear
 * more than once must be included more than once.
 * 
 * Example:
 * Input : A : [1 2 3 3 4 5 6] B : [3 3 5]
 * Output : [3 3 5]
 *
 * Time complexity: O(N), where N is the biggest length between the two arrays.
 *
 * Explanation: keep two pointers, one at the beginning of the first array, call
 * it i, and other one at the beginning the the second array, call it j. When
 * a[i] < b[j], increment i, when b[j] < a[i] increment j, else (they are equal)
 * push the element into a result array.
 */

#include <iostream>
#include <vector>

vector<int> intersect(const vector<int> &a, const vector<int> &b) {
  vector<int> r;
  int len_a =  a.size();
  int len_b = b.size();
  int i = 0, j = 0;
  
  while (i < len_a && j < len_b) {
    if (a[i] < b[j]) i++;
    else if (b[j] < a[i]) j++;
    else {
      r.push_back(a[i]);
      i++;
      j++;
    }
  }
  
  return r;
}

int main() {
  vector<int> v1 = { 1, 2, 3, 3, 4, 5, 6 };
  vector<int> v2 = { 3, 3, 5 };
  vector<int> r = intersect(v1, v2);

  for (int i = 0; i < r.size(); i++) {
    cout << r[i] << ' ';
  }

  return 0;
}