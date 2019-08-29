/**
 * Insertition Sort Algorithm.
 *
 * Time complexity: O(N^2), where N is the size of the array to be sorted.
 * Space complexity: O(1).
 *
 * Explanation: the idea is to divide the array into two parts: a sorted part,
 * and a unsorted part. We want to move elements one by one from the unsorted
 * part to the sorted part.
 * 
 * So, for each i from 1 .. N - 1 we iterate from i to 0 (we start from the
 * second element, index 1, because the 0 element is already sorted since it is
 * just one element). When iterating from i..0 we are looking for a place to
 * move the first element from the unsorted part to the sorted part.
 */

#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &a) {
  for (int i = 1; i < a.size(); i++) {
    int element = a[i], j = i;

    // Move elements one by one to the right until we find the new position
    // for "element".
    while (j > 0 && a[j - 1] > element) {
      a[j] = a[j - 1];
      j--;
    }

    a[j] = element;
  }
}

int main() {
  vector<int> a = {1, 3, 2, 5, 4, 7, 8, 9, 6};

  insertionSort(a);

  cout << endl;
  for (int e : a) cout << e << " ";
  cout << endl;

  return 0;
}