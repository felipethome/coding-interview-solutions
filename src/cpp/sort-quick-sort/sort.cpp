/**
 * Quick Sort Algorithm.
 *
 * Time complexity: O(NLogN) average case and O(N^2) worst case, where N is the
 * size of the array to be sorted.
 * Space complexity: O(N) in naive approach, O(logN) Sedgewick 1978.
 *
 * Explanation: the idea is that for each partition we choose a PIVOT and we
 * want to find the final position of this pivot.
 * 
 * So, we want everybody to the left of this position to be smaller than pivot,
 * and everybody to the right to be larger than the pivot. For that we will use
 * the concept of a WALL. We use this wall to find the position of the pivot. At
 * the end we want wall to be the position where the pivot must be placed. So,
 * when the current element is smaller than the pivot we swap current element
 * with the wall and move the wall to the right.
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

void quickSortUtil(vector<int> &a, int left, int right) {
  int wall = left - 1, curr = left, pivot = right;

  if (left < right) {
    for (int curr = left; curr < right; curr++) {
      if (a[curr] <= a[pivot]) {
        wall++;
        swap(a[wall], a[curr]);
      }
    }

    wall++;
    swap(a[wall], a[pivot]);
    
    quickSortUtil(a, left, wall - 1);
    quickSortUtil(a, wall + 1, right);
  }
}

void quickSort(vector<int> &a) {
  quickSortUtil(a, 0, a.size() - 1);
}

int main() {
  vector<int> a = {1, 3, 2, 5, 4, 7, 8, 9, 6};

  quickSort(a);

  cout << endl;
  for (int e : a) cout << e << " ";
  cout << endl;

  return 0;
}