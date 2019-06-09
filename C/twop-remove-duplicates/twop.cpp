/**
 * Given a sorted array, remove the duplicates in place such that each element
 * appears only once and return the new length. Note that even though we want
 * you to return the new length, make sure to change the original array as well
 * in place.
 * Do not allocate extra space for another array, you must do this in place
 * with constant memory.
 * 
 * Example: 
 * Given input array A = [1,1,2],
 * Your function should return length = 2, and A is now [1,2].
 *
 * Time complexity: O(N^2 / M), where N is the size of the array and M is the
 * average number of duplicates.
 * Space complexity: O(1).
 * Obs: the erase() function has time complexity Linear on the number of
 * elements erased (destructions) plus the number of elements after the last
 * element deleted (moving).
 *
 * Explanation: use two pointers. Iterate from the end of the array (most of
 * the times when you are willing to delete elements from an array you should
 * start at the end). Use a variable to keep track of the number of duplicates.
 * While you are finding elements that are equal to its predecessor increment
 * your count, otherwise delete all elements from i + 1 (since i is the index
 * of the element that is different from the others) to i + 1 + count, and
 * restart your count making it 0.
 */

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &a) {
  int i, j = 0;

  for (i = a.size() - 2; i >= 0; i--) {
    if (a[i] == a[i + 1]) j++;
    else {
      if (j) a.erase(a.begin() + i + 1, a.begin() + i + 1 + j);
      j = 0;
    }
  }

  if (j) a.erase(a.begin() + i + 1, a.begin() + i + 1 + j);

  return a.size();
}

int main() {
  // vector<int> a = {1, 1, 2, 2, 2, 3};
  vector<int> a = {1, 1, 2, 2, 2, 3, 4, 4, 4, 4, 5, 6, 8, 9, 9, 9};

  cout << "Before (" << a.size() << "): ";
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  int r = removeDuplicates(a);

  cout << "After (" << r << "): ";
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  return 0;
}