/**
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * Example:
 * Given [1,2,0] return 3,
 * Given [3,4,-1,1] return 2,
 * Given [-8, -7, -6] returns 1
 * 
 * Your algorithm should run in O(N) time and use constant space.
 *
 * Time complexity: O(N), where N is the number of elements in the array.
 * Space complexity: O(N).
 *
 * Explanation: since the exercise ask us to use O(1) space we don't have
 * another choice besides modifying the given array. We also need to sort the
 * array (there is no other way), but the exercise asks for O(N) complexity so
 * we need to take advatange of some condition to be able to find a O(N) sort
 * algorithm. Remember we are looking for the first missing integer, so we can
 * use our array indexation to organize the integers we find in their respective
 * buckets. For example, we want number 1 at index 0, number 2 at index 1,
 * number 3 at index 2 and so on. When we find a number that can't be placed
 * in some place at the array using it index, like 0 or any number bigger than
 * the array size, we just live it there. Eventually this numbers will be
 * replaced by some number that should be in that bucket and these number will
 * end up in the end of the array. Look at:
 * before [4 2 1], after [1 2 4]
 * After this process we just need to look for the first integer that is not
 * the same as index + 1. In the above case would be 4 (the correct number at
 * that bucket would be 3), so we return the index + 1, which is 3.
 */

#include <iostream>
#include <vector>

using namespace std;

int firstMissingPositive(vector<int> &a) {
  if (a.size() == 0) return 1;

  for (int i = 0; i < a.size(); i++) {
    while (a[i] > 0 && a[i] <= a.size() && a[i] != i + 1 && a[a[i] - 1] != a[i]) {
      swap(a[i], a[a[i] - 1]);
    }
  }

  for (int i = 0; i < a.size(); i++) {
    if (a[i] != i + 1) return i + 1;
  }

  return a.size() + 1;
}

int main() {
  // vector<int> a = {1};
  // vector<int> a = {1, 2, 0};
  // vector<int> a = {3, 4, -1, 1};
  // vector<int> a = {-8, -7, -6};
  // vector<int> a = {3, 4, -1, -2, 5, 0, 1, 2};
  // vector<int> a = {5, 7, 8, 2, 1, 3, 6};
  vector<int> a = {5, 0, 0, 7, 8, -1, 2, 1, 3, -5, 6, -7, 1};

  int r = firstMissingPositive(a);

  cout << "Answer: " << r << endl;

  return 0;
}