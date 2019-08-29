/**
 * Given an array of integers, return the highest product possible by
 * multiplying 3 numbers from the array.
 *
 * Example:
 * [0, -1, 3, 100, 70, 50] => 70*50*100 = 350000
 *
 * Time complexity: O(NlogN), where N is the size of the array.
 * Space complexity: O(1).
 *
 * Explanation: sort the array in increasing order. Then, you have two possible
 * cases:
 * 1. NEGATIVE * NEGATIVE * POSITIVE, where the largest result possible for
 * the multiplication NEGATIVE * NEGATIVE is of course at the beginning of the
 * array.
 * 2. LARGEST * SECOND_LARGEST * THIRD_LARGEST, where these elements are the
 * largest ones so they are at the end of the array.
 */

#include <iostream>
#include <vector>

using namespace std;

int maxp3(vector<int> &a) {
  sort(a.begin(), a.end());
  
  int n = a.size();

  // Case 1: NEGATIVE * NEGATIVE * POSITIVE
  int p1 = a[0] * a[1] * a[n - 1];
  // Case 2: LARGEST * SECOND_LARGEST * THIRD_LARGEST
  int p2 = a[n - 1] * a[n - 2] * a[n - 3];
  
  return  max(p1, p2);
}

int main() {
  vector<int> a = {0, -1, 3, 100, -70, -50};
  // vector<int> a = {-1, -2, -3, -4, -5};

  int m = maxp3(a);

  cout << "m: " << m << endl;

  return 0;
}